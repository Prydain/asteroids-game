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
   Point point{};
   Velocity velocity{};
   bool alive = true;

public:
   FlyingObject() = default;
   FlyingObject(Point point, Velocity velocity) : point(point), velocity(velocity) {}

   Point getPoint()       const   { return point;    }
   Velocity getVelocity() const   { return velocity; }

   //bool isAlive();
   void setPoint(Point point);
   void setVelocity(Velocity velocity);
   void kill();
   void advance();
   bool isAlive() const;
   void screenWrap();
   //virtual void draw() = 0;
};


#endif /* FLYINGOBJECT.H */
