#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;
using namespace chrono;

// Función que realiza la conversión a escala de grises en una parte de la imagen.
void convertToGrayscale(Mat& image, int start_row, int end_row) {
    for (int r = start_row; r < end_row; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b& pixel = image.at<Vec3b>(r, c);
            uchar grayscale = static_cast<uchar>((pixel[0] * 0.3) + (pixel[1] * 0.59) + (pixel[2] * 0.11));
            pixel[0] = pixel[1] = pixel[2] = grayscale;
        }
    }
}

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

    // Divide la imagen en partes para cada hilo.
    int rows_per_thread = image.rows / num_threads;
    vector<thread> threads;

    for (int i = 0; i < num_threads; i++) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1) ? image.rows : (i + 1) * rows_per_thread;

        threads.emplace_back(convertToGrayscale, ref(image), start_row, end_row);
    }

    // Espera a que todos los hilos terminen.
    for (auto& thread : threads) {
        thread.join();
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
