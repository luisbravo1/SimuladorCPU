
class Ensamblador {

private:
	string instruccion;
	string codigo;
	string loc;
	string maquina;

public:
	void ensamblar(istream &archivoEntrada, ostream &archivoSalida) {
		string entrada;
		int i, espacio, coma;
		string arrayInstr[] = {"IN","OUT","LDA","STA","ADD","SUB","JUMP","BRAN","BRAZ","HALT"};
		string arrayNum[] = {"0","1","2","3","4","5","6","7","8",""};

		while(!archivoEntrada.eof()) {
			getline(archivoEntrada, entrada);
			coma = entrada.find(";");
			instruccion = entrada.substr(0, coma);
			espacio = instruccion.find(" ");
			if (espacio == -1)	
				maquina = "999";
			else {
				codigo = instruccion.substr(0, espacio);
				loc = instruccion.substr(espacio+1, 2);
				i=0;
				while(codigo != arrayInstr[i])
					i++;
				maquina = arrayNum[i] + loc;
			}
			archivoSalida << maquina << endl;
		}
	}
};