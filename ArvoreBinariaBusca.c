#include <stdio.h>
#include <stdlib.h>

struct noArv{
    int valor;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv Arv;

void imprimeEmOrdem(Arv* a){
     if(a != NULL){
     	imprimeEmOrdem(a->esq);
        printf("%d ", a->valor);
        imprimeEmOrdem(a->dir);
	 }
}

Arv* insere (Arv* a, int valor){
    if(a == NULL){
        a = (Arv*)malloc(sizeof(Arv));
        a->valor = valor;
        a->esq = a->dir = NULL;
    }else if(valor < a->valor){
        a->esq = insere(a->esq,valor);
    }else if (valor > a->valor){
        a->dir = insere(a->dir,valor);
    }
    return a;
}

Arv* retira(Arv* r, int valor){
    if(r == NULL){
    	printf("\nArvore esta vazia, insira um valor para que possa mexer com a funcao de remocao.\n");
        return NULL;
    }else if(r->valor > valor){
        r->esq = retira(r->esq, valor);
    }else if(r->valor < valor){
        r->dir = retira(r->dir, valor);
    }else{
            if(r->esq == NULL && r->dir == NULL){
                free (r);
                r = NULL;
            }else if(r->esq == NULL){
                Arv* t = r;
                r = r->dir;
                free (t);
            }else if (r->dir == NULL){
                Arv* t = r;
                r = r->esq;
                free (t);
            }else{
                // SE tiver dois filhos
            }
        }
 return r;
}

int main(){

    char resposta;
	int n, i, j, respostaMenu;
	
	printf("\nDeseja criar a arvore binaria de pesquisa? ");
	scanf("%c", &resposta);

  	if(resposta == 'S' || resposta == 's'){
    
    	Arv* a1 = NULL;

	    while(respostaMenu != 4){
	      printf("\nAcesse as demais funcoes:\n1-Insere.\n2-Retira.\n3-Imprime.\n4-Sair.\n");
	      scanf("%d", &respostaMenu);
	
	      switch(respostaMenu){
	        case 1:
	        printf("\nSessao de atribuicao: \n");
	          int valor;
	
	          printf("\nDigite um valor: ");
	          scanf("%d", &valor);
	
	          a1 = insere(a1, valor);
	
	          printf("\nValor inserido.");
	        break;
	
	        case 2:
	          printf("\nSessao de remocao: \n");
	          int valor2;
	
	          printf("\n Digite um valor para a remocao: ");
	          scanf("%d", &valor2);
	
	          a1 = retira(a1, valor2);
	        break;
	
	        case 3:
	          printf("\nSessao de Impressao: \n");
	
	          imprimeEmOrdem(a1);
	        break;
	
	        case 4:
	          printf("\nSaindo do programa:\n");
	
	          exit(1);
	        break;
	        }
     }
// a1 = insere(a1,15);
// a1 = insere(a1,10);
// a1 = insere(a1,7);
// a1 = insere(a1,6);
// a1 = insere(a1,8);
// a1 = insere(a1,9);

// printf("\nSaida:\n ");
// imprimeEmOrdem(a1);

// a1 = retira(a1, 10);

// printf("\nDepois de remover o 10:\n ");
// imprimeEmOrdem(a1);
    }else if(resposta == 'N' || resposta == 'n'){
    	printf("\nSaindo.\n");
    	exit(1);
	}else{
		exit(1);
	}
}

