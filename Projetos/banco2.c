#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTES 100
#define MAX_NOME 50
#define ARQUIVO_DADOS "contas.bin"

typedef struct
{
      int numero;             // número único da conta
      char titular[MAX_NOME]; // nome do titular (terminado em '\0')
      float saldo;            // saldo da conta
} Conta;

static Conta contas[MAX_CLIENTES];
static int totalContas = 0;
static int proximoNumeroConta = 1;

//
void carregarDados(void);
void salvarDados(void);
void limparEntrada(void);
void lerString(const char *prompt, char *buffer, size_t tamanho);
int lerInt(const char *prompt);
float lerFloat(const char *prompt);
int encontrarIndicePorNumero(int numero);
void criarConta(void);
void depositar(void);
void sacar(void);
void transferir(void);
void consultarSaldo(void);
void listarContas(void);
void excluirConta(void);
void atualizarTitular(void);
void menu(void);

// Implementações
void carregarDados(void)
{
      FILE *f = fopen(ARQUIVO_DADOS, "rb");
      if (!f)
            return; // arquivo pode não existir na primeira execução
      if (fread(&proximoNumeroConta, sizeof(int), 1, f) != 1)
      {
            fclose(f);
            return;
      }
      if (fread(&totalContas, sizeof(int), 1, f) != 1)
      {
            fclose(f);
            return;
      }
      if (totalContas > 0 && totalContas <= MAX_CLIENTES)
      {
            fread(contas, sizeof(Conta), totalContas, f);
      }
      fclose(f);
}

void salvarDados(void)
{
      FILE *f = fopen(ARQUIVO_DADOS, "wb");
      if (!f)
      {
            printf("Erro ao salvar dados em arquivo.\n");
            return;
      }
      fwrite(&proximoNumeroConta, sizeof(int), 1, f);
      fwrite(&totalContas, sizeof(int), 1, f);
      if (totalContas > 0)
            fwrite(contas, sizeof(Conta), totalContas, f);
      fclose(f);
}

void limparEntrada(void)
{
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
      {
      }
}

void lerString(const char *prompt, char *buffer, size_t tamanho)
{
      printf("%s", prompt);
      if (fgets(buffer, (int)tamanho, stdin) == NULL)
      {
            buffer[0] = '\0';
            return;
      }
      // remove newline final se existir
      size_t len = strlen(buffer);
      if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
}

int lerInt(const char *prompt)
{
      int valor;
      char linha[64];
      while (1)
      {
            printf("%s", prompt);
            if (!fgets(linha, sizeof(linha), stdin))
                  return 0;
            if (sscanf(linha, "%d", &valor) == 1)
                  return valor;
            printf("Entrada inválida. Digite um número inteiro.\n");
      }
}

float lerFloat(const char *prompt)
{
      float valor;
      char linha[64];
      while (1)
      {
            printf("%s", prompt);
            if (!fgets(linha, sizeof(linha), stdin))
                  return 0.0f;
            if (sscanf(linha, "%f", &valor) == 1)
                  return valor;
            printf("Entrada inválida. Digite um número válido (ex: 100.50).\n");
      }
}

int encontrarIndicePorNumero(int numero)
{
      for (int i = 0; i < totalContas; i++)
      {
            if (contas[i].numero == numero)
                  return i;
      }
      return -1;
}

void criarConta(void)
{
      if (totalContas >= MAX_CLIENTES)
      {
            printf("Limite de contas atingido (%d).\n", MAX_CLIENTES);
            return;
      }
      Conta nova;
      nova.numero = proximoNumeroConta++;
      lerString("Nome do titular: ", nova.titular, sizeof(nova.titular));
      if (strlen(nova.titular) == 0)
      {
            printf("Titular não pode ser vazio. Operação cancelada.\n");
            return;
      }
      nova.saldo = 0.0f;
      contas[totalContas++] = nova;
      salvarDados();
      printf("Conta criada com sucesso! Número: %d\n", nova.numero);
}

void depositar(void)
{
      int numero = lerInt("Número da conta: ");
      int idx = encontrarIndicePorNumero(numero);
      if (idx == -1)
      {
            printf("Conta não encontrada.\n");
            return;
      }
      float valor = lerFloat("Valor do depósito: ");
      if (valor <= 0.0f)
      {
            printf("Valor inválido para depósito.\n");
            return;
      }
      contas[idx].saldo += valor;
      salvarDados();
      printf("Depósito realizado. Saldo atual: R$ %.2f\n", contas[idx].saldo);
}

void sacar(void)
{
      int numero = lerInt("Número da conta: ");
      int idx = encontrarIndicePorNumero(numero);
      if (idx == -1)
      {
            printf("Conta não encontrada.\n");
            return;
      }
      printf("Seu Saldo atual é: R$ %.2f\n", contas[idx].saldo);
      float valor = lerFloat("Valor do saque: ");
      if (valor <= 0.0f)
      {
            printf("Valor inválido para saque.\n");
            return;
      }
      if (valor > contas[idx].saldo)
      {
            printf("Saldo insuficiente. Saldo atual: R$ %.2f\n", contas[idx].saldo);
            return;
      }
      contas[idx].saldo -= valor;
      salvarDados();
      printf("Saque efetuado. Saldo atual: R$ %.2f\n", contas[idx].saldo);
}

