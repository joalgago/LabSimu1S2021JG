/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Primo.c -o Primo
Fecha: Wed Mar 17 10:46:16 CST 2021
Librerias: stdio, (otras)
Resumen: Evalua si un número mayor a 1 es primo
Entradas: Número entero mayor a 1
Salidas: Texto (es primo, no es primo)
*/

//Librerias
#include <stdio.h>

void main(){

//Declaración de la variable que almacenara el número solicitado    
    int n;
//Declaración e inicialización de nuestro contador y la variable que definira si n es primo o no    
    int i = 2;
    int primo = 1;

//Se solicita un número mayor a 1 y se almacena en la variable n    
    printf("Ingrese un entero mayor a 1: ");
    scanf("%d",&n);

//Mientras el usuario no ingrese un número mayor a 1    
    while(n<=1){
//El programa le seguirá solicitando el número hasta que cumpla con el requisito solicitado        
        printf("Ingrese un entero mayor a 1: ");
        scanf("%d",&n);
    }

//Mientras no se halla alterado el valor de la variable primo, y el contador sea menor a n-1    
    while(i<n-1 && primo==1){
//Si el contador no es divisor de n (si el residuo de su división es cero)        
        if(n%i==0){
//Se cambia el valor de primo a cero y se termina el ciclo            
            primo = 0;
//De lo contrario            
        }else{
//Se aumenta una unidad el contador y se repite el ciclo            
            i++;
        }
    }

//Si el valor de la variable primo fue cambiado a cero    
    if(primo==0){
//Devuelve el mensaje de que el número ingresado no es primo        
        printf("%d no es primo \n", n);
//De lo contrario        
    }else{
//Devuelve el mensaje de que el número es primo        
        printf("%d es primo \n", n);
    }

}
