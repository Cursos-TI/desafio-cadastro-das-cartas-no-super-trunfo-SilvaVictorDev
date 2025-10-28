// Game Batalha Naval

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HORIZONTAL 0
#define VERTICAL 1
#define SUCESSO 1
#define FALHA 0
#define POSICAO_INVALIDA -1
#define SOBREPOSICAO -2
#define LIMITE_EXCEDIDO -3
// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}
// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    // Verifica se o navio cabe no tabuleiro
    if (orientacao == HORIZONTAL) {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return LIMITE_EXCEDIDO;
        }
        // Verifica sobreposição
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] == NAVIO) {
                return SOBREPOSICAO;
            }
        }
        // Posiciona o navio
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
    } else if (orientacao == VERTICAL) {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return LIMITE_EXCEDIDO;
        }
        // Verifica sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return SOBREPOSICAO;
            }
        }
        // Posiciona o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        return POSICAO_INVALIDA;
    }
    return SUCESSO;
}
// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    // Coordenadas iniciais dos navios
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // Navio vertical
    // Posiciona os navios no tabuleiro
    if (posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, HORIZONTAL) != SUCESSO) {
        printf("Erro ao posicionar o navio 1\n");
    }
    if (posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, VERTICAL) != SUCESSO) {
        printf("Erro ao posicionar o navio 2\n");
    }
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    return 0;
}
