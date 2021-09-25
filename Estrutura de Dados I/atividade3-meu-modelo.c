/*
 ============================================================================
 Name        : atividade3-meu-modelo.c
 Author      : Vitor Pinheiro
 Version     :
 Copyright   : Universidade FUMEC
 Description : Atividade Avaliativa 03 - Discursiva
 ============================================================================
 */
/* Recursividade */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    char nome[40];
    int codigo;
    double preco;
    int quantidade;
} produto;

//Protótipos
void menuOpcao();
produto* preencherDados();
void cadastrarProduto(int*);
void cadastrarNome(char nome[], int i);
void cadastrarPreco(double *preco, int i);
int cadastrarCodigo(int i);
void cadastrarQuantidade(produto*,int);

int main(){
    int total = 0;
    produto* produtos; 
    char digito;
    int cadastrados, i, limite;
    produtos = preencherDados(&limite);
    fflush(stdin);
    do{
        menuOpcao();
        scanf("%c", &digito);
        switch(digito){
            case 'A':
                cadastrados = 0;
                cadastrarProduto(&cadastrados);
                int atual =(total+cadastrados);
                if(atual <= limite){
                for(i=total; i< atual; i++)
                {
                    cadastrarNome(produtos[i].nome, i);
                    cadastrarPreco(&produtos[i].preco, i);
                    produtos[i].codigo = cadastrarCodigo(i);
                    cadastrarQuantidade(produtos, i);
                    total++;
                    cadastrados--;
                }
                }else{
                    printf("\n\n***Impossível cadastrar mais que a quantidade máxima de produtos!***\n");
                }
                fflush(stdin);
            break;
            case 'B':
                printf("\n\n+======================== PRODUTOS ========================+\n");
                for (i=0; i< total; i++)
                {
                     printf("%i - Nome: %s - Código: %i - Preço: R$%.2lf - Quantidade: %i\n", i+1, produtos[i].nome, produtos[i].codigo, produtos[i].preco, produtos[i].quantidade);
                }
                printf("+==========================================================+\n");
                fflush(stdin);
            break;
        }

    if(!(digito == 'A' || digito == 'B' || digito == 'C')){
        printf("\n\n***Digite uma opção válida!***");
    }
    }while (digito != 'C');
    printf("\n\n+================= [PROGRAMA FINALIZADO!] =================+");
}


//Funções de Cadastro
void cadastrarNome(char nome[], int i){
    printf("\n\nInforme o nome do produto %i: ", i+1);
    scanf("%s", nome);
    fflush(stdin);
}

void cadastrarPreco(double *preco, int i){
    do{
        printf("\nInforme o preço do produto %i: ",i+1);
        scanf("%lf", preco);
        if(*preco <= 0){
            printf("\n***Digite um preço válido!***");
        }
    }while(*preco <= 0);
    fflush(stdin);
}

int cadastrarCodigo(int i){
    int codigo;
    do{
    printf("\nInforme o código do produto %i: ",i+1);
    scanf("%i", &codigo);
    if(codigo <= 0 || codigo >50){
        printf("\n***Digite um código válido!***");
    }
    } while(codigo <= 0 || codigo >50);
    fflush(stdin);
    return codigo;
}

void cadastrarQuantidade(produto *listaProdutos, int i){
    int quantidade;
    do{
    printf("\nInforme a quantidade do produto %i: ",i+1);
    scanf("%i", &quantidade);  
    if(quantidade < 0){
        printf("\n***Digite uma quantidade válida!***");
    }
    }while(quantidade < 0);
    listaProdutos[i].quantidade = quantidade;
    fflush(stdin);
}

//Função de alocação dinâmica
produto* preencherDados(int *limite){
    do{
        printf("\n\nInforme a quantidade máxima de produtos no programa: ");
        scanf("%i", limite);
        if(*limite <= 0){
            printf("\n***Digite uma quantidade máxima de produtos válido!***");
        }
    }while(*limite <= 0);
    produto* ptr_produto = (produto*)malloc(*limite * sizeof(produto));
    return ptr_produto;
}

void cadastrarProduto(int *quantidade){
    do{
        printf("\n\nInforme a quantidade que deseja cadastrar: ");
        scanf("%i", quantidade);
        if(*quantidade <= 0){
            printf("\n***Digite uma quantidade de produtos válido!***");
        }
    }while(*quantidade <= 0);
}

//função com as opções do menu
void menuOpcao(){
    printf("\n\nMenu Principal\nA – Cadastrar produtos\nB – Exibir produtos cadastrados no estoque\nC – Finalizar\nDigite a letra desejada: ");
}