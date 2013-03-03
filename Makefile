SOURCE=main.cpp 
PROGRAM=raytracer
INCLUDE=../glm
C=g++

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(C) -I$(INCLUDE) -o$(PROGRAM) $(SOURCE) 

clean:
	rm -rf *.o raytracer
