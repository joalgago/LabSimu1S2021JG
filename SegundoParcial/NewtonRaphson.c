/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc NewtonRaphson.c -o NewtonRaphson -lm
Fecha: Mon May 3 09:19:44 CST 2021
Librerias: stdio, (otras)
Resumen: Cálculo de la raíz de una función por el método de Newton-Raphson
Entradas: Punto inicial, tolerancia
Salidas: Posible raíz de la función
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Constante de máximas iteraciones
#define max_iter 200
//Prototipos de funciones
float f(float x);
float df(float x);
float NR(float xi, float tol, int *itot);

void main(){
//Declaración de variables que almacenaran la presicion y valor inicial del método, así como la respuesta del mismo
//Además de la cantidad de iteraciones
    float x, pres, sol;
    int iter;
//Bienvenida al usuario
    puts("*****Método de Newton-Raphson para buscar raices*****");
//Se pide el valor inicial del método
    puts("Ingrese valor inicial del método (mayor a cero): ");
    scanf("%f",&x);
//Para evitar problemas matemáticos, se necesita que el valor inicial sea mayo que cero, por lo que
//se crea un bucle que seguirá pidiendo el valor inicial hasta que cumpla dicha condición    
    while (x<=0)
    {
        puts("Valor no válido. Por favor ingrese un número mayor a cero");
        scanf("%f",&x);
    }
//Se pide la presición de la respuesta    
    puts("Ingrese la presición de la respuesta: ");
    scanf("%f",&pres);
//Se valua la función del método
    sol = NR(x,pres,&iter);
//Si este regresa cero, es que hubo algún error en el método, por lo que se devuelve un mensaje de error
    if (sol == 0)
    {
        printf("ERROR MATEMÁTICO: Algún valor del ciclo indefine la función o su derivada. Pruebe otro valor inicial  \n");
    }else if(iter == max_iter){
//Si se alcanza el máximo de iteraciones, el método falló y se imprime un mensaje de error        
        printf("Se llegó al máximo de %d iteraciones. Reintentar con otro valor inicial",iter);
    }else{
//De lo contrario se da la solución junto al número de iteraciones hechas        
        printf("La solución es: %f, después de %d iteraciones \n",sol,iter+1);
    }
}

float f(float x){
//Evalúa la función asignada    
    float res = sqrt(x/2)-1;
    return res;
}
float df(float x){
//Evalúa la derivada de la función    
    float res = (sqrt(2/x))/4;
    return res;
}
float NR(float xi, float tol, int *itot){
//Declaramos las variables locales de respuesta, evaluación de tolerancia, y el contador    
    float res, dif;
    int i = 0;
//Evaluamos el método por primera vez    
    res = xi - f(xi)/df(xi);
//Sacamos el valor absoluto de la diferencia del resultado del método y el valor inicial.
//Este es nuestro medidor de tolerancia    
    dif = fabs(res - xi);
//Si se obtiene un valor negativo   
    if (res < 0)
    {
//Se regresa cero como indicador de que sucedió un error        
        return 0;
    }
//Si no hubo errores, se procede a seguir valuando el método hasta estar dentro de la tolerancia deseada
//o hasta un número máximo de iteraciones, fijado    
    while (dif>tol && i<max_iter)
    {
        xi = res;
        res = xi - f(xi)/df(xi);
        dif = fabs(res - xi);
//Se aumenta el contador        
        i++;
    }
//Por medio de punteros, se guarda el valor del contador para poder asignarlo a otra variable al valuar la función     
    *itot = i;
//Se devuelve el resultado del método    
    return res;
}
