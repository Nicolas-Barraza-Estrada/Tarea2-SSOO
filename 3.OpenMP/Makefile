CC = g++
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

all: grayscale_openMP

grayscale_openMP: grayscale_openMP.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale_openMP gris.jpg imagen_gris.png imagen_escala_grises.jpg imagen_gris.jpg imagen_gises.png imagen_gises.jpg
