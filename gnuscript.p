#set terminal qt 0
#plot 	"2.csv" using 5 title 'Ay' with linespoints #, \
#	"2.csv" using 5 title 'Ay' with linespoints , \
#	"2.csv" using 6 title 'Az' with linespoints
#set terminal qt 1
#plot 	"4.csv" using 3 title 'Lat' with linespoints , \
	"4.csv" using 6 title 'Lon' with linespoints , \
	"4.csv" using 7 title 'Height' with linespoints
#set terminal qt 2
#plot 	"4.csv" every ::00::8000 using 6:3 title 'Lon vs Lat' with linespoints , \
	"4.csv" using 6 title 'Lon' with linespoints , \
	"4.csv" using 7 title 'Height' with linespoints


set terminal qt 3
clear
set datafile separator ";"
set xlabel "x"
set ylabel "y"
#set zlabel "z" 
set boxwidth 0.5
set style fill solid
plot 	"IMDB.csv" using ($6==1 ? 1 : 0) with boxes axes x1y2,\
	"IMDB.csv" using 3 with linespoints lw 8 axes x1y1


pause -1
#plot 	"Image_2_18_2018_0_0.xls" using 2:3 with linespoints #,\
	"Image_2_18_2018_0_0.xls" using 2:1 with linespoints


#splot 	"13.csv" using 1:2:3 title 'XYZ plot' with linespoints

#set terminal qt 4
#clear
#set xlabel "x"
#set ylabel "y"
#set zlabel "z" 
#splot	"11.csv" using 1:2:3 title 'XYZ plot_2' with linespoints


#plot 	"8.csv" using 1 title 'q0' with linespoints , \
	"8.csv" using 2 title 'q1' with linespoints , \
	"8.csv" using 3 title 'q2' with linespoints , \
	"8.csv" using 4 title 'q3' with linespoints
	
	
