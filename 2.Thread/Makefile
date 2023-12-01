CC = g++
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

all: grayscale_thread

grayscale_thread: grayscale_thread.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale_thread gris.jpg imagen_escala_grises.jpg imagen_gris.jpg imagen_gises.png imagen_gises.jpg
