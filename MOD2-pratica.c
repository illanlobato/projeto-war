#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de um territorio
typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

// Função para exibir o mapa
void exibirMapa(Territorio* territorios, int n) {
    printf("\n==============================\n");
    printf("   MAPA DO JOGO - ESTADO ATUAL\n");
    printf("==============================\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s (Exercito %s, Tropas: %d)\n", 
            i+1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

// Função para resolver batalha
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("Atacante %s rolou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor %s rolou: %d\n", defensor->nome, dadoDefensor);

    if(dadoAtacante > dadoDefensor) {
        printf(">>> VITORIA DO ATAQUE! O territorio %s foi conquistado!\n", defensor->nome);

        // defensor muda de dono
        snprintf(defensor->cor, 20, "%s", atacante->cor);

        // defensor recebe metade das tropas do atacante
        defensor->tropas = atacante->tropas / 2;

        // atacante perde metade das tropas que transferiu
        atacante->tropas = atacante->tropas - defensor->tropas;
        if(atacante->tropas < 1) atacante->tropas = 1; // pelo menos 1 fica

    } else {
        atacante->tropas--;
        printf(">>> DEFESA BEM-SUCEDIDA! O atacante %s perdeu 1 tropa.\n", atacante->nome);
    }
}

// Função para liberar memoria
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL));

    int n;
    printf("==============================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL\n");
    printf("==============================\n");

    printf("Digite o numero de territorios: ");
    scanf("%d", &n);

    // aloca memoria dinamicamente
    Territorio* territorios = (Territorio*) calloc(n, sizeof(Territorio));
    if(territorios == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro inicial
    for(int i=0; i<n; i++) {
        printf("\n--- Cadastrando Territorio %d ---\n", i+1);

        printf("Nome do Territorio: ");
        scanf(" %[^\n]", territorios[i].nome);

        printf("Cor do Exercito: ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    int atacante, defensor;

    // Loop principal
    while(1) {
        exibirMapa(territorios, n);

        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", n);
        scanf("%d", &atacante);

        if(atacante == 0) {
            printf("\nJogo encerrado. Liberando memoria...\n");
            liberarMemoria(territorios);
            break;
        }

        printf("Escolha o territorio defensor (1 a %d): ", n);
        scanf("%d", &defensor);

        if(atacante < 1 || atacante > n || defensor < 1 || defensor > n || atacante == defensor) {
            printf(">>> Escolha invalida!\n");
            continue;
        }

        // impede atacar o proprio exercito
        if(strcmp(territorios[atacante-1].cor, territorios[defensor-1].cor) == 0) {
            printf(">>> Nao e permitido atacar um territorio do mesmo exercito!\n");
            continue;
        }

        atacar(&territorios[atacante-1], &territorios[defensor-1]);

        // Pausa antes do proximo turno
        printf("\nPressione ENTER para continuar...");
        getchar(); // consome enter
        getchar(); // espera apertar enter
    }

    return 0;
}