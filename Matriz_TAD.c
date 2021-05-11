#include <stdlib.h>
#include <stdio.h>

// Estrutura criada da matriz em struct para manipulacao utilizando TAD.
struct matriz{

  int linha;
  int coluna;
  float* valor;

};

//O que faz e para que utilizar nesse contexto? 
//Resposta: O comando typedef serve para criar um sinônimo e permite que um tipo existente seja denominado de uma forma diferente, de acordo com a especificação do programador.
typedef struct matriz Matriz;


//Funcao de criacao de uma Matriz utilizando TAD.
//Observe a funcao e explique o funcionamento da criacao da matriz utilizando TAD? Comente cada linha explicando cada item.
Matriz* cria(int m, int n){ //A função recebe duas variáveis para o tamanho da matriz que será criada. Na struct, está sendo utilizado o casting ou conversão de tipos.

  Matriz* mat = (Matriz*)malloc(sizeof(Matriz)); //É criada uma struct que se chama mat, onde também está sendo alocada a memória com base no tamanho da struct Matriz*.

  if (mat == NULL){ //Caso a memória não tenha mais espaço para que ocorra o alocamento, ou até mesmo ocorra algum erro durante o processo de alocação, a mensagem será apresentada e o programa será fechado. 
    printf("Memoria insuficiente!\n");
    exit(1);
  }

  mat->linha = m; //O membro linha da struct mat recebe o valor de int m, que foi recebido como parâmetro.
  mat->coluna = n; //O membro coluna da struct mat recebe o valor de int n, que foi recebido como parâmetro.
  mat->valor = (float*)malloc(m*n*sizeof(float)); //Se não há memória suficiente para a Matriz, desaloca a memória que anteriormente foi alocada.

  return mat; //retorna a struct criada, com os valores de linha, coluna e valor alocado.

}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
void libera(Matriz* mat){ // Função criada paraLiberar a memoria de uma Matriz

  free(mat->valor); // Chamada da função "free", liberando o espaço de memória consumido pelo valor informado pelo usuário na váriavel 'valor'.
  free(mat); // Comando que libera o valor alocado anteriormete anterior da struct 'mat'.

}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
float acessa(Matriz* mat, int i, int j) { // Função criada para o usuário acessar a matriz a partir do comando "acessa();"

  int k; // Indica o elemento no vetor.

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) { // Condição criada que verifica se a varivel i é menor que 0 ou i maior ou igual ao numero de linhas alocado dentro da struct mat ou se a variavel j é menor que 0 ou j maior ou igual ao numero de colunas dentro da struct mat. 
    printf("Acesso invalido!\n"); // Imprime mensagem para o usuario de acesso inválido caso a matriz não seja quadrada.
    exit(1); // Encerra a aplicação.
  }

  k = i * mat->coluna + j;// // Variavel K ta pegando a variavel i e multiplicando o valor da coluna de struct mat + a variavel j

  return mat->valor[k]; // Retorna o Valor da struct mat que foi passado na variavel K.
}

// Observe a funcao e explique o funcionamento? Comente cada linha explicando cada item.
void atribui(Matriz* mat, int i, int j, float valor) { // Atribui o valor ao elemento [i][j].

  int k;//Indica o elemento no vetor.

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {
    printf("Atribuicao invalida!\n");
    exit(1);
  }

  k = i * mat->coluna + j; // Variavel K ta pegando a variavel i e multiplicando o valor da coluna de struct mat + a variavel j

  mat->valor[k] = valor; // Valor da struct mat na posiçao K está recebendo valor

}

// Observe a funcao e explique o funcionamento?
int linhas(Matriz* mat){//Função criada para mostrar quantas linhas a struct mat tem, recebendo a mesma como parâmetro.

  return mat->linha;//A função retorna o número de linhas da struct mat, fazendo o acesso com o '->'.

}

// Observe a funcao e explique o funcionamento?
int colunas(Matriz* mat){ // Função criada para mostrar quantas colunas a struct mat tem, recebendo a mesma como parâmetro.

  return mat->coluna; // A função retorna o número de colunas da struct mat, fazendo o acesso com o '->'.

}
#include <stdio.h>

int main(void) {

  char resposta;
  int n, i, j;
  int respostaMenu;

  printf("\nDeseja criar a matriz? ");
  scanf("%c", &resposta);

  if(resposta == 'S' || resposta == 's'){
    int lines, columns;

    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &lines);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &columns);

    Matriz *m1 = cria(lines, columns);

    while(respostaMenu != 8){
      printf("\nAcesse as demais funcoes:\n1-Libera.\n2-Acessar.\n3-Atribui.\n4-Linhas.\n5-Colunas.\n6-Extremidades\n7-Matriz abaixo Diagonal secundaria\n8-Sair\n");
      scanf("%d", &respostaMenu);

      switch(respostaMenu){
        case 1:
          libera(m1);
          printf("\nMemoria liberada!");
        break;

        case 2:
          printf("\nSessao para acesso: \n");
          for(int i =0; i < lines; i++){
            for(int j=0; j < columns; j++){
              printf("\n= %.2f.", acessa(m1, i, j));
            }
          }
        break;

        case 3:
          printf("\nSessao de atribuicao: \n");
          float valor;
          for(int i =0; i < lines; i++){
            for(int j=0; j < columns; j++){
              printf("\n Digite um valor para a posicao [%d][%d]: ", i, j);
              scanf("%f", &valor);
              
              atribui(m1, i, j, valor);
            }
          }
        break;

        case 4:
          printf("\nNumero de linhas: %d", linhas(m1));
        break;

        case 5:
          colunas(m1);
          printf("\nNumero de colunas: %d", m1->coluna);
        break;

        case 6:
          printf("\nQuatro extremidades da matriz: \n");
          printf("\n\nExtremidades: %.2f, %.2f, %.2f e %.2f", acessa(m1, 0, 0), acessa(m1, columns-1, 0), acessa(m1, 0, columns-1), acessa(m1, lines-1, columns-1));
        break;

        case 7:
          printf("\nMatriz abaixo da diagonal segundaria");
            for (i = 0; i < columns; i++) {
              printf("\n");
              for (j = 0; j < columns; j++) {
                if (j > columns-i) {
                  printf("\n= %.2f.", acessa(m1, i, j));
                }
              }
            }
        break;

        case 8:
          printf("\n\n -= Saindo =-");
          libera(m1);
          exit(1);t
        break;
        
        default :
          printf ("Valor invalido!\n");
          exit(1);
        }
    }
    
    }else if(resposta == 'N' || resposta == 'n'){
      printf("\nEncerrando o programa.");      
    }
return 0;
}



/*
Comente o codigo explicando as funcoes conforme solicitado.
O codigo devera ser apresentado e explicado pelo grupo em aula.
Implemente a main de forma que todas as funcoes sejam utilizadas amplamente pelo usuario.
Ao executar o programa deve ser solicitado ao usuario se deseja criar a matriz: 
  SIM: 
    -Executar a funcao de criacao da matriz.
    -Em seguida deve abrir um menu que permita utilizar amplamente as demais funcoes.
    -Implemente uma opcao que imprime as quatro extremidades da matriz.
    -Implemente a opcao especifica de seu grupo.
    -O programa devera executar ate que o usuario escolha a opcao sair, liberando a memoria e encerrando a execucao do programa.
  NAO: 
    -Encerrar a execucao do programa.



Grupo 4:
-Implemente uma opcao que imprime todos os numeros abaixo da diagonal secundario, essa opcao somente pode funcionar se for matriz quadrada quando a quantidade de linhas e colunas sao iguais. */
