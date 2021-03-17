/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc RaizCuad.c -o RaizCuad
Fecha: Wed Mar 17 10:28:06 CST 2021
Librerias: stdio, (otras)
Resumen: Calcula la raiz cuadrada (aproximada a entero) de un número entero
Entradas: Número n (entero)
Salidas: Raíz cuadrada de n (aproximada al entero más cercano hacia abajo)
*/

//Librerias
#include <stdio.h>

void main(){

//Declaracion de la variable que almacenara el entero al que se le busca la raiz cuadrada
    int n;

//Bienvenida al usuario    
    printf("***** Programa para calcular raices cuadradas enteras ***** \n");
//Solicitud y almacenamiento del número al que se le encontrara la raiz cuadrada    
    printf("Ingrese un número entero: ");
    scanf("%d",&n);

//Declaracion e inicializacion del contador    
    int i = 1;

//Mientras el contador al cuadrado sea menor o igual que el número ingresado    
    while(i*i<=n){
//El contador aumentara una unidad        
        i++;
    }

//Finalmente, se imprime el resultado (se resta uno debido a que el ciclo while se efectua en i*i==n, por lo
//que el contador lleva una unidad de más)    
    printf("La raíz cuadrada de %d es: %d \n",n,i-1);

}
