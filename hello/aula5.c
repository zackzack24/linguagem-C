// esses comandos chamam algumas das bibliotecas do C
#include <stdio.h> // biblioteca de saída 
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

// aula 5: Aplicativo para calcular média
int main(int argc, char *argv[])
{
      float n1, n2, n3, media; // declaração das variáveis do tipo float

      // entrada de dados
      printf("Digite a primeira nota: ");
      scanf("%f", &n1);
      printf("Digite a segunda nota: ");
      scanf("%f", &n2);
      printf("Digite a terceira nota: ");
      scanf("%f", &n3);

      // processamento
      media = (n1 + n2 + n3) / 3;

      // saída de dados
      printf("A média é: %.2f\n", media); // imprime a média com 2 casas decimais

      // estrutura de decisão para verificar se o aluno foi aprovado ou reprovado
      if (media >= 7.0) {
            printf("Aluno aprovado!\n");
      } else {
            printf("Aluno reprovado!\n");
      }

      system("pause"); // pausa o programa até que uma tecla seja pressionada
      return 0;
}