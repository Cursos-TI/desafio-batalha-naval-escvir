#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Inicializa o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coloca alguns navios fixos
    tabuleiro[2][2] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[7][7] = NAVIO;
}

// Imprime o tabuleiro com cabeçalho de colunas
void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("  ");
    for (int j = 0; j < TAM_TAB; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAM_TAB; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Constrói um cone apontando para baixo (triângulo)
void construirCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i <= TAM_HAB / 2 && j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Constrói uma cruz com centro no meio
void construirCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Constrói um octaedro (losango)
void construirOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Aplica a matriz de habilidade sobre o tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int centroX, int centroY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabX = centroX - TAM_HAB / 2 + i;
            int tabY = centroY - TAM_HAB / 2 + j;

            if (tabX >= 0 && tabX < TAM_TAB && tabY >= 0 && tabY < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[tabX][tabY] == AGUA) {
                    tabuleiro[tabX][tabY] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica as três habilidades em posições distintas
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // topo esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // meio
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // embaixo

    imprimirTabuleiro(tabuleiro);

    return 0;
}