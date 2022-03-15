#ifndef ENTITY_H
#define ENTITY_H

#include "Includes.h"

namespace sls
{

enum class EntityTravelState{IDLE=0, SEARCHINGFOOD, SEARCHINGSHELTER};
enum class EntityHungerState{FULL, SATISFIED, HUNGRY, STARVING};

class Entity
{
private:
    bool sheltered;
    double stomach;
    double stomachMax;
    EntityTravelState travelState;
    EntityHungerState hungerState;
    sf::CircleShape blob;
    sf::CircleShape fov;
public:
    Entity();
    virtual ~Entity();

    void searchFood();
    void updateState();
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};

};
#endif