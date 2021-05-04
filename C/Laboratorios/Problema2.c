/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema2.c -o Problema2
Fecha: Wed Apr 21 17:31:05 CST 2021
Librerias: stdio, (otras)
Resumen: Ordena un vector de forma ascendente
Entradas: 5 valores enteros
Salidas: Valores ordenados
*/

//Librerias
#include <stdio.h>
//Prototipo de funcion
void orden(int a[]);

void main(){
//Se declara el arreglo que almacenara los datos
    int A[5];
//Bienvenida al usuario
    puts("*****Ordenar 5 números enteros*****");
    puts("Ingrese cinco enteros");
//Ciclo for que almacena todos los datos en el vector A
    for(int i=0;i<5;i++){
        scanf("%i", &A[i]);
    }
//Se aplica la función de ordenamiento a A
    orden(A);
//Se imprime el vector ya ordenado
    for(int i=0;i<5;i++){
        printf("%d ", A[i]);
    }
//Imprime un salto de línea    
    puts("");
}

void orden(int a[]){
//Contadores    
     int inMenor, i, j;
//Se utiliza el primer espacio del vector para comparar el resto de los valores
    for(i=0;i<4;i++)
    {
        inMenor = i;
//Se busca en la sublista generada la posicion del menor valor
        for(j=i+1; j<5;j++)
        {
            if  (a[j]<a[inMenor]){
                inMenor = j;
            }
        }    
//Se realiza el cambio del menor elemento por el seleccionado de pivote, solo si este es mayor
        if (i!=inMenor)
        {
            int aux = a[i];
            a[i] = a[inMenor];
            a[inMenor] = aux;
        }
    }
}