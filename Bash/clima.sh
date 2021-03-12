#!/bin/bash

#Autor: José García
#Tipo: Script de Bash
#Ejecutar: ./clima.sh
#Resumen: Muestra el clima del día en Guatemala

#Obtiene la información de la página y la guarda en un archivo con el nombre archivo
curl -o archivo wttr.in/Guatemala
#Lee las primeras siete líneas del archivo que acabamos de crear
head -7 archivo
#Imprime un salto de línea
echo ""
#Borra el archivo creado con la información de la página
rm archivo

