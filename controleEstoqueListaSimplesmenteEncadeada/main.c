#include <stdio.h>
#include <stdlib.h>
#include "controleEstoqueListaSimplesmenteEncadeada.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <strings.h>

///a fazer: ordenação, mensagens de confirmação


int main()
{
    setlocale(LC_ALL, "Portuguese");
    LISTA lista;
    REGISTRO reg;
    int opcaoMenu=-1;
    int id=0;
    ///opcao de menu = de 1 a 10
    while(opcaoMenu!=10){

        printf("\n\n~ MENU ~\n\n1-Inicializar\n2-Inserir\n3-Reinicializar\n4-Buscar\n5-Excluir\n6-Imprimir\n7-Ordenar por Idade\n8-Ordenar por quantidade\n9-Ordenar por país\n10-Sair");
        printf("\n\nDigite a opção desejada: ");
        scanf("%i",&opcaoMenu);
        fflush(stdin);

        if(opcaoMenu!=1 && opcaoMenu!=2 && opcaoMenu!=3 && opcaoMenu!=4 && opcaoMenu!=5 && opcaoMenu!=6 && opcaoMenu!=7 && opcaoMenu!=8 && opcaoMenu!=9 && opcaoMenu!=10){
            system("cls");
            printf("\n\nERRO! OPÇÃO INVÁLIDA!");
        }

        if(opcaoMenu==1){
            system("cls");
            inicializarLista(&lista);
            printf("\n\nLista inicializada!\n\n");
        }
        if(opcaoMenu==2){
            system("cls");
            printf("\n\nCadastro de bebidas\n\nDigite os dados sobre o Whisky\n\n");
            printf("Nome: ");
            gets(reg.nome);
            fflush(stdin);

            printf("Preço de venda(R$): ");
            scanf("%f",&reg.precoDeVenda);
            fflush(stdin);

            printf("Idade(anos): ");
            scanf("%i",&reg.idade);
            fflush(stdin);

            printf("País de origem: ");
            gets(reg.pais);
            fflush(stdin);

            printf("Código da bebida: ");
            gets(reg.codigoDoProduto);
            fflush(stdin);

            printf("Quantidade no estoque: ");
            scanf("%i",&reg.qtdEstoque);
            fflush(stdin);

            reg.chave = id;
            id++;

            inserir_elemento_ordenado(&lista, reg);
        }
        if(opcaoMenu==3){
            system("cls");
            reinicializar(&lista);
            printf("\n\nLista reinicializada!\n\n");
        }
        if(opcaoMenu==4){
            system("cls");
            printf("Busca de whisky(s)\n\n")
            TIPOCHAVE chave=0;
            printf("\nDigite o ID do Whisky: ");
            scanf("%i",&chave);
            fflush(stdin);
            busca_elemento(&lista, chave);
        }
        if(opcaoMenu==5){
            system("cls");
            printf("Exclusão de whisky(s)\n\n")
            TIPOCHAVE chave=0;
            printf("\nDigite o ID do Whisky: ");
            scanf("%i",&chave);
            fflush(stdin);
            excluir_elemento(&lista, chave);
        }
        if(opcaoMenu==6){
            system("cls");
            printf("Lista de produtos\n\n")
            imprimir(&lista);
        }
        if(opcaoMenu==7){

        }
        if(opcaoMenu==8){

        }
        if(opcaoMenu==9){

        }
        if(opcaoMenu==10){
            exit(0);
        }
    }



    /*reg.chave = 8;
    excluir_elemento(&lista, reg.chave);*/

   /* reg.chave = 10;
    if(busca_elemento(&lista, reg.chave) != NULL){
        printf("O elemento %d esta na lista.\n");
    }else{
        printf("\nO elemento %d nao esta na lista.\n");
    }

    reg.chave = 15;
    if(busca_elemento(&lista, reg.chave) != NULL){
        printf("O elemento %d esta na lista.\n");
    }else{
        printf("\nO elemento %d nao esta na lista.\n");
    }*/




    return 0;
}
