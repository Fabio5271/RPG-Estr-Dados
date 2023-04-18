#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> // só funciona em linux

/* ignorar tudo entre esses comentários */
int game_path[2][2];
/* ignorar tudo entre esses comentários */

// Função que verifica se o caminho escolhido pelo usuário é válido (tirei, nunca era usada)
int is_valid_path(int path[], int num_nodes)
{
    int i;
    for (i = 0; i < num_nodes - 1; i++){
        if (game_path[path[i]][path[i + 1]] == 0){
            return 0;
        }
    }
    return 1;
};

// teste do conceito de memória dinâmica, só funciona em linux
int main(){
    int c=1;
    printf("sizeof(int)=%d\n",sizeof(int));

    int* path = malloc(sizeof(int));

    while (c<10){
        printf("\nsizeof path=%ld\n",malloc_usable_size((int*) path));
        printf("c=%d\n",c);
        path = realloc(path, c * sizeof(int));
        printf("sizeof path=%ld\n",malloc_usable_size((int*) path));
        c++;
    }
    return EXIT_SUCCESS;
}

// mostrar o que tem no path
void prt_path(int* path, int nip){
    int c = 0;
    printf("\npath: ");
    while (c < nip){
        printf("%d ",path[c]+1);
        c++;
    }
    printf("\n");
}
/* no main:
if (choice == 9){
            prt_path(path, nodes_in_path);
            current_node = path[nodes_in_path - 2];
        }
*/