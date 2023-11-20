CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -I/usr/local/include/opencv4/ `pkg-config opencv4 --libs`

all: grayscale

grayscale: grayscale.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale imagen_gris.jpg
