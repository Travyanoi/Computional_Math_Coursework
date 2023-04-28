.PHONY: all run clean

.all: run

run:
	mkdir -p pdf Data
	gcc -Wall -o main SEIR_D.c
	./main
	gnuplot -persists gnuplot/D.gp
	gnuplot -persists gnuplot/E.gp
	gnuplot -persists gnuplot/I.gp
	gnuplot -persists gnuplot/N.gp
	gnuplot -persists gnuplot/R.gp
	gnuplot -persists gnuplot/S.gp
clean:
	rm main
	rm -r Data pdf