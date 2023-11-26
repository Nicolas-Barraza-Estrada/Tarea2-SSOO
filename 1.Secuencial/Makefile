CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -I/usr/local/include/opencv4/ `pkg-config opencv4 --libs`

all: grayscale

grayscale: grayscale.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale gris.jpg imagen_escala_grises.jpg imagen_gris.jpg imagen_gises.png imagen_gises.jpg
