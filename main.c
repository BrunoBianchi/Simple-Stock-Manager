#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando Estrutura
typedef struct stock
{
   char nome[255];
   int preco;
   int quantidade;
}stock;
// Criando Total de Items no stock
int totalstock= 0;

void criarstock(stock *stocks) {
    printf("Nome do item para ser adicionado ao stock: \n");
    getchar(); // Limpando Buffer!
    char text[255];
    fgets(text,255,stdin);
    // Retirando \n do text
    text[strlen(text) - 1] = '\0';
    strcpy(stocks[totalstock].nome,text);
    printf("Preco do item \n");
    scanf("%d",&stocks[totalstock].preco);
    getchar();
    printf("Quantidade \n");
    scanf("%d",&stocks[totalstock].quantidade);
    printf("Item %s criado \n", stocks[totalstock].nome);
    int opcao = 0;
    totalstock++;
    menu(stocks);
}

void listarstocks(stock *stocks) {
    for(int i = 0 ; i<totalstock;i++) {
        printf(" \nNome: %s\nQuantidade: %d\nPreco: %d \t \n",stocks[i].nome,stocks[i].quantidade,stocks[i].preco);
    }
    menu(stocks);
} 

void apagarItem(stock *stocks) {
    if(totalstock <= 0) {
        printf("Stock vazio!");
        menu(stocks);
    }
    printf("Qual Item Deseja Apagar? \n");
for(int i = 0; i <totalstock; i ++) {
    printf("%d. %s\n",i,stocks[i].nome);
}
int opcao =  0;
scanf("%d",&opcao);

if(opcao < 0 || opcao > totalstock) printf("Opcao invalida!");
// Mudando toda posicao a partir da opcao para o prox index!
for(int i = opcao; i<totalstock;i++) {
    int aux = i + 1;
    strcpy(stocks[i].nome,stocks[aux].nome);
    stocks[i].preco = stocks[aux].preco;
    stocks[i].quantidade = stocks[aux].quantidade;
}
// Diminuindo tamanho do stock
totalstock--;
menu(stocks);
}
void ModificarItem(stock *stocks) {
        if(totalstock <= 0) {
        printf("Stock vazio!");
        menu(stocks);
    }
printf("Qual Item Deseja Modificar? \n");
for(int i = 0; i <totalstock; i ++) {
    printf("%d. %s\n",i,stocks[i].nome);
}
int opcao =  0;
scanf("%d",&opcao);
if(opcao < 0 || opcao > totalstock) printf("Opcao invalida!");

printf("Preco: \n");
scanf("%d",&stocks[opcao].preco);
printf("Quantidade: \n");
scanf("%d",&stocks[opcao].quantidade);
printf("\n Item %s Modificado! \n",stocks[opcao].nome);

menu(stocks);
}

int menu(stock *stocks) {
    int opcao = 0;

    printf("\nMenu: \n1.Adicionar um item ao stock\n2.Listar items do stock\n3.Apagar item do estock\n4.Modificar item do stock\n");
   do{
    scanf("%d",&opcao);

    switch(opcao) {
        case 1:
        criarstock(stocks);
        break;
        case 2:
        listarstocks(stocks);
        break;
        case 3:
         apagarItem(stocks);
        break;
        case 4:
         ModificarItem(stocks);
        break;
        default: printf("Opcao Invalida, por favor escolha umas das opcoes: \n1.Adicionar um item ao stock\n2.Listar stock do stock\n3.ApagarItem do estock\n4.Remover/Adicionar quantias no stock\n ");
        opcao = 0;
        break;
    }
   }while( opcao == 0);

}
int main() {
stock stocks[255];
menu(stocks);

}