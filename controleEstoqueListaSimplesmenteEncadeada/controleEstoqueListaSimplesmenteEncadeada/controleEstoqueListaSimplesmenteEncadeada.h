#ifndef CONTROLEESTOQUELISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define CONTROLEESTOQUELISTASIMPLESMENTEENCADEADA_H_INCLUDED


typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    char nome[50];
    float precoDeVenda;
    int idade;
    char pais[50];
    char codigoDoProduto[5];
    int qtdEstoque;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

void inicializarLista(LISTA *l);

void inserir_elemento_ordenado_idade(LISTA *l, REGISTRO reg);
void inserir_elemento_ordenado_pais(LISTA *l, REGISTRO reg);
void inserir_elemento_ordenado_qtdEstoque(LISTA *l, REGISTRO reg);

PONT busca_elemento(LISTA *l, TIPOCHAVE ch);
int excluir_elemento(LISTA *l, TIPOCHAVE ch);
void imprimir(LISTA *l);
void reinicializar(LISTA *l);


#endif // CONTROLEESTOQUELISTASIMPLESMENTEENCADEADA_H_INCLUDED
