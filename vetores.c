#include <stdio.h>

#define MAX 10
#define ENTRADAS 5

//Leia 10 números inteiros em um vetor e imprima o maior valor.
int main(){	

	int valores[MAX] = {77,2,3,4,35,87,7,18,9,101};
	int valorMaior;
	
	
	for(int i = 0; i < MAX ;i++ ){
		
		if( valores[i] > valorMaior){

			valorMaior = valores[i];
		}
				
		
	}
	
	
	printf("O menor valor do vetor e -> %i \n", valorMaior);
	

//Leia 20 inteiros e exiba quantos valores são pares.
int inteiros[ENTRADAS], valor, qtdPar;
printf("======== Informe %i numeros inteiros ========\n ",ENTRADAS);
for(int i=0; i < ENTRADAS; i++){
	
	printf("\nInforme registro nro %i--> ",i+1);
	scanf("%i", &valor);
	
	if(valor%2 == 0){
		qtdPar++;	
	}
}


printf("Temos %i numeros pares ", qtdPar);

return 0;
}

