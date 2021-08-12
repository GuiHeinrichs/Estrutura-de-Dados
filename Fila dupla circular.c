#include <stdio.h>
#include <stdlib.h>

struct no{
   int info;
   struct no* elo_anterior;
   struct no* elo_proximo;
};

typedef struct no No;

struct fila{
   No* inicio;
   No* fim;
};

typedef struct fila Fila;

Fila* cria(){
   Fila* fila = (Fila*) malloc(sizeof(Fila));
   fila->inicio = NULL;
   fila->fim = NULL;
   if(fila == NULL){
    	printf("\nMemoria insuficiente!");
    	exit(1);
	}
   return fila;
}

No* insere_fim(No* inicio, No* fim, int info){
   No* no = (No*) malloc(sizeof(No));
   no->info = info;

   if(fim == NULL && inicio == NULL){
    	no->elo_proximo = no;
    	no->elo_anterior = no;
   }else{
	fim->elo_proximo = no;
	no->elo_anterior = fim;
	fim = no;
	
	inicio->elo_anterior = fim;
	fim->elo_proximo = inicio;
   }
   return no;
}

void enqueue_fim(Fila* fila , int info){
   fila->fim = insere_fim(fila->inicio,fila->fim , info);
   if(fila->inicio == NULL){
        fila->inicio = fila->fim;
    }
}

void vazia(Fila* fila){
	
  if(fila->inicio == NULL && fila->fim == NULL && fila->inicio == fila->fim){
    printf("\nA fila esta vazia!\n");
  }else{
    printf("\nA fila nao esta vazia!\n");
  }
}

No* insere_inicio(No* inicio, No* fim, int info){
   No* no = (No*) malloc(sizeof(No));
   no->info = info;

   if(fim == NULL && inicio == NULL){
      no->elo_proximo = no;
      no->elo_anterior = no;
   }else{
   	no->elo_proximo = inicio;
   	inicio->elo_anterior = no;
   	inicio = no;
   	
   	inicio->elo_anterior = fim;
   	fim->elo_proximo = inicio;
   }
   return no;
}

void enqueue_inicio(Fila* fila , int info){
   fila->inicio = insere_inicio(fila->inicio, fila->fim,info);
   if(fila->fim == NULL){
        fila->fim = fila->inicio;
    }
}

void dequeue_inicio(Fila* fila){
	if(fila->inicio == NULL && fila->fim == NULL){
		printf("\nFila esta vazia.");
	}else{
		No* no = fila->inicio;
		if(fila->inicio == fila->fim){
			fila->inicio = fila->fim = NULL;
		}else{
			fila->inicio = no->elo_proximo;
			
			fila->inicio->elo_anterior = fila->fim;
			fila->fim->elo_proximo = fila->inicio;	
		}
		free(no);
	}
}

void dequeue_fim(Fila* fila){
	if(fila->fim == NULL && fila->inicio == NULL){
		printf("\nFila esta vazia.");
	}else{
		No* no = fila->fim;
		if(fila->inicio == fila->fim){
			fila->inicio = fila->fim = NULL;
		}else{
			fila->fim = no->elo_anterior;
			
			fila->fim->elo_proximo = fila->inicio;
			fila->inicio->elo_anterior = fila->fim;	
		}
		free(no);
	}
}

void imprime(Fila* fila){
   No* no;
   no = fila->inicio;
	if(fila->fim == NULL && fila->inicio == NULL){
		printf("\nFila esta vazia.");
	}else{
		do{
      		printf("\n|INFO: %d |", no->info);
      
      		no = no->elo_proximo;
    	}while(no != fila->inicio);
     		printf("\n");
	}
}
   
void libera(Fila** fila){
	Fila* aux = *fila;
   	
   	if(aux != NULL){
   	//caso a lista possua elementos.
   		No* no = aux->inicio;
   		printf("\nMemoria liberada!\n");
   		while(no != aux->fim){
   		 No* no2 = no;
   		 no = no->elo_proximo;
   			
   		 free(no2);
		}
		free(no);
	   }else{
	   	printf("\nFila vazia, nada para liberar.");
	   }
   free(aux);
   *fila = NULL;   
}


