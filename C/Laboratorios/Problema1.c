/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema1.c -o Problema1
Fecha: Wed Apr 21 09:27:24 CST 2021
Librerias: stdio, (otras)
Resumen: Ordenar un vector según lo requiera el usuario
Entradas: Carácter ingresado por usuario en el menú
Salidas: Vector ordenado
*/

//Librerias
#include <stdio.h>
#include <ctype.h>
//Prototipo de funciones
void asc (int a[]);
void desc (int a[]);

void main(){
//Arreglo de números y variable que almacenara el caracter
    int A[10] = {2,4,6,8,10,12,14,16,18,20};
    char men;
//Bienvenida al usuario 
    puts("*****Visualizador de números pares del rango 2-20*****");
    puts("¿Cómo desea ver los números?");
//Ciclo que solo finalizara bajo ciertas condiciones
    while(1){
//Se dan las opciones del menú        
        puts("a -> De forma ascendente (menor a mayor)");
        puts("d -> De forma descendente (mayor a menor)");
//Se solicita el caracter al usuario, convirtiendolo a minusculas          
        men = tolower(getchar());
//Si este es igual a 'a'
        if(men == 'a'){
//Aplica la función ascendente            
            asc(A);
//Deja un salto de línea            
            puts("");
//Termina el ciclo while            
            break;
//Como segunda opcion, si es igual a 'd'            
        }else if (men == 'd')
        {
//Aplica la funcion descendente            
            desc(A);
//Deja salto de linea            
            puts("");
//Terimina el ciclo while            
            break;
        }
//Si se ingresó otro valor, imprime este mensaje y repite el ciclo        
        puts("Por favor ingrese un valor válido");
        }
}

void asc (int a[]){
//Imprime el vector en el orden en el que esta    
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }
}
void desc (int a[]){
//Imprime el vector en orden inverso    
    for(int i=9;i>=0;i--){
        printf("%d ", a[i]);
    }
}
