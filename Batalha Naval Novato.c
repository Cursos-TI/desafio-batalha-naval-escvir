#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais para o navio horizontal (linha, coluna)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Coordenadas iniciais para o navio vertical (linha, coluna)
    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Verificação se os navios cabem no tabuleiro sem ultrapassar os limites
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO &&
        linha_vertical + TAMANHO_NAVIO <= TAMANHO) {

        // Verificação de sobreposição simples
        int sobreposicao = 0;

        // Verifica se já existe algo no caminho do navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Verifica se já existe algo no caminho do navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro com o valor 3
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
            }

            // Posiciona o navio vertical no tabuleiro com o valor 3
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            }

            // Exibe o tabuleiro completo
            printf("Tabuleiro com navios posicionados:\n\n");
            for (int i = 0; i < TAMANHO; i++) {
                for (int j = 0; j < TAMANHO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: Sobreposição de navios detectada.\n");
        }
    } else {
        printf("Erro: Um ou ambos os navios ultrapassam os limites do tabuleiro.\n");
    }

    return 0;
}