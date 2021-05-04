/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Crecimientoplanta.c -o Crecimientoplanta
Fecha: Mon May 3 16:57:09 CST 2021
Librerias: stdio, (otras)
Resumen: Hacer un ajuste a una serie de datos usando el método de mínimos cuadrados
Entradas: Lista de datos de tiempo y alturas
Salidas: Gráfica de puntos vs ajuste, estimación de crecimiento usando el ajuste
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
//Prototipo de funciones
float sum(float a[]);
float summult(float a[], float b[]);
//Arreglos de datos que se usaran para el ajuste
float T[8] = {1,2,3,4,5,6,7,8};
float Y[8] = {0.01,0.03,0.09,0.13,0.19,0.22,0.37,0.43};
//Variable que almacenara el tamaño de los arreglos
int n = sizeof(T)/sizeof(T[0]);

void main(){
//Declaración de variables 
    float m,b,res;
//Se calcula la pendiente y el intersecto usando el método de mínimos cuadrados
    m = (n*summult(T,Y)-sum(T)*sum(Y))/(n*summult(T,T)-sum(T)*sum(T));
    b = (sum(Y)-m*sum(T))/n;
//Se calcula la altura después de 23 semanas, usando el ajuste antes calculado    
    res = 23*m + b;
//Se devuelve la respuesta anterior, junto a la pendiente e intersecto calculados, para poder usarlos
//en el archivo graficador
    printf("Después de 23 semanas la planta medirá (de forma estimada) %f m, con error %f \n",res,res*0.01);
    printf("m=%f,b=%f \n",m,b);
//Se imprime en consola el comando para ejecutar el archivo graficador
//De hacerse un nuevo ajuste, se debe cambiar la función obtenida en el arhivo graficador antes de ejecutar
//este comando
    system("gnuplot graficador.gp");
}

float sum(float a[]){
//Se declara la variable que almacenara el resultado de la sumatoria, se inicia en cero    
    float res = 0;
//Con un ciclo for, sumamos todos los elementos del arreglo    
    for (int i = 0; i < n; i++)
    {
        res += a[i];
    }
//Devolvemos la respuesta    
    return res;
}
float summult(float a[], float b[]){
//Se declara la variable que almacenara el resultado de la sumatoria, se inicia en cero 
    float res = 0;
//Con un ciclo for, sumamos el producto de dos elementos en la misma posición de ambos arreglos, con
//todos los elementos
    for (int i = 0; i < n; i++)
    {
        res += a[i]*b[i];
    }
//Devolvemos la respuesta 
    return res;
}
