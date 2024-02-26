/*************************************************************
 * File: 
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/

#include <iostream>
#include <cmath>

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "bullet.h"

/*************************************************************
 * Function: Bullet()
 * Description: ca
 *************************************************************/
Bullet::Bullet(Point point, Velocity velocity)
{
   setPoint(point);
   setVelocity(velocity);
   frameCount = 0;
}

/*************************************************************
 * Function: draw()
 * Description: draw bullet
 *************************************************************/
void Bullet::draw()
{
   drawDot(getPoint());
}

/*************************************************************
 * Function:
 * Description: 
 *************************************************************/
int Bullet::counter()
{
   frameCount++;
   return frameCount;
}