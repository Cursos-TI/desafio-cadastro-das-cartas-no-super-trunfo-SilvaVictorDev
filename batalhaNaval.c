/*
    Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.
     
    Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
    Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
     
    Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
    Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.

Requisitos funcionais

    O programa deve receber as coordenadas iniciais (linha e coluna) de cada navio como entrada (pode ser definido diretamente no código).
     
    O programa deve validar se as coordenadas e o tamanho dos navios são válidos dentro dos limites do tabuleiro.
     
    O programa deve garantir que os navios não se sobreponham.
     
    O programa deve exibir o tabuleiro no console com os navios posicionados corretamente.

Requisitos não funcionais

    Performance: O programa deve executar de forma eficiente, sem causar atrasos perceptíveis.
     
    Documentação: O código deve ser bem documentado, com comentários claros explicando a lógica e o propósito de cada parte do programa. Utilize comentários para explicar a função de cada variável, loop e bloco de código.
     
    Legibilidade: O código deve ser escrito de forma clara, organizada e fácil de entender, com nomes de variáveis descritivos e indentação consistente.

Simplificações para o nível básico

    O tamanho do tabuleiro e dos navios é fixo (10x10).
     
    Os navios têm tamanho fixo igual a 3.
     
    As coordenadas dos navios são definidas diretamente no código, sem input do usuário.
     
    Não é necessário implementar a lógica do jogo (ataques, acertos, etc.) neste nível.
     
    A validação de sobreposição de navios pode ser simplificada.
*/

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
