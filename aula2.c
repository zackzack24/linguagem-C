// esses comandos chamam algumas das bibliotecas do C
#include <stdio.h> // biblioteca de saída 
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

// aula 2: Entrada de dados em C
int main(int argc, char *argv[])
{
      char nome[30]; // declaração da variável nome
      printf("Digite seu nome: "); // pede para o usuário digitar o nome
      // scanf("%s", nome);  lê o nome digitado e armazena na variável
      fgets(nome, 30, stdin); // lê o nome digitado com espaços e armazena na variável
      system("cls"); // comando para limpar a tela
      printf("Olá %s, seja bem-vindo!\n", nome); // imprime o nome armazenado
      // %s é o especificador de formato para strings
      system("pause"); // pausa o programa até que uma tecla seja pressionada
      return 0;
}