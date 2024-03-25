###############################################################
# Program:
#     Milestone 11, Asteroids
#     Brother Dudley, CS165
# Author:
#     Brian Tipton
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################

LFLAGS = -lglut -lGLU -lGL
CXXFLAGS = -std=c++20 -O3 -Wall -Wextra -pedantic-errors $(EXTRA)

###############################################################
# Build the main game
###############################################################
asteroids: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o random.o
	$(CXX) -o $@ $^ $(LFLAGS) $(EXTRA)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################

%.o : %.cpp %.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

driver.o: driver.cpp game.h
	$(CXX) -c driver.cpp $(CXXFLAGS)

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	$(CXX) -c game.cpp $(CXXFLAGS)

velocity.o: velocity.cpp velocity.h point.h
	$(CXX) -c velocity.cpp $(CXXFLAGS)

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	$(CXX) -c flyingObject.cpp $(CXXFLAGS)

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	$(CXX) -c ship.cpp $(CXXFLAGS)

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	$(CXX) -c bullet.cpp $(CXXFLAGS)

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	$(CXX) -c rocks.cpp $(CXXFLAGS)


###############################################################
# General rules
###############################################################
clean:
	rm -f asteroids *.o
