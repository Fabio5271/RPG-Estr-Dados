#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int volc_path[NUM_NODES][NUM_NODES] = {
    {0, 2, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
int v_node_msg(int node){
    if (node == 3){
        printf("\nTu olha e tem um vulcâozão.\n");
    }
    if (node == 5){
        printf("\nSala de lava\n");
    }
    if (node == 4){
        printf("\nSala com mais lava\n");
    }
    if (node == 5){
        printf("\nSala pingando lava\n");
    }
    if (node == 7){
        printf("\nSala com um rio de lava\n");
    }
    
    printf("\nOque você irá fazer agora?\n");
}

char* v_node_preview(int orig, int next_node){
    if (orig == 1 && next_node == 3){
       return "Teste13 3";
    }
    else {
        return "A definir";
    }
}

// Mostra as mensagens de morte de cada caminho
int v_death_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nVocê pisou em falso e caiu na lava!\n");
    }
    if (orig == 3 && dest == 4){
        printf("\nUm grupo enorme de monstros de lava te atacou!\n");
    }
    if (orig == 5 && dest == 6){
        printf("\nUm mar de lava te encobriu!\n.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}
//Define mensagem de inicio
const char* volc_start ="\nVocê chegou na base do vulcão e precisa chegar até o centro para adquirir o amuleto do Fodase-Fogo!Tome muito cuidado em seu caminho, o vulcão é um lugar perigoso, um deslize e você morre queimado! \n";

//Define mensagem de conclusão
const char* volc_end = "\nParabéns Você encontrou o amuleto do Fodase-Fogo!\n";

//Define a mensagem de entrada do último nó
const char* v_end_node_msg = "\nSala com pedestal com o amuleto\n";