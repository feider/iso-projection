OBJECTS=main.o render.o tilemap.o system.o
LDFLAGS=-lsfml-window -lsfml-graphics -lsfml-system

start: $(OBJECTS)
	g++ $(OBJECTS) $(LDFLAGS) -o start

%.o: %.cpp 
	g++ -c -std=c++11 $< -o $@
