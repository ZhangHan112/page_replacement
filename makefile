all: page

page: ref_str.o algo.o main.o
	g++ -ggdb -O3 -o page ref_str.o algo.o main.o

ref_str.o:
	g++ -ggdb -O3 -c ref_str.cpp

algo.o:
	g++ -ggdb -O3 -c algo.cpp

main.o: main.cpp
	g++ -ggdb -O3 -c main.cpp
	

plot0: 
	gnuplot random.gp locality.gp

plot1: 
	gnuplot locality.gp

plot2: 
	gnuplot my_ref_str.gp
	
dep:
	echo "Do nothing"

clean:
	rm -f page *.o *.dat *.txt 

cleanDat:
	rm -f *.dat