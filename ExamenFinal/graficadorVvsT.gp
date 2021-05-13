set terminal jpeg
set output "VvsT.jpg"
set grid
set xlabel "t"
set ylabel "v"
set title "Cohetes, v vs t"
plot "Ah_Mun" using 3:4 t 'Ah Mun', "Ahau_Kin" using 3:4 t 'Ahau Kin', "Chac" using 3:4 t 'Chac'