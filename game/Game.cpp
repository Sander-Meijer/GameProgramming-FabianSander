#include <cassert>
#include "../engine/globals/Time.hpp"
#include "../engine/globals/FPS.hpp"

#include "../engine/renderers/Renderer.hpp"
#include "../engine/light/ShaderProgram.hpp"
#include "Game.hpp"
#include "../engine/World.hpp"
#include "../engine/camera/Camera.hpp"
#include "../engine/light/Light.hpp"
#include "../engine/object/Mesh.hpp"
#include "../engine/object/Texture.hpp"

#include "../engine/behaviours/WASDBehaviour.hpp"

#include "../engine/colliders/Collider.hpp"
#include "../engine/globals/Updater.h"


#include "../engine/Hud/Hud.hpp"
#include "../engine/builders/LevelBuilder.h"
#include "../engine/colliders/CollisionDetector.h"

Game::Game() :
		window(NULL), hud(NULL), renderer(NULL), world(NULL), camera(NULL), light(NULL) {
	window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Game_Sander_Fabian"); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	Hud::getInstance()->setWindow(window);
	renderer = new Renderer(window);
	running = false;
}

Game::~Game() {
	//dtor
}

void Game::build() {
	renderer->use(new ShaderProgram("assets/shaders/default.vs", "assets/shaders/default.fs"));
	world = LevelBuilder::getInstance()->loadFile("assets/scenes/RPG_World.awesome");
}


void Game::run() {
	running = true;
	while (running) {
		Time::getInstance()->update();
		control();
		if (running) { // control may have changed running;
			update();
			draw();
			FPS::getInstance()->update();
		}
	}
}

void Game::stop() {
}

// private functions

void Game::control() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
			running = false; // running = false;
		}
	}
}

void Game::update() {
	assert( world != NULL);
	world->accept(Updater::getInstance());
	CollisionDetector::getInstance()->checkCollisions(world);
}

void Game::draw() {
	assert( window != NULL);
	assert( renderer != NULL);
	assert( world != NULL);

	renderer->setTime(Time::getInstance()->now());
	renderer->draw(world);

}
