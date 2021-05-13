set terminal jpeg
set output "VvsY.jpg"
set grid
set xlabel "v"
set ylabel "y"
set title "Cohetes, v vs y"
plot "Ah_Mun" using 5:6 t 'Ah Mun', "Ahau_Kin" using 5:6 t 'Ahau Kin', "Chac" using 5:6 t 'Chac'