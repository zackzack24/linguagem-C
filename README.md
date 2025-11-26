<header> 
  
<p align="center">
  <img width="25%" height="25%" alt="C_Logo" src="https://github.com/user-attachments/assets/5c851c77-55a5-49bc-bc1f-e27959451cb9">
</p>

<div style="display: flex; justify-content: center; gap: 10px;">
  <img src="https://img.shields.io/badge/Linguagem-C-blue" alt="Linguagem C">
  <img src="https://img.shields.io/badge/IDE-VISUAL STUDIO CODE-green" alt="Visual Studio Code">
  <img src="https://img.shields.io/badge/Status-Em%20Desenvolvimento-orange" alt="Status Em Desenvolvimento">
</div>

</header>

<p align="center">
Este é o repositório para estudos da linguagem C.
</p>

<body>

# Veja Conceitos Básicos da Linguagem C

## Hello World
```c 
// esses comandos chamam algumas das bibliotecas da Linguagem C
#include <stdio.h> // biblioteca de saída 
#include <stdlib.h> // biblioteca de funções básicas do Sistema
#include <locale.h> // biblioteca para que a acentuação funcione

//Olá Mundo em C
int main() {  // Função Main, sempre serve como ponto de entrada de qualquer programa em C   
      setlocale(LC_ALL,"Portuguese"); // configuração para o idioma português      
      system("color 1F"); //  mudança da cor do texto no terminal
      printf("\nHello World!"); // Função que imprime o Hello World!
      printf("\nOlá Mundo!\n"); // Função em Português   
      system("cls"); // comando para limpar a tela
      system("pause"); 
      return 0; // Valor de Retorno da Função Main
}
```

## Variáveis 

| Tipos de Variável | Função |
| :----- | :-----: |
|  básicos |Armazenamento e Manipulação de Dados, Identificação de Informações, Funcionalidades em Funções, Controle de Memória...| 
| derivados | Usados em Operações um pouco mais complexas como Funções, Matrizes, Estruturas Complexas de Dados, Argumentos de Funções, Uniões... | 
## Exemplos de Variáveis Básicas

| Nome | Função | Exemplo | Bits |
| :----- | :-----: | :-----: | :-----: |
| int | Guarda um número inteiro | `int numero = 999;` | 8 |
| char | Representa Caracteres | `char c = 'a';` | 8 |
| float | Usado para números decimais com precisão de 7 digitos |  `float f = 12.34; ` | 32 |
| double |  Usado para números decimais com precisão de 15 ou mais digitos | ` double pi = 3.14159265359...      ` | 64 |
| void | Usados para indicar valores nulos, entidades sem valor | ` void v;      ` | Não se aplica |
|Modificadores|
| short | Indica um tipo inteiro com um tamanho **reduzido**, geralmente otimizado para economizar espaço.   | `       ` |Não se aplica |
| long  | Indica um tipo inteiro com um tamanho **aumentado** para armazenar valores maiores. | `       ` |Não se aplica |
| signed  | Indica que a variável pode armazenar ambos os valores, positivos e negativos, além de zero. | `       ` | Não se aplica|
| unsigned  | Indica que a variável pode armazenar apenas valores não negativos (zero e positivos). | `       ` |Não se aplica |

## Exemplos em Linhas de Código
```c
// Variável é o identificador dado ao local da memória do computador que armazena dados
// Vou colocar aqui representações práticas das variáveis básicas, também vou fazer uma tabela das variáveis deriva
```

</body>

<div id="frieren-C" align="center">
<img width=50% height=25% src="assets/Frieren with the book _The C programming language_.jpeg">
</div>