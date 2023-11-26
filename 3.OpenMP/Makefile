CC = g++
CFLAGS = -Wall -std=c++11 -fopenmp  # Agregamos la bandera -fopenmp
LIBS = -I/usr/local/include/opencv4/ `pkg-config opencv4 --libs`

all: grayscale_openMP

grayscale_openMP: grayscale_openMP.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale_openMP imagen_gris.png imagen_escala_grises.jpg imagen_gris.jpg imagen_gises.png imagen_gises.jpg
