/*
Trab_2 - Controle Estoque (Lista Encadeada Estática e Lista Simplesmente Encadeada)

Especificações:

-DUPLA:

      -Aluno A: Focar no desenvolvimento de Lista Encadeada Estática

      -Aluno B: Focar no desenvolvimento de Lista Simplesmente Encadeada Dinâmica

      OBS1: porém, as explicações do funcionamento do código serão Aluno A -> Lista Dinâmica e Aluno B -> Lista Estática (sim, trocado).

      OBS2: Pode-se utilizar 3 ajudas do colega de grupo durante a entrevista.


Informações que devem conter em cada REGISTRO:

           -Nome

           -Preço de venda

          - Idade

          -País

          -Código do Produto

         -Quantidade em Estoque

Programa: Controle de Estoque de Whisky (básico):

       -Inserir

       -Inicializar

       -Reinicializar

       -Busca

       -Excluir

       -Imprimir

      -Ordenação: Idade, Quantidade e País.

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
        printf("\n\nErro de alocação: inserir_elemento");
    }

    novo->reg = reg; //recebe o registro
    novo->prox = NULL; // deixa o prox NULL para não ter lixo na memoria
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
        printf("\n\nErro de alocação: inserir_elemento_ordenado");
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
        printf("Preço de venda: R$ %.2f \n", aux->reg.precoDeVenda);
        printf("Idade: %i \n", aux->reg.idade);
        printf("País: %s \n", aux->reg.pais);
        printf("Código do produto: %s \n", aux->reg.codigoDoProduto);
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
        printf("\nERRO! Valor digitado inválido!");
    }
    else{
        if(ant == NULL){
            l->inicio = atual->prox;
        }
        else{
            ant->prox = atual->prox;
        }
        free(atual);
        printf("\nExclusão feita com sucesso!");
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




