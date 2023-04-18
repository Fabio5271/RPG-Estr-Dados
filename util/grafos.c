#include <stdio.h>

typedef struct no {
  char descricao[1000];
} t_no;

typedef struct aresta {
  t_no item;
  t_no origem;
  t_no destino;
} t_aresta;

int main(void) {
  printf("Hello World\n");
  return 0;
}