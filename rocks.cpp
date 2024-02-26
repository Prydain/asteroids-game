/*************************************************************
 * File: rocks.cpp
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/
#include "rocks.h"

// Big Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
BigRock::BigRock(Point point, Velocity velocity)
{
   setPoint(point);
   setVelocity(velocity);
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

// Medium Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
MediumRock::MediumRock(Point point, Velocity velocity)
{
   setPoint(point);
   setVelocity(velocity);
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

// Small Rock
/*************************************************************
 * Function: BigRock(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
SmallRock::SmallRock(Point point, Velocity velocity)
{
   setPoint(point);
   setVelocity(velocity);
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