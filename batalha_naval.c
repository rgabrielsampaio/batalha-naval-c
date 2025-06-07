#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

void inicializaTabuleiro(int tab[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tab[i][j] = AGUA;
}

void posicionarNavio(int tab[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int k = 0; k < tamanho; k++) {
        if (direcao == 'H') tab[linha][coluna + k] = NAVIO;
        else if (direcao == 'V') tab[linha + k][coluna] = NAVIO;
    }
}

void criarHabilidadeCone(int cone[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cone[i][j] = (i == 0 && j == 2) || 
                         (i == 1 && j >= 1 && j <= 3) || 
                         (i == 2) ? 1 : 0;
}

void criarHabilidadeCruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
}

void criarHabilidadeOctaedro(int octaedro[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            octaedro[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
}

void aplicarHabilidade(int tab[TAMANHO][TAMANHO], int hab[5][5], int linhaOrigem, int colOrigem) {
    int meio = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = linhaOrigem - meio + i;
            int c = colOrigem - meio + j;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                if (hab[i][j] == 1 && tab[l][c] == AGUA)
                    tab[l][c] = AREA_AFETADA;
            }
        }
    }
}

void exibirTabuleiro(int tab[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d  ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    inicializaTabuleiro(tabuleiro);

    // Posicionar navios fixos
    posicionarNavio(tabuleiro, 1, 1, 3, 'H'); // Horizontal
    posicionarNavio(tabuleiro, 5, 8, 3, 'V'); // Vertical

    // Criar matrizes de habilidades
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Aplicar habilidades em posições fixas
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);

    // Mostrar resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}
