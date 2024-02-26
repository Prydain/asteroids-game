/*************************************************************
 * File: rocks.cpp
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/

#include "ship.h"
#include "uiDraw.h"
#include "flyingObject.h"

/*************************************************************
 * Function: ship(point, velocity) 
 * Description: Non-default constructor
 *************************************************************/
Ship::Ship()
{
   rotation = ANGLE_START;
   thrust = false;
}

/*************************************************************
 * Function: draw()
 * Description: 
 *************************************************************/
void Ship::draw() 
{ 
   drawShip(getPoint(), rotation, thrust); 
}

/*************************************************************
 * Function: hit()
 * Description: call kill() function
 *************************************************************/
void Ship::hit()
{
   kill();
}

/*************************************************************
 * Function: thurst()
 * Description:
 *************************************************************/
void Ship::applyThrust()
{
   Velocity velocity = getVelocity();
   
   velocity.setDx(velocity.getDx() + THRUST_AMOUNT * (-sin(M_PI / 180.0 * rotation)));
   velocity.setDy(velocity.getDy() + THRUST_AMOUNT * (cos(M_PI / 180.0 * rotation)));

   setVelocity(velocity);
}

/*************************************************************
 * Function: shipRotation()
 * Description:
 *************************************************************/
void Ship::applyRotationLeft()
{
   rotation += SHIP_ROTATION;
}

/*************************************************************
 * Function: shipRotation()
 * Description:
 *************************************************************/
void Ship::applyRotationRight()
{
   rotation -= SHIP_ROTATION;
}

/*************************************************************
 * Function: canThrust()
 * Description:
 *************************************************************/
void Ship::isThrust()
{
   thrust = true;
}

/*************************************************************
 * Function: canThrust()
 * Description:
 *************************************************************/
void Ship::isNotThrust()
{
   thrust = false;
}