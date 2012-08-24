CC = g++-4.4
CFLAGS = -Wall
PROG = test

SRCS = test.cpp Ship.hpp Ship.cpp ShipGraphicsComponent.hpp ShipGraphicsComponent.cpp ShipPhysicsComponent.hpp ShipPhysicsComponent.cpp Sphere.cpp Defs.hpp

LIBS = -lglut -lGLU -lrt -lm

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
