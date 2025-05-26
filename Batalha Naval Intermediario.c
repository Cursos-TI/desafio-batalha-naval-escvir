#include <stdio.h>

// Constantes para o tamanho do tabuleiro e símbolos
#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição é válida e não há sobreposição
int podeColocarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        // Ajuste das coordenadas baseado na direção e diagonal
        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else {
            if (direcao == 0) l += i; // vertical
            else c += i;              // horizontal
        }

        // Verifica se está fora dos limites
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO)
            return 0;

        // Verifica se já tem navio na posição
        if (tabuleiro[l][c] == NAVIO)
            return 0;
    }
    return 1;
}

// Função para posicionar navios
void colocarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else {
            if (direcao == 0) l += i;
            else c += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro);

    // Navios horizontais/verticais
    if (podeColocarNavio(tabuleiro, 0, 0, 1, 0)) // Horizontal
        colocarNavio(tabuleiro, 0, 0, 1, 0);

    if (podeColocarNavio(tabuleiro, 4, 2, 0, 0)) // Vertical
        colocarNavio(tabuleiro, 4, 2, 0, 0);

    // Navios diagonais
    if (podeColocarNavio(tabuleiro, 2, 2, 0, 1)) // Diagonal principal
        colocarNavio(tabuleiro, 2, 2, 0, 1);

    if (podeColocarNavio(tabuleiro, 0, 9, 0, 2)) // Diagonal secundária
        colocarNavio(tabuleiro, 0, 9, 0, 2);

    exibirTabuleiro(tabuleiro);

    return 0;
}