#include <stdio.h>

int main() {
    int i, j;

    // Cria o tabuleiro 10x10 e enche com água
    int tabuleiro[10][10];
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === NAVIO 1 (horizontal) ===
    int linha_navio1 = 2;
    int coluna_navio1 = 4;
    int tamanho_navio1 = 3;

    if (coluna_navio1 + tamanho_navio1 <= 10) {
        for (j = coluna_navio1; j < coluna_navio1 + tamanho_navio1; j++) {
            tabuleiro[linha_navio1][j] = 3;
        }
    } else {
        printf("Navio 1 não cabe no tabuleiro!\n");
    }

    // === NAVIO 2 (vertical) ===
    int linha_navio2 = 1;
    int coluna_navio2 = 2;
    int tamanho_navio2 = 3;
    int pode_colocar = 1; // assume que pode, até provar o contrário

    if (linha_navio2 + tamanho_navio2 <= 10) {
        for (i = linha_navio2; i < linha_navio2 + tamanho_navio2; i++) {
            if (tabuleiro[i][coluna_navio2] != 0) {
                pode_colocar = 0; // já tem navio nessa posição
                break;
            }
        }

        if (pode_colocar) {
            for (i = linha_navio2; i < linha_navio2 + tamanho_navio2; i++) {
                tabuleiro[i][coluna_navio2] = 3;
            }
        } else {
            printf("Navio 2 não pode ser colocado: colisão com outro navio.\n");
        }

    } else {
        printf("Navio 2 não cabe no tabuleiro!\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro final:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
