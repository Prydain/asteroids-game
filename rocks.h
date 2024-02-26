/*************************************************************
 * File: rocks_h
 * Author: Brian Tipton
 *
 * Description: 
 *************************************************************/
#ifndef rocks_h
#define rocks_h

#include <vector>

#include "rocks.h"
#include "flyingObject.h"
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include "bullet.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

// Define the following classes here:
//   Rock

/*************************************************************
 * Class: Rock 
 * Description: 
 *************************************************************/
class Rock : public FlyingObject
{
public:
   virtual ~Rock() {}
   virtual void draw() = 0;
   virtual void hit() = 0;
   virtual int getRockSize() const = 0;
   //virtual std::vector <Rock*> splitRock() const = 0;

protected:
   int rotation;
};

//   BigRock
/*************************************************************
 * Class: BigRock 
 * Description: 
 *************************************************************/
class BigRock : public Rock
{
public:
   BigRock(Point point, Velocity velocity);
   ~BigRock() {}
   virtual int getRockSize() const override { return BIG_ROCK_SIZE; }
   virtual void draw();
   virtual void hit();
   //virtual std::vector <Rock*> splitRock() const override;
};

//   MediumRock
/*************************************************************
 * Class: MediumRock 
 * Description: 
 *************************************************************/
class MediumRock : public Rock
{
public:
   MediumRock(Point point, Velocity velocity);
   virtual ~MediumRock() {}
   virtual int getRockSize() const override { return MEDIUM_ROCK_SIZE; }
   virtual void draw();
   virtual void hit();
   //virtual std::vector <Rock*> splitRock() const override;
};

// //   SmallRock
/*************************************************************
 * Class: SmallRock 
 * Description: 
 *************************************************************/
class SmallRock : public Rock
{
public:
   SmallRock(Point point, Velocity velocity);
   virtual ~SmallRock() {}
   virtual int getRockSize() const override { return SMALL_ROCK_SIZE; }
   virtual void draw();
   virtual void hit();
   //virtual std::vector <Rock*> splitRock() const override;
};

#endif /* rocks_h */