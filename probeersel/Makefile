CC = g++-4.4
CFLAGS = -Wall
PROG = test

SRCS = test.cpp Triangle.cpp Defs.hpp

LIBS = -lglut -lGLU -lrt -lm

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
