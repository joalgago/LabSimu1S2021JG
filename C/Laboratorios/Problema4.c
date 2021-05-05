/*
Autor: José García
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar: gcc Problema4.c -o Problema4
Fecha: Wed May 5 09:29:42 CST 2021
Librerias: stdio, (otras)
Resumen: Múltiples operaciones con dos matrices y una constante
Entradas: Dos matrices (A y B) y una constante c
Salidas: matA*c suma, resta y producto de matrices, detA, transpuesta de B e inversa de A
*/

//Librerias
#include <stdio.h>
//Constante del tamaño de las matrices
#define n 3
//Prototipos de funciones
void imprimir(float mat[][n]);
void multc(float mat[][n], float c);
void suma(float mat1[][n], float mat2[][n]);
void resta(float mat1[][n], float mat2[][n]);
void mult(float mat1[][n],float mat2[][n]);
void transp(float mat[][n]);
void inversa(float mat[][n], float deter);
//Declaración de matrices A y B
float matA[n][n];
float matB[n][n];

void main(){
//Declaramos la constante y la variable que almacenara el determinante de A
    float c,det;
//Bienvenida al usuario
    puts("*****Operaciones con dos matrices y una constante*****");
//Se llena la matriz A por medio de consola
    printf("Ingrese las coordenadas de la matriz A: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matA[i][j]);
        }
    }
//Se llena la matriz B por medio de consola
    printf("Ingrese las coordenadas de la matriz B: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matB[i][j]);
        }
    }
//Se ingresa la constante por medio de consola
    printf("Ingrese la constante c: ");
    scanf("%f", &c);
//Se calcula y se imprime matA*c
    printf("matA*c = \n");
    multc(matA,c);
//Se calcula y se imprime matA+matB
    printf("matA+matB = \n");
    suma(matA,matB);
//Se calcula y se imprime matA-matB
    printf("matA-matB = \n");
    resta(matA,matB);
//Se calcula y se imprime matA*matB
    printf("matA*matB = \n");
    mult(matA,matB);
//Se calcula y se imprime el determinante de A, aproimado a dos decimales
    det = matA[0][0]*(matA[1][1]*matA[2][2]-matA[1][2]*matA[2][1])
    -matA[0][1]*(matA[1][0]*matA[2][2]-matA[1][2]*matA[2][0])
    +matA[0][2]*(matA[1][0]*matA[2][1]-matA[1][1]*matA[2][0]);
    printf("El determinante de A es: %.2f \n",det);
//Se calcula y se imprime la transpuesta de B
    printf("Transpuesta de matB = \n");
    transp(matB);
//Si el determinante de A es igual a cero
    if (det == 0)
    {
//La matriz A no tiene inversa
        printf("La matriz A no tiene inversa \n");
    }else{
//En caso contrario, se calcula y se imprime la matriz inversa de A
        printf("Matriz inversa de A = \n");
        inversa(matA,det);
    }  
}

void imprimir(float mat[][n]){
    for (int i = 0; i < n; i++)
    {
//Por cada fila imprime un delimitador de inicio y final
        printf("| ");
        for (int j = 0; j < n; j++)
        {
//Imprime los valores de la matriz, separados por espacios y aproximados a dos decimales
            printf("%.2f ", mat[i][j]);
        }
        printf(" |\n");
    }
}
void multc(float mat[][n], float c){
//Declaramos una matriz auxiliar
    float res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
//La llenamos con el producto de la constante con los elementos de la matriz ingresada
            res[i][j] = c*mat[i][j];
        }
    }
//Imprimimos la matriz auxiliar
    imprimir(res);
}
void suma(float mat1[][n], float mat2[][n]){
//Declaramos una matriz auxiliar
    float res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
//La llenamos con la suma de los elementos de ambas matrices
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
//Imprimimos la matriz auxiliar
    imprimir(res);
}
void resta(float mat1[][n], float mat2[][n]){
//Declaramos una matriz auxiliar
    float res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
//La llenamos con la resta de los elementos de ambas matrices
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
//Imprimimos la matriz auxiliar
    imprimir(res);
}
void mult(float mat1[][n],float mat2[][n]){
//Declaramos una matriz auxiliar, llenandola de ceros para poder aplicar correctamente el algoritmo
    float res[n][n] = {{0,0,0},{0,0,0},{0,0,0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int  k = 0; k < n; k++)
            {
//Aplicamos el algoritmo de producto de matrices
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
//Imprimimos la matriz auxiliar
    imprimir(res);
}
void transp(float mat[][n]){
//Declaramos una matriz auxiliar
    float res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
//La llenamos con los elementos transpuestos de la matriz ingresada
            res[i][j] = mat[j][i];
        }
    }
//Imprimimos la matriz auxiliar
    imprimir(res);
}
void inversa(float mat[][n],float deter){
//Declaramos una matriz auxiliar
    float res[n][n];
//La llenamos con los cofactores de la matriz ingresada, pues son necesarios para hallar la inversa por
//medio de la adjunta de la misma. Además, hay que dividir cada componente dentro del determinante de la
//matriz original
    res[0][0] = (mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])/deter;
    res[0][1] = (mat[1][2]*mat[2][0]-mat[1][0]*mat[2][2])/deter;
    res[0][2] = (mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0])/deter;
    res[1][1] = (mat[0][0]*mat[2][2]-mat[0][2]*mat[2][0])/deter;
    res[1][0] = (mat[2][1]*mat[0][2]-mat[0][1]*mat[2][2])/deter;
    res[2][0] = (mat[0][1]*mat[1][2]-mat[1][1]*mat[0][2])/deter;
    res[2][2] = (mat[1][1]*mat[0][0]-mat[1][0]*mat[0][1])/deter;
    res[2][1] = (mat[1][0]*mat[0][2]-mat[0][0]*mat[1][2])/deter;
    res[1][2] = (mat[0][1]*mat[2][0]-mat[0][0]*mat[2][1])/deter;
//Imprimimos la transpuesta de la matriz de cofactores, calculando así la adjunta de la matriz original
//dividida dentro de su determinante, es decir, su inversa
    transp(res);
}
