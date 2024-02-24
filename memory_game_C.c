#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Función para generar un número aleatorio
int aleatorio_n(int ronda) {
  int max = pow(10, ronda + 2) - 1;
  int min = pow(10, ronda + 1);
  return rand() % (max - min + 1) + min;
}

// Función principal del juego
void juego() {
  int vidas = 2;
  int ronda = 0;
  int userRESTART = 1;

  while (vidas > 0 && userRESTART) {
    // Generar el número aleatorio para la ronda actual
    int numero = aleatorio_n(ronda);

    // Mostrar el número al usuario durante 7 segundos
    printf("\n\nBienvenido al juego de memoria. Hay 7 rondas, en cada una se te muestra un número y tienes que memorizarlo en los 7 segundos disponibles. Tienes 2 vidas a lo largo de la partida.\n\n\nÉste es tu primer número:\t%d\n", numero);
    sleep(7);

    // Pedir al usuario que introduzca el número
    int usr;
    printf("¿Cuál era el número?\t\tNúmero + Enter: ");
    scanf("%d", &usr);

    // Validar la respuesta del usuario
    while (usr < pow(10, ronda + 1) || usr > pow(10, ronda + 2) - 1) {
      printf("**Error:** Debes introducir un número entre %d y %d.\n", pow(10, ronda + 1), pow(10, ronda + 2) - 1);
      printf("¿Cuál era el número?\t\tNúmero + Enter: ");
      scanf("%d", &usr);
    }

    // Comprobar si el usuario ha acertado
    if (usr == numero) {
      printf("\n\tAcertaste, vidas: %d\n", vidas);
    } else {
      vidas--;
      printf("\n\tFallaste, vidas: %d\n", vidas);
    }

    // Si el usuario tiene vidas restantes, pasar a la siguiente ronda
    if (vidas > 0) {
      ronda++;
      system("cls");
      printf("\t\t\tNUEVA RONDA\t%d\n", ronda + 1);

      // Generar el número aleatorio para la siguiente ronda
      numero = aleatorio_n(ronda);

      // Mostrar el número al usuario durante 7 segundos
      printf("Tu siguiente número es:\t\t%d\n", numero);
      sleep(7);

      // Pedir al usuario que introduzca el número
      printf("¿Cuál era el número?\t\tNúmero + Enter: ");
      scanf("%d", &usr);

      // Validar la respuesta del usuario
      while (usr < pow(10, ronda + 1) || usr > pow(10, ronda + 2) - 1) {
        printf("**Error:** Debes introducir un número entre %d y %d.\n", pow(10, ronda + 1), pow(10, ronda + 2) - 1);
        printf("¿Cuál era el número?\t\tNúmero + Enter: ");
        scanf("%d", &usr);
      }

      // Comprobar si el usuario ha acertado
      if (usr == numero) {
        printf("\n\tAcertaste, vidas: %d\n", vidas);
      } else {
        vidas--;
        printf("\n\tFallaste, vidas: %d\n", vidas);
      }
    }
  }

  // Mostrar el mensaje final
  system("cls");
  if (vidas > 0) {
    printf("\n\n\t\t\t¡Enhorabuena! Has ganado el juego.\n");
  } else {
    printf("\n\n\t\t\tHas perdido el juego. Vuelve a intentarlo.\n");
  }

  // Preguntar al usuario si quiere volver a jugar
  printf("\n\n\t\t\t¿Quieres jugar de nuevo?:\n\n\t\t\t1. Sí\n\t\t\t2. No\n");
  int userAgain;
  scanf("%d", &userAgain);
