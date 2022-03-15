#ifndef FOOD_H
#define FOOD_H

#include "Includes.h"

namespace sls {

enum class FoodSize{SMALL=0, MEDIUM, BIG};
enum class FoodState{IDLE=0, HELD, EATEN};

// Will eventually add decay
class Food
{
protected:
	float x;
	float y;
	bool del;
	FoodSize size;
	FoodState state;
	double fullness;
	sf::CircleShape food;

	void initSize();
	void initShape();
public:
	Food();
	virtual ~Food();

	const FoodSize& getSize() const;
	const FoodState& getState() const;
	const double& getFullness() const;
	const sf::CircleShape& getShape() const;

	void setHeld();
	void setEaten();

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

};

#endif
