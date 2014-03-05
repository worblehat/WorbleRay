SOURCE=AmbientLight.cpp PointLight.cpp LambertMaterial.cpp main.cpp Plane.cpp SDLWindow.cpp Scene.cpp Sphere.cpp
PROGRAM=raytracer
CC=clang++
CFLAGS_SDL=$(shell sdl-config --cflags)
LIBFLAGS_SDL=$(shell sdl-config --libs)

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) $(SOURCE) -Wall -O3 -o$(PROGRAM) $(LIBFLAGS_SDL) $(CFLAGS_SDL)

debug: $(SOURCE)
	$(CC) $(SOURCE) -Wall -O0 -g -o$(PROGRAM) $(LIBFLAGS_SDL) $(CFLAGS_SDL)

clean:
	rm -rf *.o raytracer
