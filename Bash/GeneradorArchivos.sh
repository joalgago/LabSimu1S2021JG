#!/bin/bash

#Autor: José García
#Tipo: Script de Bash
#Ejecutar: ./GeneradorArchivos.sh
#Resumen: Genera en automático la cabecera de scripts de c

#Bienvenida al usuario, indicando la funcionalidad del archivo
echo "---------- Generador de archivos de C: ----------"
#Se solicita el nombre del archivo
read -p "Ingrese el nombre del archivo (sin la extension): " nombre

#Condicional que verifica si se ingreso un nombre o no
if [ -z $nombre ]; then
#En caso no se haya ingresado nada, el programa devuelve un mensaje de error    
    echo "No ingreso un nombre válido"
#Y se sale del programa    
    exit 2
fi

#Declaracion de las variables que necesitaremos
fnombre=$nombre".c"
version=$(gcc --version | head -1) #Version del compilador
usuario=$(uname -n) #Nombre de usuario
fecha=$(date) #Fecha 

#Usamos un segundo if para verificar que no se de el nombre de un archivo que ya existe
if [ -e $fnombre ]; then
#Si el archivo ya existe, el programa devuelve un mensaje de error    
    echo "El archivo ya existe, de otro nombre"
#Y cierra el programa, sin hacer nada mas    
    exit 2
fi    

#Comenzamos a ingresar la información a nuestro nuevo archivo, agregando linea por linea
echo "/*" > $fnombre
echo "Autor:" $usuario >> $fnombre
echo "Compilador:" $version >> $fnombre
echo "Compilar: gcc" $fnombre "-o" $nombre >> $fnombre
echo "Fecha:" $fecha >> $fnombre
echo "Librerias: stdio, (otras)" >> $fnombre
echo "Resumen:" >> $fnombre
echo "Entradas:" >> $fnombre
echo "Salidas:" >> $fnombre
echo "*/" >> $fnombre

#Una vez terminado el encabezado colocamos la libreria por defecto
echo "" >> $fnombre
echo "//Librerias" >> $fnombre
echo "#include <stdio.h>" >> $fnombre

#Colocamos la funcion main por defecto en void
echo "" >> $fnombre
echo "void main(){" >> $fnombre
echo "" >> $fnombre
echo "}" >> $fnombre


