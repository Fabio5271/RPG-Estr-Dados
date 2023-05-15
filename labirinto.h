#include <stdio.h>


// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int labr_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 2, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
void l_node_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nVocê entrou em uma sala escura. Fique atento!");
    }
    if (orig == 1 && dest == 4){
        printf("\n");
    }
    if (orig == 2 && dest == 3){
        printf("\n");
    }
    if (orig == 3 && dest == 6){
        printf("\n");
    }
    if (orig == 4 && dest == 5){
        printf("\n");
    }
    if (orig == 4 && dest == 7){
        printf("\n");
    }
    if (orig == 5 && dest == 8){
        printf("\n");
    }
    printf("\nO que você irá fazer agora?\n");
}

// Define as mensagens de morte de cada caminho
void l_death_msg(int orig, int dest){
    if (orig == 2 && dest == 4){
        printf("\nTropeçou e caiu sentado na pica.");
    }
    if (orig == 2 && dest == 5){
        printf("\nEntrou na vala.");
    }
    if (orig == 7 && dest == 5){
        printf("\nComeu merda.");
    }
    if (orig == 6 && dest == 8){
        printf("\nSeu cu ardeu.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}

//Define mensagem de inicio
const char* labr_start = "\n Voce chegou na entrada do que dizem ser o grande Labirinto";

//Define mensagem de conclusão
const char* labr_end = "\nParabéns! Você encontrou a Espada da Tormenta!\n";