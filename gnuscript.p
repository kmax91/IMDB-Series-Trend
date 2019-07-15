set terminal qt 3
clear

set datafile separator ";"
set xlabel "x"
set ylabel "y"

set boxwidth 0.1
set style fill solid
set title ARG1



xl=0; xh=100; yl=0; yh=10;
eps=0.01;
rx=0.6; ry=0.8; kw=0.35; kh=0.15
lh=0.06; al=0.1

#set object 1 rect from graph rx,ry rto kw,kh fc rgb "#aaaaaa" fs solid 1.0 front lw 0
#set object 2 rect from graph rx-eps,ry+eps rto kw,kh front fs empty
#set arrow from graph rx, ry+2*lh rto al, 0 lt 1 lw 1.5 nohead front
#set arrow from graph rx, ry+lh rto al, 0 lt 3 lw 1.5 nohead front 

#set table 'shadowkey.dat'
#splot [xl:xh] [yl:yh] x/(xh-xl)
#unset table


set palette defined (0 "#8888ff", 10 "#ffffff")

##Modify this to add Labels marking Seasons (7/15/2019)
#LABEL = "Label in a box"
#box_y = 8.0
#set obj 10 rect at 0,box_y size char strlen(LABEL), char 1 
#set obj 10 fillstyle empty border -1 front
#set label 10 at 0,box_y LABEL front center
#set obj 9 rect from -1,box_y to 0,box_y fc lt -1


#set obj 20 rect from graph 0, graph 0 to graph 1, graph 1 fs solid 0.15 fc rgb "#FFD700" behind

plot 	"IMDB.csv" using ($6==1 ? 1 : 0) with boxes lt rgb 'black' title 'Seasons' axes x1y2 ,\
	"IMDB.csv" using 3 with linespoints lw 4 lt rgb 'red' title 'Episodes1' axes x1y1 #,\
	'shadowkey.dat' w ima



pause -1

