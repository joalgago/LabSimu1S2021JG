/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Final.c -o Final -lm
Fecha: Thu May 13 10:30:04 CST 2021
Librerias: stdio, (otras)
Resumen: Analizar trayectorias de tres cohetes
Entradas: Diversos datos sobre cohetes
Salidas: Tablas de datos de posición, tiempo y velocidad, además de otros datos calculados
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Se define la estructura que almacenara las características de los cohetes 
typedef struct
{
    float E;
    float TSFC;
    float CD;
    float A;
    float M;
    float MC;
} cohetes;
//Se definen los elementos de la estructura
cohetes uno;
cohetes dos;
cohetes tres;
//Prototipos de funciones
float masacombustible(cohetes prueba, float t);
float masa(float m, cohetes prueba);
float gravedad(float y);
float rho(float y);
float friccion(float y, float v, cohetes prueba);
float aceleracion(cohetes prueba, float y, float m,float v);
void calculo(cohetes prueba, float v0, float y0, float dt, char* nombre);

void main(){
//Se ingresan los valores del primer cohete
    uno.E = 3*pow(10,7);
    uno.TSFC = 3.248*pow(10,-4);
    uno.CD = 61.27;
    uno.A = 201.06;
    uno.M = 1.1*pow(10,5);
    uno.MC = 1.5*pow(10,6);
//Se ingresan los valores del segundo cohete
    dos.E = 2.7*pow(10,7);
    dos.TSFC = 2.248*pow(10,-4);
    dos.CD = 61.27;
    dos.A = 201.06;
    dos.M = 1.1*pow(10,5);
    dos.MC = 1.5*pow(10,6);
//Se ingresan los valores del tercer cohete
    tres.E = 2.5*pow(10,7);
    tres.TSFC = 2.248*pow(10,-4);
    tres.CD = 70.25;
    tres.A = 215.00;
    tres.M = 1.8*pow(10,5);
    tres.MC = 2.1*pow(10,6);
//Se hacen los calculos para los tres cohetes 
    printf("Nombre: Ah Mun \n");
    calculo(uno,0.0,0.67,0.1,"Ah_Mun");
    printf("\n");
    printf("Nombre: Ahau Kin \n");
    calculo(dos,0.0,0.67,0.1,"Ahau_Kin");
    printf("\n");
    printf("Nombre: Chac \n");
    calculo(tres,0.0,0.67,0.1,"Chac");
}
//Se calcula la masa del combustible respecto al tiempo luego de resolver la ecuación diferencial
//propuesta por el problema
float masacombustible(cohetes prueba, float t){
    float res = -1*prueba.TSFC*prueba.E*t + prueba.MC;
    return res;
}
//Se calcula la masa del cohete juntando el propulsor y el combustible
float masa(float m, cohetes prueba){
    float res;
    res = prueba.M + m;
    return res;
}
//Se calcula la gravedad respecto a la altura
float gravedad(float y){
//Se declaran todas las variables a usar
    float G=6.693*pow(10,-11),M=5.9736*pow(10,24),R=6.378*pow(10,6);
    float res = (G*M)/pow(R+y,2);
    return res;
}
//Se calcula la densidad del aire respecto a la altura
float rho(float y){
//Se declaran las constantes a usar
    float P=101325,R=287.06,T=288.15,L=6.5*pow(10,-3),g=9.81;
//Se declara y asigna un valor a la altura límite, y la variable que almacenara el resultado
    float res, ymax;
    ymax = T/L;
//Si se supera la altura propuesta
    if (y > ymax){
//La densidad es cero
        res = 0;
    }else{
//De lo contrario se hace el cálculo
        res = (P/R*T)*pow(1-(L*y)/T,g/(R*L));
    }
    return res;
}
//Se calcula la fricción basandonos en la densidad
float friccion(float y, float v, cohetes prueba){
//Se declara la variable a usar y se le asigna un valor con la función antes declarada
    float dens = rho(y);
    float res = 0.5*dens*prueba.CD*prueba.A*v*fabs(v);
    return res;
}
//Se hace el cálculo de la fricción
float aceleracion(cohetes prueba, float y, float m, float v){
//Se declaran las variables a usar y se les asignan valores con las funciones antes declaradas
    float ac,g,mc,f;
    g=gravedad(y);
    mc=masa(m,prueba);
    f=friccion(y,v,prueba);
//Si la masa del cohete es menor a la masa del propulsor (es decir, se acabó el combustible y este ahora
//resta a la masa del propulsor en vez de sumarle)
    if (mc < prueba.M){
//No hay empuje
        ac = -1*((f + mc*g)/mc);
    }else{
//De lo contrario sí hay empuje
        ac = (prueba.E - f - mc*g)/mc;
    }
    return ac;
}
void calculo(cohetes prueba, float v0, float y0, float dt, char* nombre){
//Se declaran las variables de distancia, tiempo, velocidad (y las inicia), aceleracion y masa del 
//combustible
    float mt,t=0,y=y0,v=v0,a;
//Se incluyen dos banderas para el combustible y la altura máxima
    int i = 0, j = 0;
//Se imprimen los datos del choete
    printf("Empuje del cohete = %.2e \n",prueba.E);
    printf("Consumo específico del empuje = %.2e \n",prueba.TSFC);
    printf("Coeficiente de forma = %.2f \n",prueba.CD);
    printf("Sección transversal = %.2f \n",prueba.A);
    printf("Masa del propulsor = %.2e \n",prueba.M);
    printf("Masa inicial del combustible = %.2e \n",prueba.MC);
//Se abre el archivo de texto en modo escritura, para ingresar los datos a graficar
    FILE* pf;
    pf = fopen(nombre,"wt");
//Mientras el cohete no toque el suelo
    while (y > 0){
//Ingresamos los datos a nuestro archivo de texto
        fprintf(pf,"%.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \n",t,y,t,v,v,y);
//Se calcula la masa del combustible
        mt = masacombustible(prueba,t);
//Cuando la masa es negativa
        if (mt <= 0){
//Se aumenta el contador
            i++;
        }
//La primera vez que se aumenta el contador este queda en 1, y es aquí donde el combustible se agotó
        if (i == 1){
//Imprime el mensaje del combustible agotado
            printf("El combustible se agota en %.2f segundos \n",t);
        }
//Se calcula la aceleración
        a = aceleracion(prueba,y,mt,v);
//Se aumentan la velocidad, la altura y el tiempo usando la separación indicada
        t += dt;
        v += a*dt;
//Si la velocidad se hace cero, se alcanzó la altura máxima
        if (v < 0){
//Se aumenta el contador
            j++;
        }
//La primera vez que se aumenta el contador este queda en 1, y es aquí donde se alcanzó la altura máxima
        if (j == 1){
//Imprime el mensaje de la altura máxima
            printf("La altura máxima es %.2f metros \n",y);
        }
        y += v*dt;
    }
//Ingresamos los últimos datos a nuestro archivo de texto
    fprintf(pf,"%.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \n",t,y,t,v,v,y);
//Cerramos nuestro archivo de texto
    fclose(pf);
//Una vez que se sale del ciclo ya se alcanzó el suelo, por lo que se imprime el tiempo en el que el ciclo
//se quedó como el tiempo del impacto, en minutos
    printf("El cohete impacta el suelo en %.2f minutos \n",t/60);
}
