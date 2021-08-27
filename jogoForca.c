#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"
void limpa_variaveis()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int ganhou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }

    return 1;
}
char escolhatentativa;

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

void limparTela()
{
    system("cls");
}

int chuteserrados()
{
    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {

        if (!letraexiste(chutes[i]))
        {
            erros++;
        }
    }

    return erros;
}

void forca()
{

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 4 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}
int nivelamento(nivel)
{
    nivelAtual = 0;
    switch (nivel + 1)
    {
    case 1:
        nivelAtual = (rand() % 4);
        break;

    case 2:
        nivelAtual = (5 + (rand() % 9));
        break;

    case 3:
        nivelAtual = (10 + (rand() % 14));
        break;

    case 4:
        nivelAtual = (15 + (rand() % 19));
        break;

    case 5:
        nivelAtual = (20 + (rand() % 24));
        break;
    }

    return nivelAtual;
}

void escolhepalavra()
{
    FILE *palavras;

    palavras = fopen("palavras.txt", "r+");
    if (palavras == 0)
    {
        printf("Banco de dados das palavras nao foi encontrado!\n\n");
        exit(1);
    }

    fscanf(palavras, "%d", &quantidadeDePalavras);

    int randomico = nivelamento(nivelAtual);

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(palavras, "%s", palavrasecreta);
    }

    fclose(palavras);
}

int letraexiste(char letra)
{

    for (int j = 0; j < strlen(palavrasecreta); j++)
    {
        if (letra == palavrasecreta[j])
        {
            return 1;
        }
    }

    return 0;
}

void chuta()
{
    char chute;
    printf("\nQual letra? ");
    scanf(" %c", &chute);

    if (letraexiste(chute))
    {
        printf("Voce acertou: a palavra tem a letra %c\n\n", chute);
    }
    else
    {
        printf("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute;
    chutesdados++;
}

//

void comeco()
{
    printf("\n~~~~ JOGO DA FORCA ~~~~\n");
}
void mostrarNivel()
{
    printf("\nAgora voce esta no nivel %d \n\n", nivelAtual);
}
// ### 		Limite de erros para perder    ###

int enforcou()
{
    return chuteserrados() >= 7;
}

// ###          Função principal           ###

int main()
{
    for (nivelAtual = 0; nivelAtual < 5; nivelAtual++)
    {
        do
        {
            comeco();
            mostrarNivel();
            escolhepalavra();

            do
            {
                forca();
                chuta();
                limparTela();

            } while (!ganhou() && !enforcou());
            if (ganhou())
            {
                printf("\n### Parabens! voce acertou a palavra. ###\n");
                printf("\nA palavra certa eh %s\n\n \n", palavrasecreta);
            }
            else
            {
                printf("Perdeu ;-;, a palavra certa era \" %s \".", palavrasecreta);
            }

        escolha:
            printf("\nQuer tentar novamente?\nDigite \"S\"  para tentar novamente ou \"N\" para finalizar \n");
            scanf("%s", &escolhatentativa);
        } while ((escolhatentativa == 'n') || (escolhatentativa == 'N'));
    }
}