void transferir(void)
{
      int origem = lerInt("Número da conta de origem: ");
      int idxOrig = encontrarIndicePorNumero(origem);
      if (idxOrig == -1)
      {
            printf("Conta de origem não encontrada.\n");
            return;
      }

      int destino = lerInt("Número da conta de destino: ");
      int idxDest = encontrarIndicePorNumero(destino);
      if (idxDest == -1)
      {
            printf("Conta de destino não encontrada.\n");
            return;
      }

      if (idxOrig == idxDest)
      {
            printf("Origem e destino são a mesma conta.\n");
            return;
      }

      float valor = lerFloat("Valor a transferir: ");
      if (valor <= 0.0f)
      {
            printf("Valor inválido.\n");
            return;
      }
      if (valor > contas[idxOrig].saldo)
      {
            printf("Saldo insuficiente na conta de origem.\n");
            return;
      }

      contas[idxOrig].saldo -= valor;
      contas[idxDest].saldo += valor;
      salvarDados();
      printf("Transferência concluída. Saldo origem: R$ %.2f | Saldo destino: R$ %.2f\n",
             contas[idxOrig].saldo, contas[idxDest].saldo);
}

void consultarSaldo(void)
{
      int numero = lerInt("Número da conta: ");
      int idx = encontrarIndicePorNumero(numero);
      if (idx == -1)
      {
            printf("Conta não encontrada.\n");
            return;
      }
      printf("Titular: %s\nSaldo: R$ %.2f\n", contas[idx].titular, contas[idx].saldo);
}

void listarContas(void)
{
      if (totalContas == 0)
      {
            printf("Nenhuma conta cadastrada.\n");
            return;
      }
      printf("=== CONTAS CADASTRADAS ===\n");
      for (int i = 0; i < totalContas; i++)
      {
            printf("Conta Nº %d | Titular: %s | Saldo: R$ %.2f\n",
                   contas[i].numero, contas[i].titular, contas[i].saldo);
      }
}

void excluirConta(void)
{
      int numero = lerInt("Número da conta a ser excluída: ");
      int idx = encontrarIndicePorNumero(numero);
      if (idx == -1)
      {
            printf("Conta não encontrada.\n");
            return;
      }
      // confirmação simples
      char resp[8];
      printf("Confirmar exclusão da conta %d (S/N)? ", numero);
      if (!fgets(resp, sizeof(resp), stdin))
            return;
      if (toupper((unsigned char)resp[0]) != 'S')
      {
            printf("Exclusão cancelada.\n");
            return;
      }

      // mover elementos à esquerda
      for (int i = idx; i < totalContas - 1; i++)
            contas[i] = contas[i + 1];
      totalContas--;
      salvarDados();
      printf("Conta %d excluída com sucesso.\n", numero);
}

void atualizarTitular(void)
{
      int numero = lerInt("Número da conta a ser atualizada: ");
      int idx = encontrarIndicePorNumero(numero);
      if (idx == -1)
      {
            printf("Conta não encontrada.\n");
            return;
      }
      char novoTitular[MAX_NOME];
      lerString("Novo nome do titular: ", novoTitular, sizeof(novoTitular));
      if (strlen(novoTitular) == 0)
      {
            printf("Nome inválido. Operação cancelada.\n");
            return;
      }
      strcpy(contas[idx].titular, novoTitular);
      salvarDados();
      printf("Titular atualizado com sucesso.\n");
}

void menu(void)
{
      carregarDados();
      int opcao;
      do
      {
            printf("\n=== SISTEMA BANCÁRIO ===\n");
            printf("1 - Criar Conta\n");
            printf("2 - Depositar\n");
            printf("3 - Sacar\n");
            printf("4 - Transferir\n");
            printf("5 - Consultar Saldo\n");
            printf("6 - Listar Contas\n");
            printf("7 - Atualizar Titular\n");
            printf("8 - Excluir Conta\n");
            printf("9 - Sair\n");
            opcao = lerInt("Escolha uma opção: ");

            switch (opcao)
            {
            case 1:
                  criarConta();
                  break;
            case 2:
                  depositar();
                  break;
            case 3:
                  sacar();
                  break;
            case 4:
                  transferir();
                  break;
            case 5:
                  consultarSaldo();
                  break;
            case 6:
                  listarContas();
                  break;
            case 7:
                  atualizarTitular();
                  break;
            case 8:
                  excluirConta();
                  break;
            case 9:
                  printf("Saindo...\n");
                  break;
            default:
                  printf("Opção inválida. Tente novamente.\n");
            }
      } while (opcao != 9);
}

int main(void)
{
      menu();
      return 0;
}
