#include "Entity.h"

sls::Entity::Entity()
{
    this->stomachMax = rand() % 22 + 100;
    this->stomach = this->stomachMax;

    this->blob.setFillColor(sf::Color::Blue);
    this->blob.setRadius(7.5f);
    
    this->fov.setPointCount(3);
    this->fov.setRadius(15.f);
}

sls::Entity::~Entity()
{
    
}