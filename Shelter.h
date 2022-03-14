#ifndef SHELTER_H
#define SHELTER_H

#include "Includes.h"

namespace sls{

class Entity;

enum class ShelterState {EMPTY = 0, HALF, FULL};

class Shelter
{
private:
    ShelterState state;
    int capacity;
    Entity* shelter[];
public:
    Shelter();
    virtual ~Shelter();

    const ShelterState& getState() const;
    void update();
    void render(sf::RenderTarget* target);
};

};


#endif