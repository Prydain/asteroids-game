/*********************************************
 * Header file:
 *    SHIP
 * Author:
 *    Brian Tipton
 * Summary:
 **********************************************/

#ifndef SHIP_H
#define SHIP_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"

#define THRUST_AMOUNT 0.5
#define SHIP_ROTATION   6
#define ANGLE_START    270

/******************************************
* SHIP
 *****************************************/
class Ship : public FlyingObject
{
public:
   Ship();
   ~Ship() {}
   int getRotation() const { return rotation; }
   void draw();
   void hit();
   void applyThrust(); 
   void applyRotationLeft();
   void applyRotationRight();
   void isThrust();
   void isNotThrust();

private:
   bool thrust;
   int rotation;
};

#endif // SHIP_H
