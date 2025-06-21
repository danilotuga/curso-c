#include <stdio.h>
#include <string.h>

#define MAX_PROFS 3               // número total de professores
#define MAX_ALUNOS 9              // número total de alunos
#define MAX_ALUNOS_POR_PROF 4     // máximo de alunos que um professor pode ter

// Struct que representa um aluno
typedef struct {
    int codAluno;
    char nome[50];
    int idade;
} Aluno;

// Struct que representa um professor, com um vetor de ponteiros para alunos
typedef struct {
    int codProf;
    char nome[50];
    int numAlunos;                        // contador de alunos atribuídos
    Aluno *alunos[MAX_ALUNOS_POR_PROF];  // vetor de ponteiros para alunos
} Professor;

/**
 * Função que adiciona um aluno ao vetor de um professor.
 * Recebe ponteiros para o professor e o aluno.
 */
void adicionarAluno(Professor *prof, Aluno *aluno) {
	
    if (prof->numAlunos < MAX_ALUNOS_POR_PROF) {
    	
        prof->alunos[prof->numAlunos] = aluno;  // salva o ponteiro do aluno
        prof->numAlunos++;                      // incrementa o número de alunos
        
    } else {
    	
        printf("Professor %s ja tem o maximo de alunos (%d).\n", prof->nome, MAX_ALUNOS_POR_PROF);
        
    }
}

/**
 * Função que imprime os dados do professor e seus alunos.
 * Recebe ponteiro constante para não modificar os dados.
 */
void imprimirProfessor(const Professor *prof) {
	
    printf("Professor: %s (Codigo %d)\n", prof->nome, prof->codProf);
    
    printf("Alunos:\n");
    
    for (int i = 0; i < prof->numAlunos; i++) {
    	
        Aluno *a = prof->alunos[i];
        printf("  - %s (Codigo %d, Idade %d)\n", a->nome, a->codAluno, a->idade);
        
    }
    printf("\n");
}

/**
 * Função que distribui os alunos automaticamente entre os professores.
 * Usa round-robin simples: vai distribuindo um por um em ordem circular.
 */
void distribuirAlunos(Professor *profs, int numProfs, Aluno *alunos, int numAlunos) {
    int profAtual = 0;

    for (int i = 0; i < numAlunos; i++) {
        printf("Atribuindo aluno %s ao professor %s\n", alunos[i].nome, profs[profAtual].nome);
        adicionarAluno(&profs[profAtual], &alunos[i]);
        profAtual = (profAtual + 1) % numProfs;
    }
}

int main() {
    // === Criando os alunos ===
    Aluno alunos[MAX_ALUNOS] = {
        {101, "Maria", 20},
        {102, "Joao", 22},
        {103, "Ana", 19},
        {104, "Carlos", 24},
        {105, "Fernanda", 21},
        {106, "Lucas", 23},
        {107, "Juliana", 25},
        {108, "Paulo", 20},
        {109, "Beatriz", 22}
    };

    // === Criando os professores ===
    Professor profs[MAX_PROFS] = {
        {1, "Dr. Carlos", 0, {NULL}},
        {2, "Dra. Ana", 0, {NULL}},
        {3, "Dr. Pedro", 0, {NULL}}
    };

    // === Distribuir alunos entre professores ===
    distribuirAlunos(profs, MAX_PROFS, alunos, MAX_ALUNOS);

    // === Imprimir professores e seus alunos ===
    for (int i = 0; i < MAX_PROFS; i++) {
        imprimirProfessor(&profs[i]);
    }

    // === Alterar a idade de um aluno via ponteiro ===
    printf("Alterando a idade do aluno Joao para 30...\n");
    alunos[1].idade = 30;

    // Verificar se a mudança reflete nos professores (spoiler: sim!)
    printf("\n Apos alteracao:\n");
    imprimirProfessor(&profs[1]); // Dra. Ana recebeu João no round-robin

    return 0;
}
