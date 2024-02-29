/*************************************************************
 * File: flyingObject
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"


/*************************************************************
 * Function: setPoint(point)
 * Description: set point
 *************************************************************/
void FlyingObject::setPoint(Point point)
{
   this->point = point;
}

 /*************************************************************
 * Function: setVelocity(velocity)
 * Description: set velocity
 *************************************************************/
void FlyingObject::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

/*************************************************************
 * Function: kill()
 * Description: set alive to false
 *************************************************************/
void FlyingObject::kill()
{
   alive = false;
}

/*************************************************************
 * Function: advance()
 * Description: move flyingObject across the screen
 *************************************************************/
void FlyingObject::advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}

/**************************************************************************
 * GAME :: screenWrap()
 * 
 **************************************************************************/
void FlyingObject::screenWrap()
{
   Point newPoint = point;

   if (newPoint.getX() > 205 || newPoint.getX() < -205)
   {
      newPoint.setX(-newPoint.getX());
   }

   if (newPoint.getY() > 205 || newPoint.getY() < -205)
   {
      newPoint.setY(-newPoint.getY());
   }
   point = newPoint;
}

/*************************************************************
 * Function: isAlive()
 * Description: return alive
 *************************************************************/
bool FlyingObject::isAlive() const
{
   return alive;
}
