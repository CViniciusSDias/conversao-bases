#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binarioParaDecimal(char binario[]);
int octalParaDecimal(char octal[]);
int hexaParaDecimal(char hexa[]);
char* decimalParaBase(int valorEmDecimal, int baseDestino);
char* revertString(char* stringOrigem);
char valorEmNumeroOuLetra(int valorEmNumero);
int valorEmNumero(char numeroOuLetra);

int main(void)
{
  int base;
  int decimal = 0;
  printf("MENU\n");
  printf("1 - Para converter um número binario\n");
  printf("2 - Para converter um número decimal\n");
  printf("3 - Para converter um número hexadecimal\n");
  printf("4 - Para converter um número octal\n");
  printf("5 - Para sair do programa\n");
  printf("\nDigite a opção: ");
  scanf("%d", &base);

  switch (base) {
    case 1:
      printf("Digite o valor em binário:\n");
      char binario[20];
      setbuf(stdin, NULL);
      fgets(binario, 20, stdin);
      setbuf(stdin, NULL);
      decimal = binarioParaDecimal(binario);
      break;
    case 2:
      printf("Digite o valor em decimal:\n");
      setbuf(stdin, NULL);
      scanf("%d", &decimal);
      break;
    case 3:
        printf("Digite o valor em hexadecimal:\n");
        char hexa[20];
        setbuf(stdin, NULL);
        fgets(hexa, 20, stdin);
        setbuf(stdin, NULL);
        decimal = hexaParaDecimal(hexa);
      break;
    case 4:
      printf("Digite o valor em octal:\n");
      char octal[20];
        setbuf(stdin, NULL);
        fgets(octal, 20, stdin);
        setbuf(stdin, NULL);
        decimal = octalParaDecimal(octal);
      break;
    case 5:
    printf("\nSaindo...\n");
    exit(0);
  }

  printf("Número em binário: %s\n", decimalParaBase(decimal, 2));
  printf("Número em decimal: %d\n", decimal);
  printf("Número em octal: %s\n", decimalParaBase(decimal, 8));
  printf("Número em hexadecimal: %s", decimalParaBase(decimal, 16));

  return 0;
}

int binarioParaDecimal(char binario[])
{
  int tamanhoBinario = strlen(binario) - 1;
  int i = 0;
  int decimal = 0;
  while (tamanhoBinario) {
    int numeroAtual = binario[i++] - '0';
    int potenciaAtual = --tamanhoBinario;
    decimal = decimal + pow(2, potenciaAtual) * numeroAtual;
  }

  return decimal;
}

int hexaParaDecimal(char hexa[])
{
  int tamanhoHexa = strlen(hexa) - 1;
  int i = 0;
  int decimal = 0;
  while (tamanhoHexa) {
    int numeroAtual = valorEmNumero(hexa[i++]);
    int potenciaAtual = --tamanhoHexa;
    decimal = decimal + pow(16, potenciaAtual) * numeroAtual;
  }

  return decimal;
}

int octalParaDecimal(char octal[])
{
  int tamanhoOctal = strlen(octal) - 1;
  int i = 0;
  int decimal = 0;
  while (tamanhoOctal) {
    int numeroAtual = octal[i++] - '0';
    int potenciaAtual = --tamanhoOctal;
    decimal = decimal + pow(8, potenciaAtual) * numeroAtual;
  }

  return decimal;
}

char* decimalParaBase(int valorEmDecimal, int baseDestino)
{
  char valorNaBaseDestino[10] = "";
  int resultado;
  int i = 0;
  int valorOriginal = valorEmDecimal;

  do {
    if (valorOriginal < baseDestino) {
      sprintf(valorNaBaseDestino, "%s%c", valorNaBaseDestino, valorEmNumeroOuLetra(valorOriginal));
      return revertString(valorNaBaseDestino);
    }

    int tamanho = strlen(valorNaBaseDestino);
    resultado = valorOriginal / baseDestino;
    int resto = valorOriginal % baseDestino;

    sprintf(valorNaBaseDestino, "%s%c", valorNaBaseDestino, valorEmNumeroOuLetra(resto));

    valorOriginal = resultado;
  } while (resultado >= baseDestino);

  sprintf(valorNaBaseDestino, "%s%c", valorNaBaseDestino, valorEmNumeroOuLetra(resultado));

  return revertString(valorNaBaseDestino);
}

char* revertString(char* stringOrigem)
{
  char* stringDestino;
  int tamanho = strlen(stringOrigem);
  stringDestino = malloc(tamanho);

  int j = 0;
  for (int i = tamanho - 1; i >= 0; i--) {
    stringDestino[j++] = stringOrigem[i];
  }

  return stringDestino;
}

char valorEmNumeroOuLetra(int valorEmNumero)
{
  if (valorEmNumero <= 9) {
    return valorEmNumero + '0';
  }

  char letra = 'A';
  int qtd = valorEmNumero - 10;
  return letra + qtd;
}

int valorEmNumero(char numeroOuLetra)
{
  if (numeroOuLetra < '9') {
    return numeroOuLetra - '0';
  }

  return numeroOuLetra - 65 + 10;
}