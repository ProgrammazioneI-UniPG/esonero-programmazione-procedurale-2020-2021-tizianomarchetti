#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char M[129], k[129]; //129 per comprendervi il newline e lo \0 finale
int choose = 0;

void GetInput() {
  do {
    printf("Inserisci la stringa da cifrare: ");
    fgets(M, 129, stdin);
  } while (strlen(M) - 1 == 0);
  if (!strchr(M, '\n')) {                        //Tronco la stringa M se
    while (fgetc(stdin) != '\n');                //superiore a 127 caratteri
    printf("La stringa inserita e': %s\n", M);
  } else
    printf("La stringa inserita e': %s", M);
}

void GetKey() {
  do {
    printf("Inserisci una stringa con la quale cifrare, di lunghezza uguale o superiore alla stringa iniziale: ");
    fgets(k, 129, stdin);
  } while (strlen(k) < strlen(M));
  if (!strchr(k, '\n')) {                        //Tronco la stringa k se
    while (fgetc(stdin) != '\n');                //superiore a 127 caratteri
    printf("La chiave inserita e': %s\n", k);
  } else
    printf("La chiave inserita e': %s", k);
}

void GetRandomKey() {
  printf("La chiave generata e': ");
  for (int i = 0; i < strlen(M) - 1; i++) {
    char rand_key_char = rand() % 128;
    if (rand_key_char > 31)
      printf("%c", k[i] = rand_key_char);
    else
      printf("%x", k[i] = rand_key_char); //Stampo in esadecimale i caratteri non visibili
  }
  printf("\n");
}

void GetChoose() {
  printf("Scegliere come procedere:\n1. Inserisci la chiave manualmente\n2. Genera una chiave casuale\n");
  while (choose != 1 && choose != 2) {
    scanf("%d", &choose);
    while (getchar() != '\n');  //Leggo la stringa intera fino al newline
    switch (choose) {
      case 1:
        GetKey();
        break;
      case 2:
        GetRandomKey();
        break;
      default:
        printf("Scegli opzione 1 o 2.\n");
        break;
    }
  }
}

void GetOutput() {
  char chyphertext[128], plaintext[128];
  printf("Il testo cifrato e': ");
  for (int i = 0; i < strlen(M) - 1; i++) {
    chyphertext[i] = M[i] ^ k[i];
    if (chyphertext[i] > 31)
      printf("%c", chyphertext[i]);
    else
      printf("%x", chyphertext[i]); //Stampo in esadecimale i caratteri non visibili
  }
  printf("\n");

  printf("Il testo originale e': ");
  for (int i = 0; i < strlen(M) - 1; i++) {
    plaintext[i] = chyphertext[i] ^ k[i];
    printf("%c", plaintext[i]);
  }
  printf("\n");
}

int main () {
  time_t t;
  srand((unsigned) time(&t));

  GetInput();
  GetChoose();
  GetOutput();

  return(0);
}
