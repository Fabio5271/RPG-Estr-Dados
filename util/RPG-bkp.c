#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int game_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 2, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Mostra as mensagens de morte de cada caminho
int death_msg(int orig, int dest){
    if (orig == 2 && dest == 4){
        printf("\nEntrou na vala.");
    }
    if (orig == 6 && dest == 8){
        printf("\nSeu cu ardeu.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}

int check_death(int path[], int num_nodes, int *pos){
    if (game_path[path[num_nodes-2]][path[num_nodes-1]] != 2){ // Se o caminho não causa morte, retornar 0
        return 0;
    }

    death_msg(path[num_nodes-2] + 1, path[num_nodes-1] + 1); // Manda as mensagens de morte usando os índices + 1, pra facilitar colocar cada caso na função

    printf("Voltando pro começo...\n");
    *pos = 0;

    return 1;
}

int main(){
    int current_node = 0; // começa na entrada do labirinto
    int path[NUM_NODES]; // armazena o caminho escolhido pelo usuário
    int nodes_in_path = 1; // numero de nos no caminho, começa com um (a entrada)
    path[0] = current_node;

    printf("Bem-vindo ao RPG do FUSCAO\n");
    printf("Você é um herói destemido que recebe uma missão do grande sábio da sua terra: matar um terrível dragão que aterroriza o reino.\n");
    printf(" Mas, antes de enfrentar o dragão, você precisa coletar uma série de equipamentos mágicos.Boa sorte!");
    printf("O primeiro item que você precisa é a Espada da Tormenta. Dizem que ela esta dentro de labirinto perigoso, que é cheio de armadilhas mortais e monstros hostis.\n");
    printf("O caminho pelo labirinto é complicado e você precisa escolher cuidadosamente qual caminho seguir para evitar as armadilhas e derrotar os monstros.");
    printf("Voce chegou a porta do labirinto:");

    while (current_node != NUM_NODES - 1){ // Enquanto não chegar à Espada da Tormenta
        printf("\nVocê está no nó %d.\n", current_node + 1);
        printf("Para onde você quer ir?\n");

        for (int i = 0; i < NUM_NODES; i++){ // Mostra os caminhos disponíveis
            if (game_path[current_node][i] != 0){
                printf("%d. Nó %d\n", i + 1, i + 1);
            }
        }

        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > NUM_NODES || game_path[current_node][choice - 1] == 0){
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }
        
        path[nodes_in_path++] = choice - 1;
        current_node = choice - 1;
        check_death(path, nodes_in_path, &current_node);
    }
    printf("\nParabéns! Você encontrou a Espada da Tormenta!\n");
    return 0;
}
