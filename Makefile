GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O3 
LFLAGS = -O3
LIBS = -lgsl -lm 

super: main.o super.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

data: super
	./super > data


ellipsoids.png: ellipsoids.gpl data
	$(GRAPH) ellipsoids.gpl

clean:
	rm -f *.o *~ super

veryclean: clean
	rm -f data ellipsoids.png
