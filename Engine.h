#ifndef ENGINE_H
#define ENGINE_H

#include "Includes.h"

class Engine
{
private:
    float dt;
    sf::Clock dtClock;

    sf::Event event;
    sf::RenderWindow* window;

    void initWindow();
public:
    Engine();
    virtual ~Engine();

    void updateDeltaTime();
    void updateEvents();
    void update();

    void render();

    void core();
};

#endif