#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info; // elemento da lista
	struct no *prox;
} t_no;

typedef struct lista {
	t_no *primeiro;
} t_lista;

t_lista criar_lista() {
  t_lista lista = { .primeiro = NULL };
  return lista;
}

t_no *criar_no(int item) {
  t_no *no;
  no = malloc(sizeof(t_no));
  if(no != NULL) {
    no->info = item;
    no->prox = NULL;
  }
  return no;
}

void inserir_inicio(t_lista *lista, int item) {
  t_no *no = criar_no(item);

  if(no == NULL) {
    printf("Erro ao inserir novo nó!\n");
    return;
  }

  if(lista->primeiro == NULL) { // se a lista estiver vazia
    lista->primeiro = no;
  } else { // inserir no início
    no->prox = lista->primeiro; // (1)
    lista->primeiro = no; // (2)
  }
  
}

void inserir_fim(t_lista *lista, int item) {
  t_no *no = criar_no(item);

  if(no == NULL) {
    printf("Erro ao inserir novo nó!\n");
    return;
  }

  if(lista->primeiro == NULL) { // se a lista estiver vazia
    lista->primeiro = no;
  } else { // inserir no fim
    // (1 percorrer os nós)
    t_no *aux_no = lista->primeiro;
    while(aux_no->prox != NULL) {
      aux_no = aux_no->prox;
    }
    // atualizamos o útlimo nó da lista para apontar para
    // o novo nó, tornando o novo nó o útlimo da lista.
    // Por sua vez, o novo nó já está apontando para NULL. 
    aux_no->prox = no; // (2)
  }
}

void listar(t_lista lista) {
  if(lista.primeiro == NULL) {
    printf("Lista vazia!\n");
    return;
  }
  // (1 percorrer os nós)
  t_no *aux_no = lista.primeiro;
  int i = 0;
  while(aux_no != NULL) {
    printf("Nó %d -> info: %d\n", i, aux_no->info);
    aux_no = aux_no->prox;
    i++;
  }
}

t_no *consultar_item(t_lista lista, int item) {
  // (1 percorrer os nós)
  t_no *aux_no = lista.primeiro;
  while(aux_no != NULL) {
    if(aux_no->info == item) {
      return aux_no;
    }
    aux_no = aux_no->prox;
  }
  return NULL;
}

void deletar_item(t_lista *lista, int item) {
	if(lista->primeiro == NULL) { // restrições
		printf("Não é possível deletar item - Lista vazia!\n");
		return;
	}
	// se for o primeiro elemento da lista
	if(lista->primeiro->info == item) {
		t_no *prox = lista->primeiro->prox;
		free(lista->primeiro);
		lista->primeiro = prox;
	} else { // se for o segundo em diante
		t_no *aux_no = lista->primeiro;
    // verificamos se o próximo contém o conteúdo da lista
		while(aux_no->prox != NULL) {
			if(aux_no->prox->info == item) {
        t_no *no_encontrado = aux_no->prox;
        aux_no->prox = no_encontrado->prox;
        free(no_encontrado);
        break;
      }
      aux_no = aux_no->prox;
		}
	}
}

void deletar_indice(t_lista *lista, int indice) {
	if(lista->primeiro == NULL) { // restrições
		printf("Não é possível deletar item - Lista vazia!\n");
		return;
	}
  if(indice < 0) { // restrições
		printf("Índice inválido!\n");
		return;
	}
	
  // se for o primeiro elemento da lista
	if(indice == 0) {
		t_no *prox = lista->primeiro->prox;
		free(lista->primeiro);
		lista->primeiro = prox;
	} else { // se for o segundo em diante
		t_no *aux_no = lista->primeiro;
    // verificamos se o próximo contém o conteúdo da lista
    int i = 1;
		while(aux_no->prox != NULL && (i < indice)) {
			i++; aux_no = aux_no->prox;
		}
    if(i == indice-1) {
        t_no *no_encontrado = aux_no->prox;
        aux_no->prox = no_encontrado->prox;
        free(no_encontrado);
    }
	}
}

void menu_inserir(t_lista *lista) {
  printf("-----------------------------------\n");
  printf("INSERIR\n");
  printf("-----------------------------------\n");
  printf("Introduza o novo item da lista: ");
  int item;
  scanf("%d%*c", &item);
  
  int opcao;
  do {
    printf("Escolha uma opção de inserção (1 - início, 2 - fim): ");
    scanf("%d%*c", &opcao);
  
    switch(opcao) {
      case 1:
        inserir_inicio(lista, item);
        break;
      case 2:
        inserir_fim(lista, item);
        break;
      default:
        printf("Opção inválida!\n");
    }
  } while(opcao != 1 && opcao != 2);
}

void menu_consultar(t_lista lista) {
  printf("-----------------------------------\n");
  printf("CONSULTAR\n");
  printf("-----------------------------------\n");
  
  int opcao;
  t_no *item_encontrado;
  do {
    printf("Escolha uma opção de consulta (1 - item, 2 - índice): ");
    scanf("%d%*c", &opcao);
    switch(opcao) {
      case 1: {
        int item;
        printf("Introduza o item: ");
        scanf("%d%*c", &item);
        item_encontrado = consultar_item(lista, item);
        break;
      } case 2: {
        printf("CONSULTAR LISTA POR ÍNDICE - Não implementado!\n");
        return;
      } default:
        printf("Opção inválida!\n");
        break;
    }
  } while(opcao != 1 && opcao != 2);
  if(item_encontrado == NULL) {
      printf("Item não encontrado!\n");
  } else {
    printf("Endereço do item: %p, info: %d\n", &item_encontrado, item_encontrado->info);
  }
}

void menu_deletar(t_lista *lista) {
  printf("-----------------------------------\n");
  printf("DELETAR\n");
  printf("-----------------------------------\n");
  
  int opcao;
  do {
    printf("Escolha uma opção de deleção (1 - item, 2 - índice): ");
    scanf("%d%*c", &opcao);
  
    switch(opcao) {
      case 1: {
        int item;
        printf("Introduza o item: ");
        scanf("%d%*c", &item);
        deletar_item(lista, item);
        break;
      } case 2: {
        int indice;
        printf("Introduza o índice: ");
        scanf("%d%*c", &indice);
        deletar_indice(lista, indice);
        break;
      } default:
        printf("Opção inválida!\n");
        break;
    }
  } while(opcao != 1 && opcao != 2);

}

int main(void) {
  t_lista lista = criar_lista();

  int opcao;
  do {
    
    system("clear");
    printf("1 - Exibir lista\n");
    printf("2 - Consultar lista\n");
    printf("3 - Inserir elemento na lista\n");
    printf("4 - Deletar elemento na lista\n");
    printf("5 - Atualizar elemento da lista\n");
    printf("6 - Zerar lista\n");
    printf("7 - Sair\n");
    printf("Opção: ");
    scanf("%d%*c", &opcao);

    switch(opcao) {
      case 1:
        listar(lista);
        break;
      case 2: {
        menu_consultar(lista);
        
        break;
      } case 3: 
        menu_inserir(&lista);
        break;
      case 4:
        menu_deletar(&lista);
        break;
      case 5:
        printf("ATUALIZAR LISTA - Não implementado!\n");
        break;
      case 6:
        printf("ZERAR LISTA - Não implementado!\n");
        break;
      case 7:
        break;
      default:
        printf("Opção inválida!\n");
        break;
    }
    printf("Pressione enter para continuar!");
    getchar();
    
  } while(opcao != 7);
  return 0;
}