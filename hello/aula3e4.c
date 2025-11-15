// esses comandos chamam algumas das bibliotecas do C
#include <stdio.h> // biblioteca de saída 
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

// aula 3 e 4: Variaveis e tipos de dados em C
int main(int argc, char *argv[])
{
      int idade; // declaração da variável idade do tipo inteiro
      printf("Digite sua idade: "); // pede para o usuário digitar a idade
      scanf("%d", &idade); // lê a idade digitada e armazena na variável
      printf("idade: %d", idade); // imprime a idade armazenada

      // estrutura de decisão
      if (idade >= 18) {
            printf("\nVocê é maior de idade!\n");
      } else {
            printf("\nVocê é menor de idade!\n");
      }
      // como permitir somente números inteiros positivos
      if (idade < 0) {
            printf("\nIdade inválida! Digite um número positivo.\n");
      }
      // outra estrutura de decisão
      // switch (idade)
      //  {
      //       case 18:
      //             printf("Você tem 18 anos!\n");
      //             break;
      //       case 25:
      //             printf("Você tem 25 anos!\n");
      //             break;
      //       default:
      //             printf("Idade não cadastrada!\n");
      //             break;
      // }

      system("pause"); // pausa o programa até que uma tecla seja pressionada
      return 0;
}