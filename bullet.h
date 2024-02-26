#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE  40

#include <iostream>

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*************************************************************
 * Class: Bullet
 * Description: draw a bullet, set its point and velocity
 * inherits FlyingObject class
 *************************************************************/
class Bullet : public FlyingObject
{
public:
   Bullet(Point point, Velocity velocity);
   //void fire(Point point, float angle);
   void draw();
   int counter();

private:
   int frameCount;
};

#endif /* BULLET_H */
