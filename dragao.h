#include <stdio.h>

// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int drag_path[NUM_NODES][NUM_NODES] = {
    {0, 2, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 1, 1, 1, 0, 0},
    {0, 2, 2, 0, 1, 1, 0, 0},
    {0, 2, 0, 0, 0, 1, 1, 0},
    {0, 2, 0, 0, 2, 0, 1, 0},
    {0, 2, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
void d_node_msg(int node){
    if (node == 3){
        printf("\nO dragão ruge de dor e se aproxima, cuspindo fogo em sua direção. Você usa seu escudo-congelado que o protege,mas derrete logo apos e se prepara para o próximo ataque.\n");
    }
    if (node == 4){
        printf("\nVocê entra em uma caverna escura. O rugido ensurdecedor do dragão ressoa nas paredes de pedra, ele sabe de você. Seus olhos brilham no escuro enquanto ele começa a entrar.\n");
    }
    if (node == 5){
        printf("\nO impacto do poder da espada surte grande efeito,machucando o dragão bastante e o lançando para tras,ele grita em furia balançando suas asas e cauda em sua direção.\n");
    }
    if (node == 6){
        printf("\nVocê sobe na pilha de tesouros.O dragão avança imprudentemente para proteger-las com ferocidade. O que te da espaço para cortar uma de suas asas\n");
    }
    if (node == 7){
        printf("\nVocê percebe que o dragão esta bem ferido. O ar está quente e cheio de fumaça. O dragão está pronto para seu ataque final. Esta é sua chance de derrotá-lo. O dragão junta todas as suas energias para um jato colossal de fogo em sua direção.\n");
    }
    printf("\nO que você irá fazer agora?\n");
}

// Define as prévias de cada movimento
char* d_node_preview(int orig, int next_node){
   if (orig == 1 && next_node == 2){//morre
       return "Avançar em direção ao dragão e acertar sua cabeça...";
    }
    if (orig == 1 && next_node == 3){
       return "Se aproximar cautelosamente do dragão e enfiar a espada em suas costas...";
    }
    if (orig == 1 && next_node == 4){
       return "Se esgueirar por uma caverna do lado evitando o olhar do dragão...";
    }
    if (orig == 3 && next_node == 2){//morre
       return "Tentar sair de perto do dragão...";
    }
    if (orig == 3 && next_node == 4){
       return "Entrar numa caverna perto de você...";
    }
    if (orig == 3 && next_node == 5){
       return "Usar o poder da espada da tempestade para derrubar o dragão com vento...";
    }
    if (orig == 3 && next_node == 6){
       return "Subir numa pilha de tesouros proxima...";
    }
    if (orig == 4 && next_node == 2){//morre
       return "Se esconder na escuridão da caverna...";
    }
    if (orig == 4 && next_node == 3){//morre
       return "Avançar em direção ao dragão e acertar sua cabeça...";
    }
    if (orig == 4 && next_node == 5){
       return "Usar o poder da espada da tempestade para acertar a cabeça do dragão com vento e tentar sair da caverna...";
    }
    if (orig == 4 && next_node == 6){
       return "Correr para uma pilha de tesouros...";
    }
    if (orig == 5 && next_node == 2){//morre
       return "Desviar do golpe da asa e tentar corta-la...";
    }
    if (orig == 5 && next_node == 6){
       return "Recuar para uma pilha de tesouros proxima...";
    }
    if (orig == 5 && next_node == 7){
       return "Desviar do golpe da cauda e cortar sua lateral...";
    }
    if (orig == 6 && next_node == 2){//morre
       return "Correr e deslizar na pilha por baixo do dragão e cortar sua barriga...";
    }
    if (orig == 6 && next_node == 5){//morre
       return "Pular na direção do dragão e enfiar a espada em sua cabeça...";
    }
    if (orig == 6 && next_node == 7){
       return "Pular na direção do dragao para cortar sua outra asa...";
    }
    if (orig == 7 && next_node == 2){//morre
       return "Desviar do sopro...";
    }
    if (orig == 7 && next_node == 8){
       return "Usar o amuleto do Fodase-Fogo...";
    }
    else {
        return "A definir";
    }
}

// Mostra as mensagens de morte de cada caminho
void d_death_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nO dragão estende suas garras afiadas em sua direção, rasgando seu corpo e encerrando sua jornada.");
    }
    if (orig == 3 && dest == 2){
        printf("\nO dragão o alcança e o devora em um único golpe. Seus esforços foram em vão.");
    }
    if (orig == 4 && dest == 2){
        printf("\nO dragão o encontra na escuridão da caverna e o devora impiedosamente.");
    }
    if (orig == 5 && dest == 2){
        printf("\nA asa te acerta em cheio, te cortando ao meio.");
    }
    if (orig == 6 && dest == 2){
        printf("\nAssim que você chega embaixo dele, ele solta seu peso e te esmaga.");
    }
    if (orig == 7 && dest == 2){
        printf("\nVocê é atingido pelo sopro de fogo. As chamas o consomem, levando-o à morte.");
    }
    if (orig == 4 && dest == 3){
        printf("\nO dragão te percebe no escuro e com uma mordida te despedaça.");
    }
    if (orig == 6 && dest == 5){
        printf("\nSua espada nao entra,o dragão usa sua força avassaladora para empurrá-lo e te acerta com a cauda,estraçalhando todos os ossos de seu corpo.");
    }
}

//Define mensagem de inicio
const char* drag_start ="\nVocê enfrentará o dragão feroz e astuto! Tome muito cuidado em sua batalha, pois o destino do reino depende da sua vitória! Você consegue ver o dragão em seu covil...\n";

//Define mensagem de conclusão
const char* drag_end = "\nVocê derrotou o dragão! Parabéns você salvou a todos!\n";

//Define a mensagem de entrada do último nó
const char* d_end_node_msg = "\nO amuleto se despedaça com você intacto no meio das chamas, o dragão parece exausto, você corre em sua direçao, ele tenta acerta-lo com as garras, mas facilmente você desvia e corta sua cabeça.O dragão está morto aos seus pés. Você venceu a batalha e salvou o reino!\n";