set grid
set xlabel 'Semanas'
set ylabel 'Altura'
set title 'Crecimiento semanal de planta'
set key right bottom
set xrange [-1:10]
plot 'datos.txt' t '', 0.060595*x-0.088929 t 'Ajuste'
