#include <stdio.h>

// Super Trunfo Game

int main(){

    // Variables declaration

    int population1, turistcAttractions1,
        population2, turistcAttractions2;
    float area1, PIB1,
          area2, PIB2;
    char state1[50], cardCode1[10], nameCity1[50], 
         state2[50], cardCode2[10], nameCity2[50];

    printf("Bem vindo ao Jogo Super Trunfo!\n");

    // Information of card1

    printf("Digite as informações da carta 1:\n");

    printf("Digite o nome do estado: ");
    fgets(state1, sizeof(state1), stdin);

    printf("Digite o código da carta: ");
    fgets(cardCode1, sizeof(cardCode1), stdin);

    printf("Digite o nome da cidade: ");
    fgets(nameCity1, sizeof(nameCity1), stdin);

    printf("Digite a população: ");
    scanf("%d", &population1);

    printf("Digite a área: ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &PIB1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &turistcAttractions1);
    getchar(); // Clear the newline character from the input buffer

    // Information of card2

    printf("\nDigite as informações da carta 2:\n");

    printf("Digite o nome do estado: ");
    fgets(state2, sizeof(state2), stdin);

    printf("Digite o código da carta: ");
    fgets(cardCode2, sizeof(cardCode2), stdin);

    printf("Digite o nome da cidade: ");
    fgets(nameCity2, sizeof(nameCity2), stdin);

    printf("Digite a população: ");
    scanf("%d", &population2);

    printf("Digite a área: ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &PIB2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &turistcAttractions2);
    getchar(); // Clear the newline character from the input buffer
    
    // Print information of card1

    printf("\nCarta 1:\n");
    printf("Estado: %s", state1);
    printf("Código: %s", cardCode1);
    printf("Nome da Cidade: %s", nameCity1);
    printf("População: %d\n", population1);
    printf("Área: %.2f km2\n", area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", turistcAttractions1);

    // Print information of card2
    
    printf("\nCarta 2:\n");
    printf("Estado: %s", state2);
    printf("Código: %s", cardCode2);
    printf("Nome da Cidade: %s", nameCity2);
    printf("População: %d\n", population2);
    printf("Área: %.2f km2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Número de Pontos Túristicos: %d\n", turistcAttractions2);


    return 0;

}