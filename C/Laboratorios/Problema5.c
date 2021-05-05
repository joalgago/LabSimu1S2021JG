/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema5.c -o Problema5
Fecha: Tue May 4 18:10:49 CST 2021
Librerias: stdio, (otras)
Resumen: Calcular el factorial de un entero
Entradas: Un número entero n
Salidas: El factorial de n
*/

//Librerias
#include <stdio.h>
//Prototipo de función
int factorial(int x);

void main(){
//Declaramos las variables del entero a valuar y su factorial
    int n,nfac;
//Bienvenida al usuario
    printf("*****Cálculo de la función factorial***** \n");
//Se solicita un entero al usuario y se almacena en la variable n
    printf("Ingrese un número entero (de ingresar un decimal solo se tomara la parte entera): ");
    scanf("%d",&n);
//Se calcula el factorial de n 
    nfac = factorial(n);
//Se imprime el resultado
    printf("%d! = %d \n",n,nfac);

}

int factorial(int x){
// Uno factorial y cero factorial son iguales a uno, la función valuada en estos devuelve 1    
    if ((x == 0) || (x == 1)){
        return 1;
    }else{
//Y cualquier otro valor será la multiplicación de sí mismo por todos los enteros menores a él, es decir, él
//mismo por la función factorial valuada en el entero anterior
        return x*factorial(x-1);
    }
}
