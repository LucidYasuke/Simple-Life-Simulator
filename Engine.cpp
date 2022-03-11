#include "Engine.h"

void Engine::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Simple-Life-Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

Engine::Engine()
{
    this->initWindow();
}

Engine::~Engine()
{
    delete this->window;
}

void Engine::updateDeltaTime()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Engine::updateEvents()
{
    while (window->pollEvent(this->event))
    {
       if (event.type == sf::Event::Closed)
       {
           window->close();
       }
    } 
}

void Engine::update()
{
    this->updateEvents();
}

void Engine::render()
{
    this->window->clear();

    this->window->display();
}

void Engine::core()
{
    while (this->window->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }   
}