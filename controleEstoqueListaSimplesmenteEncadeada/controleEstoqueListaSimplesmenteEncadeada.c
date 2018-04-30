/*
Trab_2 - Controle Estoque (Lista Encadeada Est�tica e Lista Simplesmente Encadeada)

Especifica��es:

-DUPLA:

      -Aluno A: Focar no desenvolvimento de Lista Encadeada Est�tica

      -Aluno B: Focar no desenvolvimento de Lista Simplesmente Encadeada Din�mica

      OBS1: por�m, as explica��es do funcionamento do c�digo ser�o Aluno A -> Lista Din�mica e Aluno B -> Lista Est�tica (sim, trocado).

      OBS2: Pode-se utilizar 3 ajudas do colega de grupo durante a entrevista.


Informa��es que devem conter em cada REGISTRO:

           -Nome

           -Pre�o de venda

          - Idade

          -Pa�s

          -C�digo do Produto

         -Quantidade em Estoque

Programa: Controle de Estoque de Whisky (b�sico):

       -Inserir

       -Inicializar

       -Reinicializar

       -Busca

       -Excluir

       -Imprimir

      -Ordena��o: Idade, Quantidade e Pa�s.

*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "controleEstoqueListaSimplesmenteEncadeada.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <strings.h>

void inicializarLista(LISTA *l){
    l->inicio = NULL;
}
/*
void inserir_elemento(LISTA *l, REGISTRO reg){
    setlocale(LC_ALL, "Portuguese");
    PONT novo = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo == NULL){
        printf("\n\nErro de aloca��o: inserir_elemento");
    }

    novo->reg = reg; //recebe o registro
    novo->prox = NULL; // deixa o prox NULL para n�o ter lixo na memoria
    novo->prox = l->inicio;
    l->inicio = novo;
}*/

void inserir_elemento_ordenado(LISTA *l, REGISTRO reg){
     setlocale(LC_ALL, "Portuguese");
     PONT atual = NULL;
     PONT ant = NULL;
     PONT novo = NULL;
     novo = (PONT) malloc(sizeof(ELEMENTO));
      if(novo == NULL){
        printf("\n\nErro de aloca��o: inserir_elemento_ordenado");
    }

    novo->reg = reg;
    novo->prox = NULL;

    atual = l->inicio;

    while(atual != NULL && atual->reg.chave < reg.chave){
        ant = atual;
        atual = atual->prox;

    }

    novo->prox = atual;
    if(ant == NULL){
        l->inicio = novo;
    }else{
        ant->prox = novo;
    }
}

void imprimir(LISTA *l){
    PONT aux  = l->inicio;

    while(aux != NULL){
        printf("\n\nDados do Whisky\n\n");

        printf("Nome: %s \n", aux->reg.nome);
        printf("ID (chave): %i \n", aux->reg.chave);
        printf("Pre�o de venda: R$ %.2f \n", aux->reg.precoDeVenda);
        printf("Idade: %i \n", aux->reg.idade);
        printf("Pa�s: %s \n", aux->reg.pais);
        printf("C�digo do produto: %s \n", aux->reg.codigoDoProduto);
        printf("Quantidade em estoque: %i \n", aux->reg.qtdEstoque);

        aux = aux->prox;
    }
}


PONT busca_elemento(LISTA *l, TIPOCHAVE ch){
    PONT aux  = l->inicio;
    while(aux != NULL && aux->reg.chave < ch){
        aux = aux->prox;
    }
    if(aux != NULL && aux->reg.chave == ch){
        return aux;
    }

    return NULL;
}

int excluir_elemento(LISTA *l, TIPOCHAVE ch){
    PONT ant = NULL;
    PONT atual = l->inicio;

    while(atual != NULL && atual->reg.chave < ch){
        ant = atual;
        atual = atual->prox;

    }

    if(atual == NULL){
        printf("\nERRO! Valor digitado inv�lido!");
    }
    else{
        if(ant == NULL){
            l->inicio = atual->prox;
        }
        else{
            ant->prox = atual->prox;
        }
        free(atual);
        printf("\nExclus�o feita com sucesso!");
    }
}

void reinicializar(LISTA *l){
    PONT aux = l->inicio;
    while(aux != NULL){
        l->inicio = l->inicio->prox;
        free(aux);
        aux = l->inicio;
    }
}




