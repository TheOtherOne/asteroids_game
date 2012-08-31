CC = g++-4.4
CFLAGS = -Wall
PROG = game

SRCS = game.cpp Ship.hpp Ship.cpp ShipGraphicsComponent.hpp ShipGraphicsComponent.cpp ShipPhysicsComponent.hpp ShipPhysicsComponent.cpp RockPhysicsComponent.hpp RockPhysicsComponent.cpp RockGraphicsComponent.hpp RockGraphicsComponent.cpp PhysicsComponent.hpp PhysicsComponent.cpp PhysicsWorld.hpp PhysicsWorld.cpp Rock.hpp Rock.cpp Defs.hpp

LIBS = -lglut -lGLU -lrt -lm

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
