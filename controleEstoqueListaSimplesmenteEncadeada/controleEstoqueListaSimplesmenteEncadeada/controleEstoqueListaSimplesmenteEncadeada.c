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

void inserir_elemento_ordenado_idade(LISTA *l, REGISTRO reg){
     setlocale(LC_ALL, "Portuguese");
     PONT atual = NULL;
     PONT ant = NULL;
     PONT novo = NULL;
     novo = (PONT) malloc(sizeof(ELEMENTO));
      if(novo == NULL){
        printf("\n\nErro de alocação!");
    }

    novo->reg = reg;
    novo->prox = NULL;

    atual = l->inicio;

    while(atual != NULL && atual->reg.idade < reg.idade){
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

void inserir_elemento_ordenado_pais(LISTA *l, REGISTRO reg){
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

    while(atual != NULL && (stricmp(atual->reg.pais, reg.pais)<0)){
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

void inserir_elemento_ordenado_qtdEstoque(LISTA *l, REGISTRO reg){
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

    while(atual != NULL && atual->reg.qtdEstoque < reg.qtdEstoque){
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
        printf("~ Lista de produtos ~");
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
    int posicao = 0;
    while(aux != NULL && aux->reg.chave != ch){
        aux = aux->prox;
        posicao++;
    }
    if(aux != NULL){
        if(aux->reg.chave == ch){
            printf("\nWhisky na posição %i (de acordo com a ordenação selecionada).\n",posicao);
            return aux;
        }
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




