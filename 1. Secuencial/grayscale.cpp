#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Lee el archivo de imagen a color.
    Mat image = imread("earth.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Inicia el temporizador.
    auto start = high_resolution_clock::now();

    // Convierte la imagen a escala de grises usando el método mencionado.
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            // Obtiene un puntero al píxel en la posición (r, c).
            Vec3b& pixel = image.at<Vec3b>(r, c);

            // Calcula la escala de grises utilizando el método mencionado.
            uchar grayscale = static_cast<uchar>((min({pixel[0], pixel[1], pixel[2]}) + max({pixel[0], pixel[1], pixel[2]})) / 2);

            // Establece el mismo valor para cada canal (escala de grises).
            pixel[0] = pixel[1] = pixel[2] = grayscale;
        }
    }

    // Detiene el temporizador.
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Imprime el tiempo de ejecución.
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    // Guarda la imagen en escala de grises.
    imwrite("imagen_gris.jpg", image);

    return 0;
}
