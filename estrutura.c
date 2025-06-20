#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_FRUTAS 3


int main(){

 typedef  struct {
	char nomefruta[20];
	int valor;
	struct lista *proximo;
} Frutas ;

 Frutas frutas[MAX_FRUTAS] , *ponteiro;

strcpy(frutas[0].nomefruta, "Banana Prata");
frutas[0].valor= 10;
strcpy(frutas[1].nomefruta, "Banana Nanica");
frutas[1].valor= 20;
strcpy(frutas[2].nomefruta, "Banana da Terra");
frutas[2].valor= 30;

// Fazendo o ponteiro apontar para frutas[1]
ponteiro = &frutas[0];

strcpy(ponteiro->nomefruta, "Banana Nanicax");
printf("ponteiro com  ponteiro->nomefruta %s  -- ponteiro -> %p \n\n\n", ponteiro->nomefruta, *ponteiro->nomefruta);



//*frutas->nomefruta = "000000000065FD90";

printf("\n Estou no  %p enderecos %s e valor %s \n",*frutas, ponteiro, ponteiro->nomefruta );


for(int i = 0; i < MAX_FRUTAS; i++){

		printf("\nA fruta e %s  e end %p\n", frutas[i].nomefruta, ponteiro);
		
		if(frutas[i].nomefruta != NULL){
		}
		
}

	
	
	return 0;
}