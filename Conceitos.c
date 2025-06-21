#include <stdio.h>


//Criar lista concatenada

typedef struct lista {
	int valor;
	struct lista *proximo;
} lista;

//função do tipo struct que retorna caso o ponteiro da posição desejada seja encontrado.

struct lista *procuraValor(struct lista *pLista, int valor) {


	while (pLista != (struct lista *)0) {  // NULL é mais legível que (struct lista *)0
		if (pLista->valor == valor) {
			return pLista;
		} else {
			pLista = pLista->proximo;
		}
	}
	return (struct lista *)0; // Valor não encontrado



}




int main() {

	void ponteiroTeste(int x );
	void ponteiroTestePt(int *x );

	int x = 10;
	double y = 20.3;
	char z = 'a';

	int *pX = &x;
	double *pY = &y;
	char *pZ = &z;


	int a = 10;
	int b = 40;

	int *pA = &a;
	int *pB = &b;

	printf("\n ----- Atribuicao A & B -------------- \n");
	printf("Endereco de A (pA)--> %i ---- Valor de A (a) )--> %i \n",pA, a);
	printf("Endereco de A (pA)--> %i ---- Endereco de A (&a) )--> %i \n",pA, a);
	printf("Valor de A (*pA)--> %i ---- Endereco de A (&a) )--> %i \n",*pA, a);

	printf("Valor (antes) de b --> %i \n", b);

	*pB = x;

	printf("Valor de b (TESTE)--> %i e o endereco do ponteiro (pB) )e --> %i e o valor do *pB e %i \n", b, pB, *pB);


	*pB = 500;
	printf("Valor de b (mudei para 500)--> %i e o endereco do ponteiro (pB) )e --> %i e o valor do *pB e %i \n", b, pB, *pB);

	/*

	Endereco x 6684164 - Valor x - 10
	Endereco y 6684152 - Valor y - 20.300000
	Endereco z 6684151 - Valor z - a

	*/
	printf("Endereco x %i - Valor x - %i \n",pX, *pX );
	printf("Endereco y %i - Valor y - %f \n",pY, *pY );
	printf("Endereco z %i - Valor z - %c \n",pZ, *pZ );


	int teste = 1;
	int *pTeste = &teste;

//ponteiroTeste(teste);
	ponteiroTestePt(pTeste);
	printf("\n\n valor de teste depois do ponteiro --> %i \n", teste);



	lista m1, m2, m3;
	lista *resultado, *gancho = &m1;

	m1.valor = 10;
	m2.valor = 20;
	m3.valor = 30;

	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = (struct lista *) 0;

	while(gancho != (struct lista *)0) {
		printf("\n\n\n Gancho ----> %i  valor --> %i", gancho, gancho->valor );
		gancho = gancho->proximo;
	}



	gancho = &m1;
	
	struct lista *procuraValor(struct lista *pLista, int valor) ;
	int valorEnter;
		printf("\n Digite o valor a ser pesquisado :  ");
		scanf("%i", &valorEnter);
		resultado = procuraValor(gancho,valorEnter);

		if(resultado == (struct lista *)0 ) {
			printf("\n Valor nao encontrado");
		} else {
			printf("\n Valor encontrado  --> %i e endereco de memoria -> %i ", resultado->valor, resultado);
		}

		
		
		resultado->valor = 320;
		
				printf("\n valor de M1 agora e %i", m1.valor);
				printf("\n valor de M2 agora e %i", m2.valor);
				printf("\n valor de M3 agora e %i", m3.valor);







	return 0;
}




void ponteiroTeste(int x) {
	++x;
	printf("%i <----- x ", x);
};

void ponteiroTestePt(int *px) {
	printf("%i < antes ---- x ", *px);
	++*px;
	printf("%i < agora ----- x ", *px);
};
