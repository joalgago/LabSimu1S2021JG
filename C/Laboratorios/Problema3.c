/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema3.c -o Problema3 -lm
Fecha: Tue May 4 17:14:32 CST 2021
Librerias: stdio, (otras)
Resumen: Operaciones con dos vectores
Entradas: Dos vectores de tres posiciones cada uno
Salidas: Magnitudes, suma, producto escalar y vectorial
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Declaramos los prototipos de las funciones
void imprimir(float v[]);
float magnitud(float v[]);
void suma(float a[], float b[]);
float prodpunt(float a[], float b[]);
void prodcruz(float a[], float b[]);
//Declaramos los dos arreglos que almacenaran nuestros dos vectores
float v1[3];
float v2[3];
//Almacenamos el tamaño de los vectores en la variable n
int n = sizeof(v1)/sizeof(v1[0]);

void main(){
//Bienvenida al usuario
    printf("*****Diversas operaciones con dos vectores***** \n");
//Declaramos la variable que almacenara las magnitudes y el producto escalar (la sobre escribiremos)
    float op;
//Solicitamos las componentes del primer vector
    printf("Ingrese tres componentes para el primer vector: ");
    for (int i = 0; i < n; i++)
    {
//Llenamos el primer vector con un ciclo for
        scanf("%f",&v1[i]);
    }
//Solicitamos las componentes del segundo vector
    printf("Ingrese tres componentes para el segundo vector: ");
    for (int i = 0; i < n; i++)
    {
//Llenamos el segundo vector con un ciclo for
        scanf("%f",&v2[i]);
    }
//Calculamos la magnitud del primer vector y la imprimimos aproximada a dos decimales
    op = magnitud(v1);
    printf("La magnitud de (");
    imprimir(v1);
    printf(") es %.2f \n",op);
//Calculamos la magnitud del segundo vector y la imprimimos aproximada a dos decimales
    op = magnitud(v2);
    printf("La magnitud de (");
    imprimir(v2);
    printf(") es %.2f \n",op);
//Imprimimos la suma de ambos vectores
    printf("La suma de ambos vectores es: (");
    suma(v1,v2);
    printf(") \n");
//Calculamos el producto escalar y lo imprimimos aproximado a dos decimales
    op = prodpunt(v1,v2);
    printf("El producto escalar de ambos vectores es: %.2f \n",op);
//Imprimimos el producto vectorial del primer vector con el segundo
    printf("El producto vectorial de (");
    imprimir(v1);
    printf(") con (");
    imprimir(v2);
    printf(") es: (");
    prodcruz(v1,v2);
    printf(") \n");

}

void imprimir(float v[]){
//Imprimimos cada elemento del vector con los valores separados por comas y aproximados a dos decimales    
    for (int i = 0; i < n; i++)
    {
        printf("%.2f, ",v[i]);
    }
    
}
float magnitud(float v[]){
//Declaramos nuestro resultado y lo iniciamos en cero
    float res = 0;
    for (int i = 0; i < n; i++)
    {
//Sumamos el cuadrado de cada elemento del vector
        res += v[i]*v[i];
    }
//Devolvemos la raíz cudrada de la suma
    return sqrt(res);
}
void suma(float a[], float b[]){
//Declaramos nuestro vector resultado
    float res[n];
    for (int i = 0; i < n; i++)
    {
//En cada componente colocamos la suma de las componentes correspondientes de a y b
        res[i] = a[i] + b[i];
    }
//Imprimimos el vector resultante
    imprimir(res);  
}
float prodpunt(float a[], float b[]){
//Declaramos nuestro resultado y lo iniciamos en cero
    float res = 0;
    for (int i = 0; i < n; i++)
    {
//Sumamos el producto de las componentes de a y b uno a uno
        res += a[i]*b[i];
    }
//Devolvemos dicha suma
    return res;
}
void prodcruz(float a[], float b[]){
//Declaramos el vector resultante y calculamos el producto con su fórmula
    float res[n];
    res[0] = a[1]*b[2]-a[2]*b[1];
    res[1] = -a[0]*b[2]+a[2]*b[0];
    res[2] = a[0]*b[1]-a[1]*b[0];
//Imprimimos el resultado
    imprimir(res);
}
