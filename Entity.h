#ifndef ENTITY_H
#define ENTITY_H

#include "Includes.h"

namespace sls
{

enum class EntityState{IDLE=0, SEARCHINGFOOD, SEARCHINGSHELTER};
enum class EntityHungerState{FULL, SATISFIED, HUNGRY, STARVING};

class Entity
{
private:
    double stomach;
    double stomachMax;
    sf::CircleShape blob;
    sf::CircleShape fov;
public:
    Entity();
    virtual ~Entity();

    void updateState();
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};

};
#endif