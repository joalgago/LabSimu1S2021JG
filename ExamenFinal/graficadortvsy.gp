set terminal jpeg
set output "yvst.jpg"
set grid
set xlabel "t"
set yrange [-1:1]
set ylabel "y"
set title "Cohetes, y vs t"
plot "Ah_Mun" using 1:2 t 'Ah Mun', "Ahau_Kin" using 1:2 t 'Ahau Kin', "Chac" using 1:2 t 'Chac'