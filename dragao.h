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
int d_node_msg(int node){
    if (node == 2){
        printf("\nTu olha e tem um dragão.\n");
    }
    if (node == 3){
        printf("\nSala\n");
    }
    if (node == 4){
        printf("\nSala\n");
    }
    if (node == 5){
        printf("\nSala\n");
    }
    if (node == 6){
        printf("\nSala\n");
    }
    if (node == 7){
        printf("\nSala\n");
    }
    printf("\nOque você irá fazer agora?\n");
}

// Define as prévias de cada movimento
char* d_node_preview(int orig, int next_node){
    if (orig == 1 && next_node == 2){
       return "Teste12 4";
    }
    else {
        return "A definir";
    }
}

// Mostra as mensagens de morte de cada caminho
int d_death_msg(int orig, int dest){
    if (orig == 5 && dest == 8){
        printf("\nO dragão te partiu ao meio!\n");
    }
    if (orig == 6 && dest == 8){
        printf("\nO dragão te engoliu!\n");
    }
    printf("\nVocê escolheu o caminho errado. O dragão te matou.\n");
}
//Define mensagem de inicio
const char* drag_start ="\nVocê enfrentará o dragão feroz e astuto! Tome muito cuidado em sua batalha, pois o destino do reino depende da sua vitória!\n";

//Define mensagem de conclusão
const char* drag_end = "\nVocê derrotou o dragão! Parabéns você salvou a todos!\n";

//Define a mensagem de entrada do último nó
const char* d_end_node_msg = "\nSala\n";