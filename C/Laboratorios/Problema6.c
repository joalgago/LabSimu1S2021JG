/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema6.c -o Problema6 -lm
Fecha: Tue May 4 18:24:51 CST 2021
Librerias: stdio, (otras)
Resumen: Realizar cuatro sumatorias
Entradas: Límite superior de las sumatorias
Salidas: Sumatorias
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Prototipos de funciones
int suma(int n);
float sumb(int n);
float sumc(int n);
float bode(int n);

void main(){
//Declaramos las variables que contendran los resultados y el entero ingresado por el ususario
    int x,res1;
    float res2;
//Bienvenida al usuario
    puts("*****Cálculo de cuatro sumatorias (ver reporte)*****");
//Se solicita el límite superior y se almacena en la variable x
    printf("Ingrese el límite superior de la sumatoria (entero): ");
    scanf("%d",&x);
//Se calcula la primera suma y se imprime el resultado
    res1 = suma(x);
    printf("La sumatoria a) de 1 a %d es %d \n",x,res1);
//Se calcula la segunda suma y se imprime el resultado
    res2 = sumb(x);
    printf("La sumatoria b) de 2 a %d es %f \n",x,res2);
//Se calcula la tercera suma y se imprime el resultado
    res2 = sumc(x);
    printf("La sumatoria c) de 1 a %d es %f \n",x,res2);
//Se calcula la cuarta suma y se imprime el resultado
    res2 = bode(x);
    printf("La sucesión de Bode hasta %d es %f \n",x,res2);

}

int suma(int n){
//Iniciamos el resultado en cero
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
//Realizamos la sumatoria con la fórmula
        res += i*i*(i-3);
    }
//Devolvemos el resultado
    return res;
}
float sumb(int n){
//Iniciamos el resultado en cero
    float res = 0;
    for (int i = 2; i <= n; i++)
    {
//Realizamos la sumatoria con la fórmula, asegurandonos de que se tome el valor decimal, pues i es entero
        res += (float)3/(i-1);
    }
//Devolvemos el resultado
    return res;
}
float sumc(int n){
//Iniciamos el resultado en cero
    float res = 0;
//Debido a lo complejo de la expresión, declaramos dos variables auxiliares para realizar la sumatoria
    float aux1,aux2;
    aux1 = (1+sqrt(5))/2;
    aux2 = (1-sqrt(5))/2;
    for (int i = 1; i <= n; i++)
    {
//Realizamos la sumatoria con la fórmula, asegurandonos de que se tome el valor decimal, pues i es entero
        res += (float)(pow(aux1,(double)i)-pow(aux2,(double)i))/sqrt(5);
    }
//Devolvemos el resultado
    return res;
}
float bode(int n){
//Iniciamos el resultado en cero
    float res = 0;
    for (int i = 2; i <= n; i++)
    {
//Realizamos la sumatoria con la fórmula
        res += 0.1*(3*pow(2,i-2)+4);
    }
//Devolvemos el resultado
    return res;
}
