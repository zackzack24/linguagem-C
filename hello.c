// esses comandos chamam algumas das bibliotecas do C
#include <stdio.h> // biblioteca de saída 
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

// aula 1: Olá Mundo em C
int main() {      
      setlocale(LC_ALL,"Portuguese"); // configuração para o idioma português      
      system("color 1F"); //  mudança da cor do texto no terminal
      printf("\nHello World!");
      printf("\nOlá Mundo!\n");     
      system("cls"); // comando para limpar a tela
      printf("Isaac Silva");
      system("pause");
      return 0;
}

     