void busca(Fila* fila, int info){
	No* no = fila->inicio;
	
	if(no == NULL){
		printf("\nA fila esta vazia!");
		return;
	}
	int posicao = 1;
	int encontrado = 0;
	do{
		if(no->info == info){
			printf("\n Informacao encontrada na posicao %d.\n", posicao);
			encontrado = 1;
		}
		no = no->elo_proximo;
		posicao++;
	}while(no != fila->inicio);
	if(encontrado == 0){
		printf("O valor nao foi encontrado.\n");
		return;
	}
}

int main(){
	char resposta;
	int n, i, j, respostaMenu;
	
	printf("\nDeseja criar a fila dupla circular? ");
	scanf("%c", &resposta);

  	if(resposta == 'S' || resposta == 's'){
    
    	Fila* f1 = cria();
    	printf("\nFila dupla encadeada e circular criada!\n\n");

    while(respostaMenu != 7){
      printf("\nAcesse as demais funcoes:\n1-Libera.\n2-Busca.\n3-Insere.\n4-Retira.\n5-Imprime.\n6-Vazia.\n7-Sair;\n");
      scanf("%d", &respostaMenu);

      switch(respostaMenu){
        case 1:
          libera(&f1);
        break;

        case 2:
          printf("\nSessao para busca: \n");
          int valor2;

          printf("\n Digite um valor para a busca: ");
          scanf("%d", &valor2);

          busca(f1, valor2);
        break;

        case 3:
          fflush(stdin);
          printf("\nSessao de atribuicao: \n");
          int valor;
          char respEnqueue;
          printf("\nDeseja adicionar ao inicio[I] ou o fim[F]?");
          scanf("%c", &respEnqueue);
          fflush(stdin);
            if(respEnqueue == 'I' || respEnqueue == 'i'){
              printf("\n Digite um valor para a insercao [Inicio]: ");
              scanf("%d", &valor);

              enqueue_inicio(f1, valor); 
            }else if(respEnqueue == 'F' || respEnqueue == 'f'){
              printf("\n Digite um valor para a insercao [Fim]: ");
              scanf("%d", &valor);

              enqueue_fim(f1, valor); 
            }else{
              printf("\nValor nao compativel.\n");
            }
        break;

        case 4:
        fflush(stdin);
          printf("\nSesso de remocao:\n");

          int valor3;
          char respEnqueue2;

            printf("\nDeseja remover do inicio[I] ou do fim[F]?");
            scanf("%c", &respEnqueue2);
            fflush(stdin);
            if(respEnqueue2 == 'I' || respEnqueue2 == 'i'){
              dequeue_inicio(f1);
            }else if(respEnqueue2 == 'F' || respEnqueue2 == 'f'){
              dequeue_fim(f1); 
            }else{
              printf("\nValor nao compativel.\n");
            }
          
        break;

        case 5:
          printf("\nImpressao:\n\n");
          imprime(f1);
        break;

        case 6:
          vazia(f1);
        break;
        
        case 7:
          printf("\n\n -= Saindo =-");
          libera(&f1);
          exit(1);
        break;
        
        default :
          printf ("Valor invalido!\n");
          exit(1);
        }
    }
    
    }else if(resposta == 'N' || resposta == 'n'){
      printf("\nEncerrando o programa.");      
    }	
//Fila* f1 = cria();
//
//enqueue_inicio(f1, 22);
//enqueue_inicio(f1, 222);
//enqueue_fim(f1,33);
//enqueue_fim(f1,333);
//enqueue_fim(f1,3333);
//enqueue_fim(f1,33323);
//
//busca(f1, 222);
//
//imprime(f1);
//
//vazia(f1);
//
//libera(&f1);
//
//vazia(f1);
	
return 0;

}
   
   
