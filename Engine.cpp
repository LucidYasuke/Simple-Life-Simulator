#include "Engine.h"

void Engine::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Simple-Life-Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

Engine::Engine()
{
    this->timerFruitSpawn = sf::seconds(10.f);
    this->timerFruitSpawnMax = sf::seconds(10.f);
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

void Engine::updateTimers()
{
    this->timerFruitSpawn += sf::seconds(this->dt);
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

void Engine::updateFood()
{   
    if(this->foods.size() < 25)
    {
        if (this->timerFruitSpawn >= this->timerFruitSpawnMax)
        {
            this->foods.push_back(new sls::Food());
            this->timerFruitSpawn = sf::seconds(0.f);
        }
    }

    for (int i = 0; i < this->foods.size(); i++)
    {
        this->foods[i]->update(this->dt);
    }
}

void Engine::update()
{
    this->updateTimers();
    this->updateEvents();
    this->updateFood();
}

void Engine::render()
{
    this->window->clear();

    for (int i = 0; i < this->foods.size(); i++)
    {
        this->foods[i]->render(this->window);
    }

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