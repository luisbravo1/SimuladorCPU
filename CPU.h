class CPU {
private: 
	int pc;
	int ir;
	int ac;
	int memoria[30];

public:
	CPU() {
		pc = 0;

		for(int i=20; i < 30; i++)
			memoria[i] = 0;
	}

	void leer(ifstream &archivoEntrada) {
		int i=0;
		archivoEntrada >> memoria[i];

		while(!archivoEntrada.eof()) {
			i++;
			archivoEntrada >> memoria[i];
		}
	}

	int instruccion() {
		int codigo;
		int loc;
		int valor;

      	ir = memoria[pc];
      	codigo = ir / 100;
      	loc = ir % 100;

	    switch (codigo) {
	    	case 0: //IN
	        	cout << "Ingresa un valor: ";
	            cin >> valor;
	            memoria[loc] = valor;
	            pc++;
	            break;
	        case 1: //OUT
	            cout << "Output: " << memoria[loc] << endl;
	            pc++;
	            break;
	        case 2: //LDA
	            ac = memoria[loc];
	            pc++;
	            break;
	        case 3: //STA
	            memoria[loc]=ac;
	            pc++;
	            break;
	        case 4: //ADD
	            ac = ac + memoria[loc];
	            pc++;
	            break;
	        case 5: //SUB
	            ac = ac - memoria[loc];
	            pc++;
	            break;
	        case 6: //JUMP
	            pc = loc;
	            break;
	        case 7: //BRAN
	            if(ac < 0) {
	               pc = loc;
	            } else pc++;
	            break;
	        case 8: //BRAZ
	            if (ac == 0) {
	               pc = loc;
	            } else pc++;
	            break;
	        case 9: //HALT
	            break;
      	}
      	return codigo;
	}

	void mostrar() {
		cout << "PC= " << pc << "  IR= ";
      	if (ir < 100)
        	cout << "0";
      	cout << ir << "  AC= " << ac << endl;
      	cout << "Memoria"<<endl;
      	for(int i=20; i<30; i++)
        	cout << i << ": " << memoria[i] << endl;
      	cout << endl;
	}
};