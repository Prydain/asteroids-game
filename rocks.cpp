/*************************************************************
 * File: rocks.cpp
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/
#include "rocks.h"

#include "random.h"

#include <utility>

template<class... RockTypes, class... Args>
std::vector<std::unique_ptr<Rock>> rock_factory(Args&&... args) {
    std::vector<std::unique_ptr<Rock>> retval;
    retval.reserve(sizeof...(RockTypes));

    (retval.emplace_back(std::make_unique<RockTypes>(args...)), ...);
    for(auto& rock : retval) {
        rock->setVelocity(rock->getVelocity().nudge());
    }

    return retval;
}

// Rock constructor
Rock::Rock(Point point, Velocity velocity) : FlyingObject(point, velocity) {}

// Big Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
BigRock::BigRock(Point point, Velocity velocity) : Rock(point, velocity)
{
   rotation = BIG_ROCK_SPIN;
}

/*************************************************************
 * Function: draw()
 * Description: calls drawLargeAsteroid from uiDraw
 * add BIG_ROCK_SPIN to rotation everytime the game loops draws asteroid
 *************************************************************/
void BigRock::draw() 
{ 
   drawLargeAsteroid(getPoint(), rotation); 
   rotation += BIG_ROCK_SPIN; 
}

/*************************************************************
 * Function: hit()
 * Description: call kill() function
 *************************************************************/
void BigRock::hit()
{
   kill();
}

std::vector<std::unique_ptr<Rock>> BigRock::splitRock() const {
    return rock_factory<MediumRock, MediumRock, SmallRock>(getPoint(), getVelocity());
}

// Medium Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
MediumRock::MediumRock(Point point, Velocity velocity) : Rock(point, velocity)
{
   rotation = MEDIUM_ROCK_SPIN;
}

/*************************************************************
 * Function: draw()
 * Description: calls drawLargeAsteroid from uiDraw
 * add BIG_ROCK_SPIN to rotation everytime the game loops draws asteroid
 *************************************************************/
void MediumRock::draw() 
{ 
   drawMediumAsteroid(getPoint(), rotation); 
   rotation += MEDIUM_ROCK_SPIN; 
}

/*************************************************************
 * Function: hit()
 * Description: call kill() function
 *************************************************************/
void MediumRock::hit()
{
   kill();
}

std::vector<std::unique_ptr<Rock>> MediumRock::splitRock() const {
    return rock_factory<SmallRock, SmallRock, SmallRock>(getPoint(), getVelocity());
}

// Small Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
SmallRock::SmallRock(Point point, Velocity velocity) : Rock(point, velocity)
{
   rotation = SMALL_ROCK_SPIN;
}

/*************************************************************
 * Function: draw()
 * Description: calls drawLargeAsteroid from uiDraw
 * add BIG_ROCK_SPIN to rotation everytime the game loops draws asteroid
 *************************************************************/
void SmallRock::draw() 
{ 
   drawSmallAsteroid(getPoint(), rotation); 
   rotation += SMALL_ROCK_SPIN; 
}

/*************************************************************
 * Function: hit()
 * Description: call kill() function
 *************************************************************/
void SmallRock::hit()
{
   kill();
}

std::vector<std::unique_ptr<Rock>> SmallRock::splitRock() const {
    return {};
}
