#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int mount_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}, // O grafo é menor, então pula pro nó 8, que funciona como se fosse o 6
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

// Define as mensagens de entrada em cada local
int m_node_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nTu olha e tem um montanhão.");
    }
    if (orig == 1 && dest == 3){
        printf("\n");
    }
    if (orig == 2 && dest == 4){
        printf("\n");
    }
    if (orig == 3 && dest == 5){
        printf("\n");
    }
    if (orig == 5 && dest == 6){
        printf("\n");
    }
    printf("\nOque você irá fazer agora?\n");
}

// Mostra as mensagens de morte de cada caminho
int m_death_msg(int orig, int dest){
    if (orig == 3 && dest == 5){
        printf("\nUma avalanche te engoliu.");
    }
    if (orig == 4 && dest == 6){
        printf("\nO chão quebrou e você afundou em um lago congelado.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu congelado.\n");
}
//Define mensagem de inicio
const char* mount_start = "Você chegou na base da montanha congelada, para encontrar o escudo da montanha congelada é preciso chegar ao topo!\nTome muito cuidado com suas escolhas,pois o caminho é cheio de armadilhas e monstros de gelo! \n";
//Define mensagem de conclusão
const char* mount_end ="\nVocê encontrou o escudo da montanha gelada!\n";
