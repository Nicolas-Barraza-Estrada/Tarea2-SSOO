#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagen_a_color> <imagen_escala_de_grises> <cantidad_de_hilos>" << endl;
        return -1;
    }

    // Lee el archivo de imagen a color.
    Mat image = imread(argv[1], IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen a color." << endl;
        return -1;
    }

    int num_threads = stoi(argv[3]);

    // Inicia el temporizador.
    auto start = high_resolution_clock::now();

    // Convierte la imagen a escala de grises usando el método mencionado con OpenMP.
    #pragma omp parallel for num_threads(num_threads)
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            // Obtiene un puntero al píxel en la posición (r, c).
            Vec3b& pixel = image.at<Vec3b>(r, c);

            // Calcula la escala de grises utilizando Luminosity Method.
            uchar grayscale = static_cast<uchar>((pixel[0] * 0.3) + (pixel[1] * 0.59) + (pixel[2] * 0.11));
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
    imwrite(argv[2], image);

    return 0;
}
