#include <stdio.h>

#define MAX 3
#define MAXSALAS 2
#define MAX_SALA 5




int main(){
	
	struct salasEscola{
		int codSala;
		char NomeSala[50];
	};	

	struct salaAlunoProf{
		int codSalaAP;
		struct salasEscola *sala;
		struct professores *Professor;
		struct alunos *aluno;
	};
	
	struct alunos{
		int codAluno;
		char nomeAluno[45];
		int idade;
	};

	struct professores{
		int codProfessor;
		char nomeProf[45];
	};



	struct salasEscola salas[MAXSALAS] = {
															{1,"Sala Primaria"},
															{2,"Segundo Grau"}
														};

	struct alunos aluno[MAX] = {	
											{1,"Danilo",22},
											{2,"Manoel",32},
											{3,"Zezinho",42}
										};
		
	
	struct professores prof[2] = {
															{1,"Marieta Severo"},
															{2,"Conde Dracula"}
														};	


	struct salaAlunoProf SalaAP[MAX_SALA] = {
															{1,{1,"Sala Primaria"},{1,"Marieta Severo"},{1,"Danilo",22}},
															{2},
															{3}
															
														};	
	
/*
		int codSalaAP;
		struct codSala *sala;
		struct professores *Professor;
		struct alunos *aluno;
*/
	
	for(int i = 0; i <= 2 ; i++){
		
		printf("\n Cod. Aluno = %i ", aluno[i].codAluno);
		printf("\n Nom. Aluno = %s ", aluno[i].nomeAluno);
		printf("\n Idade Aluno = %i \n\n", aluno[i].idade);				
	}	
	
	
	return 0;
}