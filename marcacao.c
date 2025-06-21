#include <stdio.h>
#include <string.h>

typedef struct {
    int codPess;
    char nomePess[50];
} Pessoa;

typedef struct {
    int hora;
    int minuto;
    int segundo;
    Pessoa *pessoa;  
} Marcacao;

int main() {
    Pessoa pessoas[3];

    pessoas[0].codPess = 1;
    strcpy(pessoas[0].nomePess, "Danilo Cavalcante");

    pessoas[1].codPess = 2;
    strcpy(pessoas[1].nomePess, "Roger o Guitarrista");

    pessoas[2].codPess = 3;
    strcpy(pessoas[2].nomePess, "Manuel o Cantor");

    Marcacao m1, *ptAle; //Criei este ponteiro só para testar outra forma de alterar a pessoa da marcação
    
	ptAle = &m1; // como o ponteiro criado por si não realiza nada, foi preciso que ele recebesse a referência de qual endereço o ponteiro irá modificar.
    
    m1.hora = 5;
    m1.minuto = 22;
    m1.segundo = 33;
    m1.pessoa = &pessoas[0]; 

	ptAle->pessoa = &pessoas[1]; //alterando pessoa da marcacao por meio do ponteiro
	
    printf("Marcacao: %02d:%02d:%02d\n", m1.hora, m1.minuto, m1.segundo);
    printf("Pessoa associada: %s (Codigo %d)\n", m1.pessoa->nomePess, m1.pessoa->codPess);


    m1.hora = 22;
    m1.pessoa = &pessoas[2]; //alterando pessoa da marcacao diretamente na struct
    
    strcpy(pessoas[2].nomePess, "Manuel o Cantor Boemio"); 
    
    
    printf("Marcacao alterada: %02d:%02d:%02d\n", m1.hora, m1.minuto, m1.segundo);
    printf("Pessoa associada: %s (Codigo %d)\n", m1.pessoa->nomePess, m1.pessoa->codPess);

    
    
    return 0;
}
