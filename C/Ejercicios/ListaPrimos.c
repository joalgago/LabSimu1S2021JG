/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc ListaPrimos.c -o ListaPrimos
Fecha: Wed Mar 17 11:08:34 CST 2021
Librerias: stdio, (otras)
Resumen: Toma dos números enteros positivos y devuelve todos los primos entre estos
Entradas: Dos enteros (Inicio y fin del ciclo)
Salidas: Lista de números primos
*/

//Librerias
#include <stdio.h>

void main(){

//Bienvenida al usuario    
    printf("***** Lista de primos en rango dado por el usuario ***** \n");

//Declaración del contador y los límites de la lista    
    int n1,n2,i;

//Solicitud y almacenamiento de los valores de los límites de la lista    
    printf("Ingrese límite inferior de la lista: ");
    scanf("%d",&n1);
    printf("Ingrese límite superior de la lista: ");
    scanf("%d",&n2);

//Este primer contador se iniciliza en el límite inferior de la lista    
    i = n1;

//Se imprime la primer parte del mensaje
    printf("Los primos en el rango de %d-%d son: ",n1,n2);

//Mientras este contador i sea menor que el límite superior de la lista, se desarrollara el subproceso de
//evalucaión de primos    
    while(i<=n2){
//Declaración e inicialización de un segundo contador j y la variable que definira si i es primo o no    
        int j = 2;
        int primo = 1;
//Mientras no se halla alterado el valor de la variable primo, y el contador sea menor a i    
        while(j<i && primo==1){
//Si el contador no es divisor de i (si el residuo de su división es cero)        
            if(i%j==0){
//Se cambia el valor de primo a cero y se termina el ciclo            
                primo = 0;
//De lo contrario            
            }else{
//Se aumenta una unidad el contador y se repite el ciclo            
                j++;
            }
        }
//Al finaluizar el subproceso de evaluación de primos, si el valor de la variable primo no se alteró        
        if(primo==1){
//Se imprime i, pues en efecto es primo            
            printf("%d,",i);            
        }
//Se aumenta una unidad a i, y el ciclo se repite nuevamente            
        i++;
    }

//Se imprime un salto de línea al final de la lista
    printf("\n");

}
