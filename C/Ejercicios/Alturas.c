/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Alturas.c -o Alturas
Fecha: Wed Mar 17 09:59:00 CST 2021
Librerias: stdio, (otras)
Resumen: Programa que calcula la media, máximo y mínimo de un grupo de alturas (se detiene solo al detectar
una negativa)
Entradas: Alturas
Salidas: Media,máximo, mínimo
*/

//Librerias
#include <stdio.h>

void main(){

//Bienvenida al usuario    
    printf("***** Programa para calcular media, máximo y mínimo de alturas positivas ***** \n");    

//Se declaran e inicializan las primeras variables del programa (excepto la que almacenara las alturas)    
    int n = 0;          //Variable que almacenara la cantidad de alturas ingresadas
    float med = 0, h;   //Variable que almacenara la media y las alturas (una a una)

    printf("Ingrese una altura: ");         //Se solicita la primer altura
    scanf("%f",&h);                         //Se extrae dicha altura y se almacena en la variable h

//Se declaran el máximo y el mínimo, iniciandolas en el valor de h ingresado previamente    
    float max = h, min = h;

//Ciclo while que cotrolara por cuanto timepo se mantenrda activo el programa    
    while(h>=0){                            //Mientras la altura ingresada sea positiva
        n++;                                //Se aumenta en uno la cantidad de alturas ingresadas
        med+=h;                             //Se suma la altura a la media
        if(h>max){                          //Si dicha altura es mayor al máximo registrado previamente
            max = h;                        //Se toma como nuevo máximo
        }else if(h<min){                    //En cambio, si es menor al anterior mínimo
            min = h;                        //Se toma como el nuevo mínimo
        }
        printf("Ingrese una altura: ");     //Se vuelve a solicitar otra altura
        scanf("%f",&h);                     //Se reescribe el valor de h con la nueva altura y se repite el ciclo
    }

//Finalmente, se evalua que tipo de salida debe devolver el programa    
    if(n==0){                               //Si no se ingresaron números positivos
        printf("Alturas no positivas \n");  //Devuelve este mensaje
    }else{                                  //Por el contrario, con tener al menos un número positivo
//Imprime la media, el máximo y el mínimo
        printf("La media es: %.2f \n", med/n);  //La media se aproxima a dos decimales
        printf("El máximo es: %f \n", max);
        printf("El mínimo es: %f \n", min);
    }

}
