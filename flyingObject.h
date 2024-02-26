/*************************************************************
 * File: flyingObject
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/
#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "flyingObject.h"

/*************************************************************
 * Class: FlyingObject
 * Description: Base class for Bullet and Bird classes.
 *************************************************************/
class FlyingObject
{
private:
   Point point;
   Velocity velocity;
   bool alive;

public:
   FlyingObject() : point(0, 0), velocity(0, 0), alive(true) {}
   Point getPoint()       const   { return point;    }
   Velocity getVelocity() const   { return velocity; }

   //bool isAlive();
   void setPoint(Point point);
   void setVelocity(Velocity velocity);
   void kill();
   void advance();
   bool isAlive();
   void screenWrap();
   //virtual void draw() = 0;
};


#endif /* FLYINGOBJECT.H */
