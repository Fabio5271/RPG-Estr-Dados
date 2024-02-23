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
    {0, 0, 0, 0, 0, 2, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
void v_node_msg(int node){
    if (node == 3){
        printf("\nAo entrar você é imediatamente envolvido por um calor intenso e pelo brilho da lava borbulhante que flui ao redor. As paredes irregulares são formadas por rochas vulcânicas, emanando um brilho avermelhado. A câmara é preenchida com ruídos inquietantes, o som constante da lava fervente e ocasionalmente um rugido abafado ecoa pelas profundezas. Pontes estreitas e instáveis cruzam os rios de lava, exigindo habilidade e equilíbrio para atravessar.\n");
    }
    if (node == 5){
        printf("\nAo continuar para dentro do vulcão,a atmosfera muda drasticamente, o ar espesso está repleto de fumaça vulcânica, criando uma visibilidade limitada e uma sensação de claustrofobia. A câmara é um labirinto de estalactites afiadas e paredes íngremes cobertas por musgo negro. O som de vapor sibilante e gemidos das profundezas ecoa sinistramente.\n");
    }
    if (node == 7){
        printf("\nChegando perto do coração do vulcão,você se depara com uma sala verdadeiramente deslumbrante. Aqui, a rocha vulcânica se transformou em uma catedral de cristais radiantes. As paredes são revestidas por geodos gigantes, irradiando uma luz suave e multicolorida que preenche a câmara com um brilho hipnotizante.\n");
    }
    printf("\nOque você irá fazer agora?\n");
}

// Define as prévias de cada movimento
char* v_node_preview(int orig, int next_node){
    if (orig == 1 && next_node == 2){
       return "Pegar um atalho em volta do lago de lava...";
    }
    if (orig == 1 && next_node == 3){
       return "Entrar no vulcão...";
    }
    if (orig == 3 && next_node == 4){
       return "Seguir pela ponte meio queimada da direita...";
    }
    if (orig == 3 && next_node == 5){
       return "Seguir por um caminho de pedras mais afastado para cruzar o rio... ";
    }
    if (orig == 5 && next_node == 6){
       return "Seguir adiante pelo labirinto marcando seu caminho...";
    }
    if (orig == 5 && next_node == 7){
       return "Usar a espada da tempestade para soprar a fumaça e seguir em frente...";
    }
    if (orig == 7 && next_node == 8){
       return "Arrebentar o fundo do sala que parece ser fragil...";
    }
    if (orig == 7 && next_node == 6){
       return "Procurar o caminho verificando as pedras brilhantes...";
    }
    else {
        return "A definir";
    }
}

// Mostra as mensagens de morte de cada caminho
void v_death_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nVocê escoregou e caiu na lava!\n");
    }
    if (orig == 3 && dest == 4){
        printf("\nUm monstro flamejante emerge das profundezas da lava, sua pele escaldante brilhando intensamente. Suas garras afiadas rasgam o ar enquanto ele avança em sua direção, exalando chamas ardentes. Seu rugido ensurdecedor faz tremer o chão, anunciando sua iminente destruição.\n");
    }
    if (orig == 5 && dest == 6){
        printf("\nDo escuro e nebuloso labirinto, surgem criaturas esqueléticas, com olhos brilhantes e dentes afiados. Seus passos silenciosos e rápidos ecoam como um pesadelo, enquanto eles se movem com destreza e astúcia, desafiando qualquer tentativa de escapar.\n.");
    }
    if (orig == 7 && dest == 6){
        printf("\nA luz multicolorida que dança nas paredes e tetos da câmara esconde criaturas camufladas, que emergem com velocidade surpreendente para atacar. Seus golpes são rápidos e precisos, refletidos pela luz cintilante, enquanto você luta para escapar do fascínio mortal dos geodos luminosos.\n.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}
//Define mensagem de inicio
const char* volc_start ="\nVocê chegou na base do vulcão e precisa chegar até o centro para adquirir o amuleto do Fodase-Fogo!Tome muito cuidado em seu caminho, o vulcão é um lugar perigoso, um deslize e você morre queimado! \n";

//Define mensagem de conclusão
const char* volc_end = "\nParabéns Você encontrou o amuleto do Fodase-Fogo!\n";

//Define a mensagem de entrada do último nó
const char* v_end_node_msg = "\nVocê chega no que parece ser o coração do vulcão, uma sala iluminada por lava fervente abriga um pedestal de pedra negra com um amuleto brilhante. O amuleto, feito de um material desconhecido, emana uma energia mágica intensa. As inscrições na base do pedestal são indecifráveis, sugerindo segredos antigos. \n";