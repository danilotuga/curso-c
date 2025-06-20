#include <stdio.h>
#include <math.h>
#include <string.h>

// Protótipo da função de área
float areaTerreno(float largura, float comprimento);

int main(void){

	int base , exponente;
	double potencia = pow(base,exponente);

	base = 4;
	exponente = 4;
	
	printf("A potencia de %i elevado a %i -->%.2f \n", base , exponente, potencia);
	printf("A raiz quadrada de %i e %.2f \n", base, sqrt(base));
	
	
	float area = areaTerreno((float)base, (float)exponente);
	
	printf("A area do terreno de %.i e %d e %.2f M2 \n", base, exponente, area);


char var1[20]= "Estou aqui";
char var2[20];


var1[0] ='A';
var1[1] ='B';
var1[2] ='C';
var1[3] ='D';
var1[4] ='E';
var1[5] ='F';
var1[6] ='G';



printf("Var 2 antes %s \n",var2);


strcpy(var2,var1);

printf("Var 2 depois %s \n",var2);

	
	return 0;
}
float  areaTerreno(float comprimento, float altura ){
	return comprimento * altura; 
}

