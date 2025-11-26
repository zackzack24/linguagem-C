#include <stdio.h>  // biblioteca de saída
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

int numero;

int main(int argc, char *argv[]) 
{
      // prinf serve para formatar e exibir os dados
      // O código usa a função printf() da linguagem C para imprimir várias linhas de texto na tela, 
      // formando um menu de sistemas operacionais. Ele utiliza sequências de escape, como \n, para pular para a linha seguinte, 
      // e as aspas duplas " " para delimitar as strings que serão exibidas. 
      printf("Sistemas\n\n"); // Imprime a palavra "Sistemas" e depois pula duas linhas, deixando um espaço em branco.
      printf("1 - Windows\n"); // Imprime "1 - Windows" e pula uma linha.
      printf("2 - Linux\n"); // Imprime "2 - Linux" e pula uma linha.
      printf("3 - Mac Os\n"); // Imprime "3 - Mac" e pula uma linha.
      printf("\nEscolha o Sistema Desejado: \n"); // Pula uma linha e Imprime Escolha o Sistema Desejado: e logo após pula uma linha.

      // scanf serve para ler os dados fornecidos pelo usuário
      // a linha e código com scanf é usada para ler um número inteiro da entrada padrão (teclado) e armazená-lo na variável numero. 
      // A função scanf lê a entrada do usuário e a formata de acordo com a string de formato passada, que neste 
      // caso é "%d" para indicar que um inteiro será lido. 
      // O & antes de numero fornece o endereço de memória da variável, onde o valor lido será armazenado. 
      scanf("%d", &numero); //  Esta é a função de entrada de dados em C. Ela lê caracteres da entrada padrão (geralmente o teclado), interpreta-os e os armazena nas variáveis fornecidas.
      // Uso do Switch Case
      switch (numero)
      {
      case 1:
            system("cls");
            printf("Iniciando Windows...\n");
            break;
      case 2:
            system("cls");
            printf("Iniciando Linux...\n");
            break;
      case 3:
            system("cls");
            printf("Iniciando Mac Os...\n");
            break;
      
      default:
            printf("Sistema Inválido!\n");
      }

      system("pause");
      return 0;
}

//  continuar de OQUE É UMA FUNÇÃO