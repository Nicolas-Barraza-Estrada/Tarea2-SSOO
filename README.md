# Tarea 2 - Procesamiento de Imágenes Secuencial/Paralelo

Este repositorio contiene implementaciones secuenciales y paralelas para convertir imágenes a escala de grises.

## 1. Secuencial

Para compilar y ejecutar la versión secuencial, siga los siguientes pasos:
```bash
cd 1.Secuencial/
make
./grayscale imagen_a_color.jpg imagen_escala_de_grises.jpg
# ./grayscale nasa.jpg imagen_gris.jpg
make clean
```
## 2. Parelo (Thread)

Para compilar y ejecutar la versión parela utilizando la clase Thread, siga los siguientes pasos:
```bash
cd 2.Thread/
make
./grayscale_thread imagen_a_color.jpg imagen_escala_de_grises.jpg 4
# ./grayscale_thread  nasa.jpg imagen_gris.jpg 4
make clean
```

## 3. Parelo (OpenMP)
Para compilar y ejecutar la versión parela utilizando la API OpenMP, siga los siguientes pasos:
```bash
cd 3.OpenMP/
make
./grayscale_openMP imagen_a_color.jpg imagen_escala_de_grises.jpg 4
# ./grayscale_openMP nasa.jpg imagen_gris.jpg 4
make clean