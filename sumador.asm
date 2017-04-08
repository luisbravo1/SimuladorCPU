IN 20;		Leer A
LDA 20;		AC <- A
BRAZ 09;	Ciclo while; if y==0, salta al final del ciclo	
IN 21; 		Leer B
ADD 21;		AC <- AC + B
STA 22;		memoria[loc] <- AC
IN 20;		Leer A de nuevo
LDA 20;		AC <- A
JUMP 02;	PC <- 2
HALT;



