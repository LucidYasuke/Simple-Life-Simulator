#include "Engine.h"

void Engine::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Simple-Life-Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Engine::initBackground()
{
    this->background.insert({"TOP", sf::RectangleShape(sf::Vector2f(1280.f, 75.f)) });
    this->background.insert({"BOTTOM", sf::RectangleShape(sf::Vector2f(1280.f, 75.f)) });
    this->background.insert({"LEFT", sf::RectangleShape(sf::Vector2f(75.f, 720.f)) });
    this->background.insert({"RIGHT", sf::RectangleShape(sf::Vector2f(75.f, 720.f)) });
    this->background.insert({ "MIDDLE", sf::RectangleShape(sf::Vector2f(1130.f, 570.f)) });

    this->background["TOP"].setFillColor(sf::Color(120, 115, 102));
    this->background["BOTTOM"].setFillColor(sf::Color(120, 115, 102));
    this->background["LEFT"].setFillColor(sf::Color(120, 115, 102));
    this->background["RIGHT"].setFillColor(sf::Color(120, 115, 102));
    this->background["MIDDLE"].setFillColor(sf::Color(124, 94, 66));

    this->background["TOP"].setPosition(sf::Vector2f(0.f, 0.f));
    this->background["BOTTOM"].setPosition(sf::Vector2f(0.f, 645.f));
    this->background["LEFT"].setPosition(sf::Vector2f(0.f, 0.f));
    this->background["RIGHT"].setPosition(sf::Vector2f(1205.f, 0.f));
    this->background["MIDDLE"].setPosition(sf::Vector2f(75.f, 75.f));
}

Engine::Engine()
{
    this->timerFruitSpawn = sf::seconds(10.f);
    this->timerFruitSpawnMax = sf::seconds(0.f);
    this->initWindow();
    this->initBackground();
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
    if(this->foods.size() < 50)
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

    this->window->draw(this->background["TOP"]);
    this->window->draw(this->background["BOTTOM"]);
    this->window->draw(this->background["LEFT"]);
    this->window->draw(this->background["RIGHT"]);
    this->window->draw(this->background["MIDDLE"]);


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