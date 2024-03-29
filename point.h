/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef POINT_H
#define POINT_H

#include <iostream>

/*********************************************
 * POINT
 * A single position.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0)  {}
   Point(bool check)  : x(0.0), y(0.0)  {}
   Point(float x, float y);

   // getters
   float getX()       const { return x;              }
   float getY()       const { return y;              }

   // setters
   void setX(float x);
   void setY(float y);
   void addX(float dx)      { setX(getX() + dx);     }
   void addY(float dy)      { setY(getY() + dy);     }

   float length_squared() const
   {
      return x*x + y*y;
   }

   float length() const;

   Point& operator-=(const Point& rhs)
   {
       x -= rhs.x;
       y -= rhs.y;
       return *this;
   }

private:
   float x;           // horizontal position
   float y;           // vertical position
};

// subtracting two points and getting the length from the resulting
// points is a way to see how far they are from each other:
// (p1 - p2).length()  
inline Point operator-(const Point& lhs, const Point& rhs) {
    Point retval(lhs);
    retval -= rhs;
    return retval;
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);

#endif // POINT_H
