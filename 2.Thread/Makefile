CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -I/usr/local/include/opencv4/ `pkg-config opencv4 --libs`

all: grayscale_thread

grayscale_thread: grayscale_thread.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f grayscale_thread gris.jpg imagen_escala_grises.jpg imagen_gris.jpg
