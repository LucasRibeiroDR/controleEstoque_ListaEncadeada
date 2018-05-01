#include <stdio.h>
#include <stdlib.h>
#include "controleEstoqueListaSimplesmenteEncadeada.h"
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <strings.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    LISTA lista;
    REGISTRO reg;
    int listaInicializada=0;
    int opcaoMenu=-1;
    int id=-1;
    int opcaoInserir=0;
    ///opcao de menu = de 1 a 7
    printf("~ Regra de inserção ~ ");
    while(opcaoInserir!=1 && opcaoInserir!=2 && opcaoInserir!=3){
        printf("\n\nDigite '1' para inserir ordenado pela idade da bebida (ordem crescente).");
        printf("\nDigite '2' para inserir ordenado pela quantidade de estoque (ordem crescente).");
        printf("\nDigite '3' para inserir ordenado alfabeticamente pelo pais da bebida (ordem alfabética).\n\n");
        scanf("%i",&opcaoInserir);
        fflush(stdin);
        system("cls");
        if(opcaoInserir!=1 && opcaoInserir!=2 && opcaoInserir!=3){
            printf("~ Regra de inserção ~ ");
            printf("\n\nERRO! Opção inválida! Digite novamente!");
        }
    }


    while(opcaoMenu!=7){

        printf("\n\n~ MENU ~\n\n1-Inicializar\n2-Inserir\n3-Reinicializar\n4-Buscar\n5-Excluir\n6-Imprimir\n7-Finalizar Programa");
        printf("\n\nDigite a opção desejada: ");
        scanf("%i",&opcaoMenu);
        fflush(stdin);

        if((opcaoMenu!=1 && opcaoMenu!=2 && opcaoMenu!=3 && opcaoMenu!=4 && opcaoMenu!=5 && opcaoMenu!=6 && opcaoMenu!=7)){
            system("cls");
            printf("\n\nERRO! OPÇÃO INVÁLIDA!");
        }

        if(opcaoMenu==1){
            system("cls");
            inicializarLista(&lista);
            printf("\n\nLista inicializada!\n\n");
            listaInicializada=1;
        }
        if(opcaoMenu==2){
            if(listaInicializada==0){
                system("cls");
                printf("\n\nERRO! LISTA NÃO INICIALIZADA!");
            }else{
                id++;
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

                if(opcaoInserir==1){
                    inserir_elemento_ordenado_idade(&lista, reg);
                }
                if(opcaoInserir==2){
                    inserir_elemento_ordenado_pais(&lista, reg);
                }
                if(opcaoInserir==3){
                    inserir_elemento_ordenado_qtdEstoque(&lista, reg);
                }
                system("cls");
                printf("\n\nBebida cadastrada!\n");
                printf("ID: %i",id);
            }
        }
        if(opcaoMenu==3){

            if(listaInicializada==0){
                system("cls");
                printf("\n\nERRO! LISTA NÃO INICIALIZADA!");
            }else{
                system("cls");
                reinicializar(&lista);
                printf("\n\nLista reinicializada!\n\n");
                id=-1;

            }
        }
        if(opcaoMenu==4){
            if(listaInicializada==0){
                system("cls");
                printf("\n\nERRO! LISTA NÃO INICIALIZADA!");
            }else{
                system("cls");
                TIPOCHAVE chave;
                printf("Busca de whisky(s)\n\n");
                printf("\nDigite o ID do Whisky: ");
                scanf("%i",&chave);
                fflush(stdin);
                busca_elemento(&lista, chave);
            }
        }
        if(opcaoMenu==5){
            if(listaInicializada==0){
                system("cls");
                printf("\n\nERRO! LISTA NÃO INICIALIZADA!");
            }else{
            system("cls");
            printf("Exclusão de whisky(s)\n\n");
            TIPOCHAVE chave=0;
            printf("\nDigite o ID do Whisky: ");
            scanf("%i",&chave);
            fflush(stdin);
            excluir_elemento(&lista, chave);
        }
        }
        if(opcaoMenu==6){
            if(listaInicializada==0){
                system("cls");
                printf("\n\nERRO! LISTA NÃO INICIALIZADA!");
            }else{
                system("cls");
                if(id<0){
                    printf("\nLista de produtos VAZIA!\n");
                }else{
                    imprimir(&lista);
                }
            }
        }
        if(opcaoMenu==7){
            exit(0);
        }
    }
    return 0;
}
