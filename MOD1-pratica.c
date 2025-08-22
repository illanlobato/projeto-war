#include <stdio.h>
#include <string.h>

// Definicao da struct Territorio
// Agrupa informacoes de cada territorio: nome, cor do exercito e quantidade de tropas
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor para armazenar 5 territorios
    Territorio territorios[5];

    // Cadastro dos territorios
    printf("Cadastro de Territorios do WAR\n");
    printf("------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        // Entrada do nome do territorio
        printf("Digite o nome do territorio: ");
        scanf("%29s", territorios[i].nome);

        // Entrada da cor do exercito
        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);

        // Entrada da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibicao dos dados cadastrados
    printf("\nResumo dos Territorios Cadastrados:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-------------------\n");
    }

    return 0;
}