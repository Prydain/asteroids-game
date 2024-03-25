/*********************************************
 * Header file:
 *    VELOCITY
 * Author:
 *    Brian Tipton
 * Summary:
 **********************************************/

#include "velocity.h"

#include "random.h"

/******************************************
 * Velocity(float dx, float dy) 
 * constructor 
*****************************************/
Velocity::Velocity(float dx, float dy)
{
   setDx(dx);
   setDy(dy);
}

/******************************************
 * setDy(float dx)
 * 
*****************************************/
void Velocity::setDx(float dx)
{
   this->dx = dx;
}

/******************************************
 * setDy(float dy)
 * 
*****************************************/
void Velocity::setDy(float dy)
{
   this->dy = dy;
}

Velocity& Velocity::nudge() {
    std::uniform_real_distribution<float> dist(-1.f, 1.f);
    dx += dist(prng());
    dy += dist(prng());
    return *this;
}
