// Game Xadrez - Movimentos das Peças usando Recursão e Loops Aninhados


#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverTorre(casas - 1);
    printf("Baixo\n");
}
// Função recursiva para o movimento do Bispo com loops aninhados
void moverBispo(int casas) {
    for (int i = 0; i < casas; i++) { // Movimento vertical
        for (int j = 0; j < casas; j++) { // Movimento horizontal
            if (i == j) {
                printf("Diagonal Cima Direita\n");
            }
        }
    }
    for (int i = 0; i < casas; i++) { // Movimento vertical
        for (int j = 0; j < casas; j++) { // Movimento horizontal
            if (i == j) {
                printf("Diagonal Baixo Esquerda\n");
            }
        }
    }
}
// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverRainha(casas - 1);
    printf("Baixo\n");
    printf("Direita\n");
    moverRainha(casas - 1);
    printf("Esquerda\n");
}
// Função para o movimento do Cavalo com loops complexos
void moverCavalo(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            if (i == 0 && j == 1) {
                printf("Cima Cima Direita\n");
            }
        }
    }
}
int main() {
    #define casasTorre 3
    #define casasBispo 3
    #define casasRainha 3
    #define movimentosCavalo 3

    printf("###---Game Xadrez---###\n\n");

    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);
    printf("\n");

    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);
    printf("\n");

    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    printf("Movimento do Cavalo:\n");
    moverCavalo(movimentosCavalo);
    printf("\n");

    return 0;
}