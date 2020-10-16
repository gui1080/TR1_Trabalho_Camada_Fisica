sim: simulador.o CamadaFisica.o
	g++ -o sim simulador.o CamadaFisica.o

simulador.o: simulador.cpp CamadaFisica.h
	g++ -c simulador.cpp

CamadaFisica.o: CamadaFisica.cpp CamadaFisica.h
	g++ -c CamadaFisica.cpp

clean:
	rm *.o sim
