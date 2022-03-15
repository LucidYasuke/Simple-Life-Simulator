#ifndef ENGINE_H
#define ENGINE_H

#include "Food.h"
#include "Entity.h"
#include "Shelter.h"

class Engine
{
private:
    float dt;
    sf::Clock dtClock;
    std::map<std::string, sf::RectangleShape> background;

    sf::Time timerFruitSpawn, timerFruitSpawnMax;

    sf::Event event;
    sf::RenderWindow* window;

    std::vector<sls::Food*> foods;

    void initWindow();
    void initBackground();
public:
    Engine();
    virtual ~Engine();

    void updateDeltaTime();
    void updateTimers();
    void updateEvents();
    void updateFood();
    void update();

    void render();

    void core();
};

#endif