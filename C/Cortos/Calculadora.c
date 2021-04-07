/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Calculadora.c -o Calculadora
Fecha: Tue Apr 6 19:30:29 CST 2021
Librerias: stdio, (otras)
Resumen: Calculadora simple usando funciones
Entradas: Dos números para operar, indicador de operación
Salidas: Resultado de la operación elegida
*/

//Librerias
#include <stdio.h>

//Declaración de funciones
float suma(float x, float y);
float resta(float x, float y);
float mult(float x, float y);
float div(float x, float y);

void main(){
//Bienvenida al usuario
printf("*****Calculadora simple con dos números***** \n");

//Declaración de variables
float n1, n2, resul;
int op;

//Se crea el bucle de la calculadora, del que solo se saldra bajo cierta condición    
while(1){

//Se dan las instrucciones de la calculadora y sus posibles operaciones    
    printf("Posibles operaciones: \n");
    printf("Cerrar calculadora -> 0 \n");
    printf("Suma (+) -> 1 \n");
    printf("Resta (-) -> 2 \n");
    printf("Multiplicación (*) -> 3 \n");
    printf("División (/) -> 4 \n");

//Se solicita el primer número
    printf("Ingrese primer número a operar: ");
    scanf("%f",&n1);

//Se solicita la operación
    printf("Ingrese operación: ");
    scanf("%d",&op);

//Se evalua si el indicador de operación ingresado concuerda con alguno de los porporcionados
    while(op > 4 || op < 0){
        printf("Ingrese operación válida: ");               //De no ser así, se solicita la operación nuevamente
        scanf("%d",&op);
    }
//Si se ingresa el valor de cierre, el programa termina (se rompe el bucle) 
    if(op == 0){                                            
        break;
    }

//Se solicita el segundo número
    printf("Ingrese segundo número a operar: ");
    scanf("%f",&n2);

//Se evalúan todas las posibilidades de operaciones
    switch(op){
        case 1:                                         //Si op == 1
            resul = suma(n1,n2);                        //Se realiza la función suma
            printf("%f + %f = %f \n",n1,n2,resul);      //Se imprime el resultado de forma explícita
            break;
        case 2:                                         //Si op == 2
            resul = resta(n1,n2);                       //Se realiza la función resta
            printf("%f - %f = %f \n",n1,n2,resul);      //Se imprime el resultado de forma explícita
            break;
        case 3:                                         //Si op == 3
            resul = mult(n1,n2);                        //Se realiza la función mult
            printf("%f * %f = %f \n",n1,n2,resul);      //Se imprime el resultado de forma explícita 
            break;
        case 4:                                         //Si op == 4
            resul = div(n1,n2);                         //Se realiza la función div
            printf("%f / %f = %f \n",n1,n2,resul);      //Se imprime el resultado de forma explícita
            break;
    }
    printf("\n");                                       //Se imprime un salto de línea y se repite el ciclo
}
}

//Definición de funciones
float suma(float x, float y){
    float res = x+y;                            //Suma los dos valores y lo almacena en res
    return res;                                 //Devuelve el resultado
}
float resta(float x, float y){
    float res = x-y;                            //Le resta el segundo al primero y lo almacena en res
    return res;                                 //Devuelve el resultado
}
float mult(float x, float y){
    float res = x*y;                            //Multiplica ambos valores y lo almacena en res
    return res;                                 //Devuelve el resultado
}
float div(float x, float y){
    float res = x/y;                            //Divide el primero entre el segundo y lo almacena en res
    return res;                                 //Devuelve el resultado
}
