#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int mount_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 1}, // O grafo é menor, então pula pro nó 8, que funciona como se fosse o 6
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

// Define as mensagens de entrada em cada local
int m_node_msg(int node){
    if (node == 2){
        printf("\nVocê se aproxima da base da montanha e sente um arrepio percorrer sua espinha. Com um suspiro, você se prepara para subir. A entrada é estreita e a rocha é lisa ao toque, mas você não se amedronta.\n");
    }
    if (node == 3){
        printf("\nVocê segue o caminho à sua frente e encontra um corredor estreito, com a rocha escorregadia sob seus pés. O ar é úmido e o som de gotejamento ecoa nas paredes da caverna.\n");
    }
    if (node == 4){
        printf("\nAo se virar, você vê um caminho largo que serpenteia pela montanha. O sol brilha acima, iluminando o caminho à frente. Você avança com cautela, sentindo cada fibra de seu corpo congelando.\n");
    }
    if (node == 5){
        printf("\nO caminho se estreita e você começa a subir, a rocha ficando cada vez mais íngreme. Você sente o cheiro de monstros próximos e mantém sua mão firme na empunhadura da espada.\n");
    }
    
    printf("\nO que você irá fazer agora?\n");
}

// Define as prévias de cada movimento
char* m_node_preview(int orig, int next_node){
    if (orig == 1 && next_node == 2){
       return "Seguir a estrada congelada adiante.";
    }
    if (orig == 1 && next_node == 3){
        return "Entrar pelo corredor estreito congelado.";
    }
    if (orig == 2 && next_node == 4){
        return "Seguir um caminho largo...";
    }
    if (orig == 2 && next_node == 5){
        return "Seguir um caminho ingrime.";
    }
    if (orig == 3 && next_node == 5){
        return "Você segue pela trilha e ouve um rugido vindo de um ponto mais adiante...";
    }
    if (orig == 4 && next_node == 8){
        return "Seguir o caminho estreito.";
    }
    if (orig == 5 && next_node == 8){
        return "Seguir até o topo da montanha.";
    }
    else {
        return "A definir";
    }
}

// Mostra as mensagens de morte de cada caminho
int m_death_msg(int orig, int dest){
    if (orig == 3 && dest == 5){
        printf("\nVocê aperta a espada e se prepara para o que está por vir. Quando você chega mais perto, um troll aparece em sua frente. Com um rugido, ele ataca. Você luta bravamente, mas acaba sendo derrotado.\n");
    }
    if (orig == 4 && dest == 8){
        printf("\nVocê continua a subir a montanha, mas percebe que a rocha está ficando cada vez mais instável. De repente, um pedaço da rocha se solta, fazendo com que você perca o equilíbrio. Você tenta se agarrar a algo, mas não consegue, e acaba caindo para a morte.\n");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}
//Define mensagem de inicio
const char* mount_start = "\nVocê chegou na base da montanha congelada, para encontrar o escudo da montanha congelada é preciso chegar ao topo! Tome muito cuidado com suas escolhas, pois o caminho é traiçoeiro e cheio de monstros! \n";
//Define mensagem de conclusão
const char* mount_end ="\nParabéns! Você encontrou o escudo da montanha congelada!\n";

//Define a mensagem de entrada do último nó
const char* m_end_node_msg = "\nVocê chega ao topo da montanha, exausto e ofegante. Mas a vista lá de cima compensa todo o esforço. Ele avista o tesouro reluzente, o escudo congelado. Você respira fundo e aprecia a beleza da paisagem, sentindo-se vivo e realizado por ter superado mais esse desafio.\n";