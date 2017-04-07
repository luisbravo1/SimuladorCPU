#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Ensamblador.h"

int main() {
	string archivo;
	string archivoIN;
	string archivoOUT;

	Ensamblador ensamblador;

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

	return 0;
}