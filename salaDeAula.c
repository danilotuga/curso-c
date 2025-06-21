/**
 * @file main.c
 * @brief Programa para gerenciar turmas com relações muitos-para-muitos entre salas, professores e alunos.
 *
 * O código define structs para Sala, Aluno e Professor,
 * além da struct Turma, que conecta esses elementos usando ponteiros.
 * Permite múltiplos professores e alunos por turma, e vários
 * professores/turmas por aluno.
 *
 * @author ChatGPT
 * @date 2025-06-???
 */

#include <stdio.h>
#include <string.h>

#define MAX_SALAS          2  /**< Número de salas disponíveis */
#define MAX_PROFS          5  /**< Número total de professores */
#define MAX_ALUNOS        10  /**< Número total de alunos */
#define MAX_TURMAS         3  /**< Número total de turmas */
#define MAX_ALUNOS_TURMA   4  /**< Capacidade máxima de alunos por turma */
#define MAX_PROFS_TURMA    2  /**< Máximo de professores por turma */

/// Estrutura representando uma sala física
typedef struct {
    int codSala;            /**< Código único da sala */
    char nome[50];          /**< Nome descritivo da sala */
    int capacidade;         /**< Capacidade máxima de alunos */
} Sala;

/// Estrutura que armazena dados de um aluno
typedef struct Turma Turma;  // Forward
typedef struct {
    int codAluno;           /**< Código único do aluno */
    char nome[45];          /**< Nome completo do aluno */
    int idade;              /**< Idade do aluno */
    int numTurmas;          /**< Quantas turmas o aluno participa */
    Turma *turmas[MAX_TURMAS]; /**< Ponteiros para turmas associadas */
} Aluno;

/// Estrutura que armazena dados de um professor
typedef struct {
    int codProf;            /**< Código único do professor */
    char nome[45];          /**< Nome completo do professor */
    char materia[30];       /**< Matéria que o professor ensina */
    int numTurmas;          /**< Quantas turmas o professor leciona */
    Turma *turmas[MAX_TURMAS]; /**< Ponteiros para turmas associadas */
} Professor;

/// Estrutura representando uma turma, contendo múltiplos alunos e professores
struct Turma {
    int codTurma;                  /**< Código identificador da turma */
    Sala *sala;                   /**< Ponteiro para a sala onde a turma ocorre */
    int numAlunos;                /**< Contador de alunos na turma */
    Aluno *alunos[MAX_ALUNOS_TURMA]; /**< Ponteiros para alunos na turma */
    int numProfs;                 /**< Contador de professores na turma */
    Professor *profs[MAX_PROFS_TURMA]; /**< Ponteiros para professores da turma */
};

/**
 * @brief Função principal que monta e imprime a estrutura escolar.
 * 
 * A função preenche dados de salas, alunos e professores, cria turmas,
 * associa múltiplos alunos/professores por turma e imprime a configuração.
 * 
 * @return Código de saída (0 = sucesso)
 */
int main(void) {
    // Inicialização de salas
    Sala salas[MAX_SALAS] = {
        {1, "Sala Primaria", 3},
        {2, "Segundo Grau", 2}
    };

    // Inicialização de alunos
    Aluno alunos[MAX_ALUNOS] = {
        {1, "Danilo Silva", 22, 0, {NULL}},
        {2, "Manoel Pereira", 32, 0, {NULL}},
        {3, "Zezinho Costa", 42, 0, {NULL}},
        {4, "Gabriel Oliveira", 19, 0, {NULL}},
        {5, "Beatriz Santos", 25, 0, {NULL}},
        {6, "Lucas Ferreira", 28, 0, {NULL}},
        {7, "Mariana Almeida", 30, 0, {NULL}},
        {8, "Joaquim Rodrigues", 35, 0, {NULL}},
        {9, "Carolina Martins", 27, 0, {NULL}},
        {10,"Fernando Souza", 21, 0, {NULL}}
    };

    // Inicialização de professores
    Professor profs[MAX_PROFS] = {
        {1, "Marieta Severo",    "Matematica", 0, {NULL}},
        {2, "Conde Dracula",     "Historia",   0, {NULL}},
        {3, "Jose Silva",        "Portugues",  0, {NULL}},
        {4, "Ana Pereira",       "Ciencias",   0, {NULL}},
        {5, "Carlos Goncalves",  "Geografia",  0, {NULL}}
    };

    // Criação das turmas
    Turma turmas[MAX_TURMAS] = {0};
    for (int i = 0; i < MAX_TURMAS; i++) {
        turmas[i].codTurma = i + 1;
        turmas[i].sala = &salas[i % MAX_SALAS];
        turmas[i].numAlunos = 0;
        turmas[i].numProfs = 0;
    }

    // Associação de alunos e professores às turmas
    for (int i = 0; i < MAX_TURMAS; i++) {
        // Alunos
        for (int j = 0; j < MAX_ALUNOS_TURMA; j++) {
            int idxA = i * MAX_ALUNOS_TURMA + j;
            if (idxA < MAX_ALUNOS) {
                Turma *t = &turmas[i];
                Aluno *a = &alunos[idxA];
                t->alunos[t->numAlunos++] = a;
                a->turmas[a->numTurmas++] = t;
            }
        }
        // Professores
        for (int k = 0; k < MAX_PROFS_TURMA; k++) {
            int idxP = (i * MAX_PROFS_TURMA + k) % MAX_PROFS;
            Turma *t = &turmas[i];
            Professor *p = &profs[idxP];
            t->profs[t->numProfs++] = p;
            p->turmas[p->numTurmas++] = t;
        }
    }

    // Impressão da estrutura montada
    for (int i = 0; i < MAX_TURMAS; i++) {
        Turma *t = &turmas[i];
        printf("\n=== Turma %d (Sala: %s, Capacidade: %d) ===\n",
               t->codTurma, t->sala->nome, t->sala->capacidade);
        printf("Professores (%d):\n", t->numProfs);
        for (int j = 0; j < t->numProfs; j++) {
            Professor *p = t->profs[j];
            printf("  - %s (cod %d) — Materia: %s\n",
                   p->nome, p->codProf, p->materia);
        }
        printf("Alunos (%d):\n", t->numAlunos);
        for (int j = 0; j < t->numAlunos; j++) {
            Aluno *a = t->alunos[j];
            printf("  - %s (cod %d, idade %d)\n",
                   a->nome, a->codAluno, a->idade);
        }
    }

    return 0;
}
