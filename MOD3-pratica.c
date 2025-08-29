// ================================
// MOD3-pratica.c  (versao ASCII)
// ================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD_EXERCITOS 5
#define MAX_NOME 32
#define MAX_COR  24

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int  tropas;
} Exercito;

static void limpaBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

static void leLinha(char *dest, size_t tam) {
    if (fgets(dest, (int)tam, stdin)) {
        size_t n = strlen(dest);
        if (n > 0 && dest[n-1] == '\n') dest[n-1] = '\0';
    } else {
        dest[0] = '\0';
    }
}

int main(void) {
    Exercito exercitos[QTD_EXERCITOS];

    printf("=== Cadastro dos %d continentes/exercitos ===\n\n", QTD_EXERCITOS);
    for (int i = 0; i < QTD_EXERCITOS; i++) {
        printf("Exercito %d\n", i + 1);

        printf("Nome do continente: ");
        leLinha(exercitos[i].nome, sizeof(exercitos[i].nome));

        printf("Cor do exercito: ");
        leLinha(exercitos[i].cor, sizeof(exercitos[i].cor));

        printf("Tropas: ");
        while (scanf("%d", &exercitos[i].tropas) != 1) {
            limpaBuffer();
            printf("Valor invalido. Digite um numero para Tropas: ");
        }
        limpaBuffer();
        printf("\n");
    }

    // Mapa do mundo
    printf("\n========== MAPA DO MUNDO ==========\n");
    for (int i = 0; i < QTD_EXERCITOS; i++) {
        printf("%d. %-10s (Exercito: %-10s , Tropas: %d)\n",
               i + 1, exercitos[i].nome, exercitos[i].cor, exercitos[i].tropas);
    }
    printf("===================================\n");

    // Missao
    srand((unsigned)time(NULL));
    int jogador = rand() % QTD_EXERCITOS;
    int alvo;
    do { alvo = rand() % QTD_EXERCITOS; } while (alvo == jogador);

    printf("\n--- SUA MISSAO (Exercito %s) ---\n", exercitos[jogador].cor);
    printf("Destruir o exercito %s.\n\n", exercitos[alvo].cor);

    // Menu
    int opcao;
    do {
        printf("--- MENU DE ACOES ---\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha sua acao: ");
        if (scanf("%d", &opcao) != 1) { limpaBuffer(); opcao = -1; }

        switch (opcao) {
            case 1:
                printf("Voce atacou um exercito! (simulacao)\n\n");
                break;
            case 2:
                printf("Sua missao: Destruir o exercito %s.\n\n", exercitos[alvo].cor);
                break;
            case 0:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n\n");
        }
    } while (opcao != 0);

    printf("Memoria liberada com sucesso.\n");
    return 0;
}