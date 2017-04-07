IN 20;	    Leer Y
LDA 20;	    AC <- Y
BRAZ 12;	Ciclo while; if Y==0, salta al final del ciclo (instrucción HALT)
IN 21;	    Leer Z
SUB 21;	    AC <- AC – Z
BRAN 08;	Si Y<Z, entonces PC<-8
OUT 20;	         Y es mayor, entonces output Y
JUMP 09;	     PC <- 9
OUT 21;	      Z es mayor, entonces output Z
IN 20;	    Leer Y de nuevo
LDA 20;	    AC <- Y
JUMP 02;	Ir al inicio del while
HALT;		Fin