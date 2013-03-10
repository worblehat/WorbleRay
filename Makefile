SOURCE=AmbientLight.cpp PointLight.cpp LambertMaterial.cpp main.cpp Plane.cpp SDLWindow.cpp Scene.cpp Sphere.cpp
PROGRAM=raytracer
C=g++
CFLAGS_SDL=-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
LIBFLAGS_SDL=-L/usr/lib/x86_64-linux-gnu -lSDL

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(C) $(SOURCE) -o$(PROGRAM) $(LIBFLAGS_SDL) $(CFLAGS_SDL)

clean:
	rm -rf *.o raytracer
