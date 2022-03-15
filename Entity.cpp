#include "Entity.h"

sls::Entity::Entity()
{
    this->sheltered = false;

    this->stomachMax = rand() % 22 + 100.0;
    this->stomach = this->stomachMax;

    this->blob.setFillColor(sf::Color::Blue);
    this->blob.setRadius(15.5f);
    
    this->fov.setPointCount(3);
    this->fov.setRadius(30.f);

    this->travelState = sls::EntityTravelState::IDLE;
    this->hungerState = sls::EntityHungerState::FULL;
}

sls::Entity::~Entity()
{
    
}

void sls::Entity::searchFood()
{

}


void sls::Entity::updateState()
{
    if (this->stomach >= this->stomachMax){ this->hungerState = sls::EntityHungerState::FULL; }
    else if (this->stomach >= this->stomachMax * .75) { this->hungerState = sls::EntityHungerState::SATISFIED; }
    else if (this->stomach >= this->stomachMax * .50) { this->hungerState = sls::EntityHungerState::HUNGRY; }
    else  { this->hungerState = sls::EntityHungerState::STARVING; }

    switch (this->hungerState)
    {
    case sls::EntityHungerState::FULL:
    case sls::EntityHungerState::SATISFIED:
        if (this->sheltered) { this->travelState = sls::EntityTravelState::IDLE; }
        else { this->travelState = sls::EntityTravelState::SEARCHINGSHELTER; }
        break;
    case sls::EntityHungerState::HUNGRY:
    case sls::EntityHungerState::STARVING:
        this->travelState = sls::EntityTravelState::SEARCHINGFOOD;
        break;
    }
}

void sls::Entity::update(const float& dt)
{
}

void sls::Entity::render(sf::RenderTarget* target)
{
}
