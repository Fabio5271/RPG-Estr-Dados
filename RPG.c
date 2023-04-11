#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int graph[NUM_NODES][NUM_NODES] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Função que verifica se o caminho escolhido pelo usuário é válido
int is_valid_path(int path[], int num_nodes) {
    int i;
    for (i = 0; i < num_nodes-1; i++) {
        if (graph[path[i]][path[i+1]] == 0) {
            return 0;
        }
    }
    return 1;
}

// Função que verifica se o caminho escolhido pelo usuário leva à Espada da Tormenta
int is_path_to_sword(int path[], int num_nodes) {
    if (path[num_nodes-1] == NUM_NODES-1) {
        return 1;
    }
    return 0;
}

int main() {
    int current_node = 0; // começa na entrada do labirinto
    int path[NUM_NODES]; // armazena o caminho escolhido pelo usuário
    int num_nodes_in_path = 1; // começa com um nó na lista (a entrada)
    path[0] = current_node;

    printf("Bem-vindo ao RPG do FUSCAO\n");
    printf("Você é um herói destemido que recebe uma missão do grande sábio da sua terra: matar um terrível dragão que aterroriza o reino.\n");
    printf(" Mas, antes de enfrentar o dragão, você precisa coletar uma série de equipamentos mágicos.Boa sorte!");
    printf("O primeiro item que você precisa é a Espada da Tormenta. Dizem que ela esta dentro de labirinto perigoso, que é cheio de armadilhas mortais e monstros hostis.\n");
    printf("O caminho pelo labirinto é complicado e você precisa escolher cuidadosamente qual caminho seguir para evitar as armadilhas e derrotar os monstros.");
    printf("Voce chegou a porta do labirinto:");

    while (current_node != NUM_NODES - 1) { // enquanto não chegar à Espada da Tormenta
    printf("\nVocê está no nó %d.\n", current_node + 1);
    printf("Para onde você quer ir?\n");

    for (int i = 0; i < NUM_NODES; i++) {
        if (graph[current_node][i] == 1) {
            printf("%d. Nó %d\n", i + 1, i + 1);
        }
    }

    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > NUM_NODES || graph[current_node][choice - 1] == 0) {
        printf("Opção inválida. Tente novamente.\n");
        continue;
    }

    path[num_nodes_in_path++] = choice - 1;

    // Verifica se o caminho escolhido é válido
    if (!is_valid_path(path, num_nodes_in_path)) {
        printf("Você escolheu um caminho inválido. Você morreu.\n");
        return 0;
    }

    current_node = choice - 1;
}
printf("\nParabéns! Você encontrou a Espada da Tormenta!\n");
return 0;
}
