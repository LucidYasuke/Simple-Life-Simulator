#include "Food.h"

void sls::Food::initSize()
{
	int sizeSelection = rand() % 1000; // Min 0 Max 999
	double numOne = static_cast<double>(rand() % 10) / 10.0; // Random Tenth Place Decimal
	double numTwo = static_cast<double>(rand() % 10) / 100.0; // Random Hundreth Place Decimal

	if (sizeSelection < 550) { this->size = sls::FoodSize::SMALL; }
	else if (sizeSelection < 800) { this->size = sls::FoodSize::MEDIUM; }
	else { this->size = sls::FoodSize::BIG; }

	switch (this->size)
	{
	case sls::FoodSize::SMALL:
		this->fullness = rand() % 11 + 5; // Min 5 Max 15
		break;
	case sls::FoodSize::MEDIUM:
		this->fullness = rand() % 9 + 17; // Min 17 Max 25
		break;
	case sls::FoodSize::BIG:
		this->fullness = rand() % 15 + 28; // Min 28 Max 42
		break;
	}

	this->fullness += numOne + numTwo;
}

void sls::Food::initShape()
{
	this->food.setFillColor(sf::Color::Green);

	switch (this->size)
	{
	case sls::FoodSize::SMALL:
		this->food.setRadius(1.5f);
		break;
	case sls::FoodSize::MEDIUM:
		this->food.setRadius(3.f);
		break;
	case sls::FoodSize::BIG:
		this->food.setRadius(4.5f);
		break;
	}

	// 1280 by 720
	//start 200 to 1080
	// start 200 to 520
	this->x = static_cast<float>(rand() % 880 + 200);
	this->y = static_cast<float>(rand() % 320 + 200);

	this->food.setPosition(sf::Vector2f(this->x, this->y));
}

sls::Food::Food()
{
	this->state = sls::FoodState::IDLE;
	this->del = false;
	this->initSize();
	this->initShape();
}

sls::Food::~Food()
{
}

const sls::FoodSize& sls::Food::getSize() const
{
	return this->size;
}

const sls::FoodState& sls::Food::getState() const
{
	return this->state;
}

const double& sls::Food::getFullness() const
{
	return this->fullness;
}

const sf::CircleShape& sls::Food::getShape() const
{
	return this->food;
}

void sls::Food::setHeld()
{
	this->state = sls::FoodState::HELD;
}

void sls::Food::setEaten()
{
	this->state = sls::FoodState::EATEN;
}

void sls::Food::update(const float& dt)
{
	switch (this->state)
	{
	case sls::FoodState::IDLE:
		break;
	case sls::FoodState::EATEN:
		this->del = true;
		break;
	default:
		break;
	}
}

void sls::Food::render(sf::RenderTarget* target)
{
	if (this->state == sls::FoodState::IDLE)
	{
		target->draw(this->food);
	}
}
