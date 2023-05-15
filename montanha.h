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
        printf("\nVocê se aproxima da base da montanha e sente um arrepio percorrer sua espinha. Com um suspiro, você se prepara para subir. A entrada é estreita e a rocha é áspera ao toque, mas você não se detém.");
    }
    if (orig == 1 && dest == 3){
        printf("\nVocê segue o caminho à sua frente e encontra um corredor estreito, com a rocha escorregadia sob seus pés. O ar é úmido e o som de gotejamento ecoa nas paredes da caverna.");
    }
    if (orig == 2 && dest == 4){
        printf("\nAo se virar, você vê um caminho largo que serpenteia pela montanha. O sol brilha acima, iluminando o caminho à frente. Você avança com cautela, sentindo cada fibra de seu corpo congelando");
    }
    if (orig == 3 && dest == 5){
        printf("\nO caminho se estreita e você começa a subir, a rocha ficando cada vez mais íngreme. Você sente o cheiro de monstros próximos e mantém sua mão firme na empunhadura da espada.");
    }
    if (orig == 5 && dest == 6){
        printf("\nVocê chega ao topo da montanha, exausto e ofegante. Mas a vista lá de cima compensa todo o esforço. Ele avista o tesouro reluzente, o escudo congelado. Você respira fundo e aprecia a beleza da paisagem, sentindo-se vivo e realizado por ter superado mais esse desafio");
    }
    printf("\nOque você irá fazer agora?\n");
}

// Mostra as mensagens de morte de cada caminho
int m_death_msg(int orig, int dest){
    if (orig == 3 && dest == 5){
        printf("\nVocê se move pela trilha e ouve um rugido vindo de um ponto mais adiante. Você aperta a espada e se prepara para o que está por vir. Quando você chega mais perto, um troll aparece em sua frente. Com um rugido, ele ataca,você luta bravamente, mas acaba sendo derrotado.");
    }
    if (orig == 4 && dest == 6){
        printf("\nVocê continua a subir a montanha, mas percebe que a rocha está ficando cada vez mais instável. De repente, um pedaço da rocha se solta, fazendo com que você perca o equilíbrio. Você tenta se agarrar a algo, mas não consegue, e acaba caindo para a morte.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}
//Define mensagem de inicio
const char* mount_start = "Você chegou na base da montanha congelada, para encontrar o escudo da montanha congelada é preciso chegar ao topo!. Tome muito cuidado com suas escolhas,pois o caminho é traiçoeiro e cheio de monstros! \n";
//Define mensagem de conclusão
const char* mount_end ="\nParabéns! Você encontrou o escudo da montanha congelada!\n";
