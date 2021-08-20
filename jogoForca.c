#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int erros;

void forca()
{ //função forca, serve para imprimir as chances do usuario a cada erro; argumento="estado"

  int estado = erros;

  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (estado >= 1 ? '(' : ' '), (estado >= 1 ? '_' : ' '), (estado >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (estado >= 3 ? '\\' : ' '), (estado >= 2 ? '|' : ' '), (estado >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (estado >= 2 ? '|' : ' ')); // Usado função if else por ternário { Condicição ? se_vdd_realiza_isso : se_mentira_realiza_isso }
  printf(" |      %c %c   \n", (estado >= 4 ? '/' : ' '), (estado >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");
}

int main()
{ //nivel 1
  printf("NIVEL 1:\n");
  char nivel1[] = "bola"; //palavra secreta
  printf("A palavra tem %lu caracteres", strlen(nivel1));

  char p_tela[100];       //palavra para tela
  strcpy(p_tela, nivel1); //copia o nivel1 em p_tela
  //substitui letras por '_'
  for (int i = 0; i < strlen(p_tela); i++)
  {
    p_tela[i] = '_';
  }

  int erros = 0;
  while (1)
  {
    //imprimir a forca
    forca(erros);
    //imprimir os underline '_' para cada letra da palavra, ou seja, imprimir p_tela
    printf("\nAdivinhe: ");
    for (int i = 0; i < strlen(p_tela); i++)
    {
      printf("%c ", p_tela[i]);
    }
    //recebe a letra
    printf("\nLetra: ");
    char letra;
    scanf(" %c", &letra);
    //se letra correta atualiza palavra na tela
    //verifica se a letra esta correta
    int sera_que_errou = 1; //1=sim 0=nao
    for (int i = 0; i < strlen(p_tela); i++)
    {
      if (letra == nivel1[i])
      { //certo
        p_tela[i] = letra;
        sera_que_errou = 0;
      }
    }
    //senao, incrementa erros
    if (sera_que_errou == 1)
    {
      erros++;
    }
    //verifica se o jogo acabou
    //verifica se ganhou
    //verifica se a palavra é igual a p_tela
    if (strcmp(p_tela, nivel1) == 0)
    {
      //ENTAO ganhou
      printf("\nAcertou: ");
      printf("%s ", nivel1);
      printf("\nVocê Venceu o Nivel 1! Parabéns!!!");

      //apartir deste ponto, é apenas uma repetição, mudando a palavra a cada nivel

      printf("\nNIVEL 2:\n");
      char nivel2[] = "abacate";
      printf("A palavra tem %lu caracteres", strlen(nivel2));

      char p_tela[100];
      strcpy(p_tela, nivel2);

      for (int i = 0; i < strlen(p_tela); i++)
      {
        p_tela[i] = '_';
      }

      int erros = 0;
      while (1)
      {

        forca(erros);

        printf("\nAdivinhe: ");
        for (int i = 0; i < strlen(p_tela); i++)
        {
          printf("%c ", p_tela[i]);
        }
        printf("\nLetra: ");
        char letra;
        scanf(" %c", &letra);
        int sera_que_errou = 1;
        for (int i = 0; i < strlen(p_tela); i++)
        {
          if (letra == nivel2[i])
          {
            p_tela[i] = letra;
            sera_que_errou = 0;
          }
        }
        if (sera_que_errou == 1)
        {
          erros++;
        }

        if (strcmp(p_tela, nivel2) == 0)
        {
          printf("\nAcertou: ");
          printf("%s ", nivel2);
          printf("\nVocê Venceu o Nivel 2! Parabéns!!!");

          printf("\nNIVEL 3:\n");
          char nivel3[] = "paralelo";
          printf("A palavra tem %lu caracteres", strlen(nivel3));

          char p_tela[100];
          strcpy(p_tela, nivel3);

          for (int i = 0; i < strlen(p_tela); i++)
          {
            p_tela[i] = '_';
          }

          int erros = 0;
          while (1)
          {
            forca(erros);

            printf("\nAdivinhe: ");
            for (int i = 0; i < strlen(p_tela); i++)
            {
              printf("%c ", p_tela[i]);
            }
            printf("\nLetra: ");
            char letra;
            scanf(" %c", &letra);
            int sera_que_errou = 1;
            for (int i = 0; i < strlen(p_tela); i++)
            {
              if (letra == nivel3[i])
              {
                p_tela[i] = letra;
                sera_que_errou = 0;
              }
            }
            if (sera_que_errou == 1)
            {
              erros++;
            }

            if (strcmp(p_tela, nivel3) == 0)
            {
              printf("\nAcertou: ");
              printf("%s ", nivel3);
              printf("\nVocê Venceu o Nivel 3! Parabéns!!!");

              printf("\nNIVEL 4:\n");
              char nivel4[] = "paralelepipedo";
              printf("A palavra tem %lu caracteres", strlen(nivel4));

              char p_tela[100];
              strcpy(p_tela, nivel4);

              for (int i = 0; i < strlen(p_tela); i++)
              {
                p_tela[i] = '_';
              }

              int erros = 0;
              while (1)
              {

                forca(erros);

                printf("\nAdivinhe: ");
                for (int i = 0; i < strlen(p_tela); i++)
                {
                  printf("%c ", p_tela[i]);
                }

                printf("\nLetra: ");
                char letra;
                scanf(" %c", &letra);
                int sera_que_errou = 1;
                for (int i = 0; i < strlen(p_tela); i++)
                {
                  if (letra == nivel4[i])
                  {
                    p_tela[i] = letra;
                    sera_que_errou = 0;
                  }
                }

                if (sera_que_errou == 1)
                {
                  erros++;
                }

                if (strcmp(p_tela, nivel4) == 0)
                {
                  printf("\nAcertou: ");
                  printf("%s ", nivel4);
                  printf("\nVocê Venceu o Nivel 4! Parabéns!!!");

                  printf("\nNIVEL 5:\n");
                  char nivel5[] = "calculodiferencialintegral";
                  printf("A palavra tem %lu caracteres", strlen(nivel5));

                  char p_tela[100];
                  strcpy(p_tela, nivel5);

                  for (int i = 0; i < strlen(p_tela); i++)
                  {
                    p_tela[i] = '_';
                  }

                  int erros = 0;
                  while (1)
                  {

                    forca(erros);

                    printf("\nAdivinhe: ");
                    for (int i = 0; i < strlen(p_tela); i++)
                    {
                      printf("%c ", p_tela[i]);
                    }

                    printf("\nLetra: ");
                    char letra;
                    scanf(" %c", &letra);
                    int sera_que_errou = 1;
                    for (int i = 0; i < strlen(p_tela); i++)
                    {
                      if (letra == nivel5[i])
                      {
                        p_tela[i] = letra;
                        sera_que_errou = 0;
                      }
                    }

                    if (sera_que_errou == 1)
                    {
                      erros++;
                    }

                    if (strcmp(p_tela, nivel5) == 0)
                    {
                      printf("\nAcertou: ");
                      printf("%s ", nivel5);
                      printf("\nVocê Venceu o Nivel 5! Parabéns!!!");
                      break;
                    }

                    //verifica se perdeu
                    else if (erros == 6)
                    {
                      //perdeu
                      forca(erros);

                      break;
                    }
                  }
                }

                else if (erros == 6)
                {
                  forca(erros);

                  break;
                }
              }
            }

            if (erros == 6)
            {
              forca(erros);
              break;
            }
          }
        }

        if (erros == 6)
        {
          forca(erros);
          break;
        }
      }
    }

    if (erros == 6)
    {
      forca(erros);
      break;
    }
  }
  return 0;
}

// FUNSÕES USADAS: strcpy() A função strcpy() copia a string-origem para a string- destino

//A função strlen() retorna o comprimento da string fornecida.

//A função strcmp() compara a string 1 com a string 2. Se as duas forem idênticas a função retorna zero. Se elas forem diferentes a função retorna não-zero.
