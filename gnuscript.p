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

plot 	"IMDB.csv" using ($6==1 ? 1 : 0) with boxes lt rgb 'black' title 'Seasons' axes x1y2 ,\
	"IMDB.csv" using 3 with linespoints lw 4 lt rgb 'red' title 'Episodes1' axes x1y1 #,\
	'shadowkey.dat' w ima

pause -1

