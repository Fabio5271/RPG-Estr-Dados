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
    {0, 0, 0, 0, 0, 0, 0, 0}};

// Função que verifica se o caminho escolhido pelo usuário é válido
int is_valid_path(int path[], int num_nodes)
{
    int i;
    for (i = 0; i < num_nodes - 1; i++){
        if (game_path[path[i]][path[i + 1]] == 0){
            return 0;
        }
    }
    return 1;
}

// verifica se o player morre e se sim volta pro começo
int check_death(int path[], int num_nodes, int *pos){
    if (game_path[path[num_nodes-2]][path[num_nodes-1]] != 2){ // verifica se o caminho escolhido leva à Espada da Tormenta
        return 0;
    }
    
    if(path[num_nodes-2] == 1 && path[num_nodes-1] == 3){
        printf("\nEntrou na vala.");
    }
    if(path[num_nodes-2] == 5 && path[num_nodes-1] == 7){
        printf("\nSeu cu ardeu.");
    }

    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
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

    while (current_node != NUM_NODES - 1){ // enquanto não chegar à Espada da Tormenta
        printf("\nVocê está no nó %d.\n", current_node + 1);
        printf("Para onde você quer ir?\n");

        for (int i = 0; i < NUM_NODES; i++){
            // if (game_path[current_node][i] == 1){
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
        if(game_path[current_node][choice-1] == 2){

        }
        path[nodes_in_path++] = choice - 1;
        
        current_node = choice - 1;
        
        check_death(path, nodes_in_path, &current_node);
    }
    printf("\nParabéns! Você encontrou a Espada da Tormenta!\n");
    return 0;
}
