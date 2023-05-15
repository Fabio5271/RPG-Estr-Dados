#include <stdio.h>


// Define o número de nós no grafo
#define NUM_NODES 8

// Define as arestas do grafo
int labr_path[NUM_NODES][NUM_NODES] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 2, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Define as mensagens de entrada em cada local
int node_msg(int orig, int dest){
    if (orig == 1 && dest == 2){
        printf("\nVocê caminha pelo corredor escuro, mas logo avista uma luz brilhante no fim do túnel. Conforme você se aproxima, a luz se torna mais forte e você se depara com uma sala circular, com pilares de pedra esculpidos e um teto curvado.");
    }
    if (orig == 1 && dest == 4){
        printf("\nVocê segue pelo corredor escuro e logo encontra uma bifurcação. Opta pela passagem à direita, seguindo em frente até encontrar uma porta de ferro enferrujada. Com um empurrão forte, a porta se abre, revelando uma sala ampla e escura com um brilho fraco vindo de uma abertura no teto.");
    }
    if (orig == 2 && dest == 3){
        printf("\nVocê entra na sala circular e encontra uma saída do outro lado. A porta é esculpida em madeira escura, com entalhes intrincados que parecem contar uma história antiga e esquecida. Você segue em frente e entra em um corredor estreito, iluminado por tochas que piscam na escuridão.");
    }
    if (orig == 3 && dest == 6){
        printf("\nVocê segue pelo corredor estreito até chegar a uma escada íngreme que leva a uma sala oval, com paredes de pedra esculpidas com padrões complexos. Há uma luz suave que emana de uma fonte brilhante no centro da sala, que parece emitir um zumbido suave.");
    }
    if (orig == 4 && dest == 5){
        printf("\nVocê escolhe a passagem à direita e segue em frente, até que encontra a porta de ferro enferrujada. Com um empurrão forte, a porta se abre, revelando uma sala ampla e escura com um brilho fraco vindo de uma abertura no teto. Você segue em frente, passando por pilares altos e chegando a um corredor estreito e sinuoso.");
    }
    if (orig == 4 && dest == 7){
        printf("\nVocê escolhe a passagem à esquerda e segue em frente, descendo uma série de degraus íngremes. Você emerge em uma caverna escura e úmida, com paredes de pedra cobertas de musgo. Há um brilho fraco que vem de uma passagem estreita na parede à sua frente.");
    }
    if (orig == 5 && dest == 8){
        printf("\nVocê segue pela passagem estreita na caverna e chega a uma sala pequena e apertada. No centro da sala, há um pedestal de pedra, com uma espada brilhante presa a ele. À medida que você se aproxima, sente uma aura poderosa emanando da espada, fazendo com que seu coração bata mais rápido.");
    }
    printf("\nO que você irá fazer agora?\n");
}

// Define as mensagens de morte de cada caminho
int death_msg(int orig, int dest){
    if (orig == 2 && dest == 4){
        printf("\nAo entrar nesta sala, você se depara com um chão coberto de musgo. Quando você pisa no musgo, ele se revela escorregadio e suas pernas são puxadas para baixo, fazendo com que você caia em um buraco profundo e escuro. Você tenta se segurar, mas é tarde demais e você acaba caindo em um abismo sem fim.");
    }
    if (orig == 2 && dest == 5){
        printf("\nAssim que você entra na sala, você sente um cheiro estranho no ar. Você olha para cima e vê uma nuvem de gás venenoso se aproximando rapidamente. Você tenta correr para a porta oposta, mas a nuvem já está sobre você. Você começa a tossir e a sentir uma dor intensa em seus pulmões, até que finalmente desmaia.");
    }
    if (orig == 7 && dest == 5){
        printf("\nAo entrar na sala, você sente um arrepio percorrer sua espinha. A luz é fraca e mal ilumina os cantos escuros da sala. Ao avançar, você escuta um sussurro que parece vir de todos os lados. O ar fica pesado e a sua respiração começa a ficar difícil. De repente, você se vê cercado por uma densa neblina negra, que torna impossível enxergar qualquer coisa. Enquanto você tenta encontrar uma saída, as vozes sussurrantes se transformam em gritos ensurdecedores. Seus ouvidos doem e sua cabeça começa a latejar até que finalmente, em meio ao caos, você perde a consciência");
    }
    if (orig == 6 && dest == 8){
        printf("\nQuando você entra na sala, percebe que ela está inundada até o teto. Você tenta nadar até a porta oposta, mas a correnteza é forte e você é arrastado para baixo. Você luta contra a água, mas logo percebe que é inútil e acaba afundando para a morte.");
    }
    printf("\nVocê escolheu o caminho errado. Você morreu.\n");
}

//Define mensagem de inicio
const char* labr_start = "\n Você se encontra diante da entrada de um grande labirinto, um portal escuro e imponente que se ergue diante de você. A pedra cinzenta e desgastada pela idade é decorada com relevos intricados, esculpidos por artesãos há muito tempo esquecidos. Enquanto você se aproxima da entrada do labirinto, sente um arrepio subir pela sua espinha. Uma brisa fria sopra, trazendo consigo o cheiro úmido e terroso que emana da escuridão do interior.";

//Define mensagem de conclusão
const char* labr_end = "\nParabéns! Você encontrou a Espada da Tormenta!\n";