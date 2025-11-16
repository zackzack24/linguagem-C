#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão para funções utilitárias
#include <string.h> // Inclui a biblioteca para manipulação de strings
#define MAX_CLIENTES 100 // Define o número máximo de clientes

// @brief significa uma estrutura para representar uma conta bancária

typedef struct {
      int numeros; // Número da conta
      char titular[50]; // Nome do titular da conta
      float saldo; // Saldo da conta
} Conta; // Define a estrutura Conta

Conta contas[100]; // Declara um array de contas
int totalContas = 0; // Inicializa o número de contas

void criarConta() {
      if(totalContas >= 100) {
            printf("Limite de contas atingido.\n");
            return;
      }

      Conta novaConta; // Declara uma nova conta
      novaConta.numeros = totalContas + 1; // Atribui um número à nova conta

      printf("Nome do titular: ");
      scanf(" %[^\n]", novaConta.titular); // Lê o nome do titular
      // %[^ \n] lê uma string até encontrar uma nova linha também pode ser usado o fgets 
      novaConta.saldo = 0.0; // Inicializa o saldo da conta
      contas[totalContas] = novaConta; // Adiciona a nova conta ao array
      totalContas++; // Incrementa o número total de contas

      printf("Conta criada com sucesso! Número da conta: %d\n", novaConta.numeros);
}

// @brief Função para depositar dinheiro em uma conta   
void depositar() {
      int numero; // int é usado para representar números inteiros
      float valor; // float é usado para representar números de ponto flutuante (números com casas decimais)
      
      printf("Número da conta: ");
      scanf("%d", &numero); // Lê o número da conta
      // & é usado para obter o endereço de uma variável

      printf("Valor do depósito: ");
      scanf("%f", &valor); // Lê o valor do depósito


      // Verifica se a conta existe 
      // || é o operador lógico "OU"  
      if(numero < 1 || numero > totalContas) {
            printf("Conta não encontrada no sistema. \n");
            return;
      }

      // Verifica se o valor do depósito é válido

      if(valor <= 0) {
            printf("Valor inválido para depósito.\n");
            return;
      }

      contas[numero -1].saldo += valor; // Adiciona o valor ao saldo da conta
      printf("Depósito realizado com sucesso! Novo saldo: %.2f\n", contas[numero-1].saldo);
}

void consultarSaldo() {
      int numero; // Declara uma variável para o número da conta

      printf("Número da conta: ");
      scanf("%d", &numero); // Lê o número da conta

      if(numero < 1 || numero > totalContas) {
            printf("Conta não encontrada no sistema.\n");
            return;
      } 

      printf("Titular: %s\n", contas[numero -1].titular); // Exibe o nome do titular
      printf("Saldo: R$ %.2f\n", contas[numero -1].saldo); // Exibe o saldo da conta
}

void listarContas() {
      if(totalContas == 0) {
            printf("Nenhuma conta cadastrada.\n");
            return;
      }

      printf("=== CONTAS CADASTRADAS ===\n");
      for(int i = 0; i < totalContas; i++) {
            printf("Conta Nº: %d, titular : %s, Saldo: R$ %.2f\n",
            contas[i].numeros, contas[i].titular, contas[i].saldo);
      }
}
void excluirConta() {
      int numero; // Declara uma variável para o número da conta

      printf("Número da conta a ser excluída: ");
      scanf("%d", &numero); // Lê o número da conta

      if(numero < 1 || numero > totalContas) {
            printf("Conta não encontrada no sistema.\n");
            return;
      }

      // Move todas as contas após a conta excluída uma posição para trás
      for(int i = numero -1; i < totalContas -1; i++) {
            contas[i] = contas[i +1];
      }
      totalContas--; // Decrementa o número total de contas
      printf("Conta Nº %d excluída com sucesso.\n", numero);
}

// @brief Função principal do programa
/* Definição duplicada de 'main' removida — o menu principal é definido mais abaixo. */

int main() {
      // Declaração de variáveis
      int opcao;
      // Exibe o menu do sistema bancário 
      printf("\n");
      printf(" === SISTEMA BANCÁRIO BRASIL VARONIL === \n" "\nESCOLHA A OPÇÃO DESEJADA:\n");
      // Loop principal do programa, pode ser usado while também
      do {
            printf("\1. 1 - Criar Conta \n");
            printf("\2. 2 - Depositar \n");
            printf("\3. 3 - Consultar Saldo \n");
            printf("\4. 4 - Sair do Sistema \n");
            printf("Escolha uma opçao: ");
            scanf("%d", &opcao);
            // Estrutura de decisão usando switch case, também pode ser usado if else
            switch(opcao) {
                  case 1: // Caso a opção seja 1
                  criarConta(); // Chama a função para criar uma conta
                  break; // Fim do case 1

                  case 2: // Caso a opção seja 2
                  depositar(); // Chama a função para depositar dinheiro
                  break; // Fim do case 2

                  case 3: // Caso a opção seja 3
                  consultarSaldo(); // Chama a função para consultar o saldo
                  break; // Fim do case 3

                  case 4: // Caso a opção seja 4
                  printf("Saindo do sistema. \n"); // Mensagem de saída
                  exit(0); // Sair do programa
            }
      } while(opcao != 4); // Continua o loop enquanto a opção não for 4
      return 0; // Retorna 0 para indicar que o programa terminou com sucesso 
} 
