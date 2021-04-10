#include <iostream>
#include <random>
#include <ctime>
#include <math.h>

using namespace std;

double generadorAleatorio() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 2.0);
    return dis(gen);
}

void calculoDeDistancia(double** v1, double** v2, int dimension) {
    double resultado, sumatoria = 0;
    for (double* d1 = *v1, *d2 = *v2; d1 < *v1 + dimension; d1++, d2++)
        sumatoria = sumatoria + pow((*d1 - *d2),2);
    resultado = sqrt(sumatoria);
    //cout << resultado << " ";
}

int main(){
    //CREACION DE VECTORES
    int cantidadVectores, dimension;
    cout << "Ingresar cantidad de vectores a crearse:\n";
    cin >> cantidadVectores;
    cout << "\nIngresar dimensiones deseadas:\n";
    cin >> dimension;
    
    double** conjuntoDeVectores = new double*[cantidadVectores];
    for (double** i = conjuntoDeVectores; i < conjuntoDeVectores + cantidadVectores; i++) {
        *(i) = new double[dimension];
        for (double* j = *(i); j < *(i) + dimension; j++)
            *j = generadorAleatorio();
    }
    
    //CALCULO DE DISTANCIA ENTRE VECTORES
    unsigned tInicio, tFin;        //para medir los tiempos

    tInicio = clock();           //inicio de medición
        
    for (double** i = conjuntoDeVectores; i < conjuntoDeVectores + cantidadVectores; i++) {
        for (double** j = i + 1; j < conjuntoDeVectores + cantidadVectores; j++)
            calculoDeDistancia(i, j, dimension);
    }

    tFin = clock();           //fin de medición
    
    double tiempoOrdenamiento = (double(tFin - tInicio) / CLOCKS_PER_SEC);
    cout << "\nEl tiempo de ejecucion del algoritmo fue de:\t" << tiempoOrdenamiento << " s" << endl;

    //ELIMINACION DE VECTORES
    for (double** i = conjuntoDeVectores; i < conjuntoDeVectores + cantidadVectores; i++) {
        delete[] * i;
    }
    delete[] conjuntoDeVectores;

    return 0;
}