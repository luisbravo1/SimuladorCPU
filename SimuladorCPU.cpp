#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Ensamblador.h"
#include "CPU.h"

int main() {
	string archivo;
	string archivoIN;
	string archivoOUT;
	string continuar;
	int codigo = 0;

	Ensamblador ensamblador;
	CPU cpu;

	ifstream archivoEntrada;
	ofstream archivoSalida;

	cout << "Nombre del archivo: ";
	cin >> archivo;
	cout << endl;

	archivoIN = archivo + ".asm";
	archivoOUT = archivo + ".obj";

	archivoEntrada.open(archivoIN);
	archivoSalida.open(archivoOUT);
	ensamblador.ensamblar(archivoEntrada, archivoSalida);
	archivoEntrada.close();
	archivoSalida.close();

	archivoEntrada.open(archivoOUT);
	cpu.leer(archivoEntrada);
	archivoEntrada.close();

	while(codigo != 9) {
		codigo = cpu.instruccion();
		cpu.mostrar();
		cout << "Presiona una tecla para continuar" << endl;
		getline(cin, continuar);
	}

	return 0;
}