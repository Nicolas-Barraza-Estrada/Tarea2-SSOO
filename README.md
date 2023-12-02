# Tarea 2 - Procesamiento de Imágenes Secuencial/Paralelo

Este repositorio contiene implementaciones secuenciales y paralelas para convertir imágenes a escala de grises.

## 1. Secuencial

Para compilar y ejecutar la versión secuencial, siga los siguientes pasos:
```bash
cd 1.Secuencial/
make
./grayscale imagen_a_color.jpg imagen_escala_de_grises.jpg
#Ejemplo: ./grayscale nasa.jpg imagen_gris.jpg
make clean
```
## 2. Parelo (Thread)

Para compilar y ejecutar la versión parela utilizando la clase Thread, siga los siguientes pasos:
```bash
cd 2.Thread/
make
./grayscale_thread imagen_a_color.jpg imagen_escala_de_grises.jpg 4
#Ejemplo: ./grayscale_thread nasa.jpg imagen_gris.jpg 4
make clean
```

## 3. Parelo (OpenMP)
Para compilar y ejecutar la versión parela utilizando la API OpenMP, siga los siguientes pasos:
```bash
cd 3.OpenMP/
make
./grayscale_openMP imagen_a_color.jpg imagen_escala_de_grises.jpg 4
#Ejemplo: ./grayscale_openMP nasa.jpg imagen_gris.jpg 4
make clean
```
## Resultados
Las siguientes mediciones se realizaron utilizando un procesadores de 6 nucleos / 12 hebras, frecuencia máxima 4.2 GHz.
Para la tarea se utilizaron 4 hebras.
### Tiempos de ejecución:
- Secuencial: 721254 microsegundos
- 4 Thread : 191028 microsegundos
- 4 thread OpenMP : 188081 microsegundos
### Secuencial / Thread
- Speedup : 721254 / 191028 = 3.775
- Eficiencia : 3.77 / 4 = 0.943

### Secuencial / OpenMP
- Speedup : 721254 / 188081 = 3.834
- Eficiencia : 3.83 / 4 = 0.958