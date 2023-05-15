#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int drag_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
int d_node_msg(int orig, int dest){
    if (orig == 1 && dest == 3){
        printf("\nTu olha e tem um dragão.");
    }
    if (orig == 3 && dest == 5){
        printf("\nSala");
    }
    if (orig == 2 && dest == 4){
        printf("\nSala");
    }
    if (orig == 3 && dest == 5){
        printf("\nSala");
    }
    if (orig == 5 && dest == 7){
        printf("\nSala");
    }
    if (orig == 7 && dest == 8){
        printf("\nSala");
    }
    printf("\nOque você irá fazer agora?\n");
}

// Mostra as mensagens de morte de cada caminho
int d_death_msg(int orig, int dest){
    if (orig == 5 && dest == 8){
        printf("O dragão te partiu ao meio!\n");
    }
    if (orig == 6 && dest == 8){
        printf("O dragão te engoliu!\n");
    }
    printf("\nVocê escolheu o caminho errado. O dragão te matou.\n");
}
//Define mensagem de inicio
const char* drag_start ="Você enfrentará o dragão feroz e astuto! Tome muito cuidado em sua batalha, pois o destino do reino depende da sua vitória!\n";

//Define mensagem de conclusão
const char* drag_end = "\nVocê derrotou o dragão! Parabéns você salvou a todos!\n";