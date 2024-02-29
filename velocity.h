/*********************************************
 * Header file:
 *    VELOCITY
 * Author:
 *    Brian Tipton
 * Summary:
 **********************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

/******************************************
 * VELOCITY
 * Velocity is used to determine bullet and bird velocity
 *****************************************/
class Velocity
{
private:
   float dx;
   float dy;

public:
// constructor
   Velocity() : Velocity(0.f, 0.f) {}
   Velocity(float dx, float dy);

   float speed_squared() const
   {
      return dx*dx + dy*dy;
   }

   float speed() const;

   Velocity& nudge();

   // getters
   float getDx() const
   {
      return dx;
   }

   float getDy() const
   {
      return dy;
   }

   void setDx(float dx);
   void setDy(float dy);
};
#endif // VELOCITY_H
