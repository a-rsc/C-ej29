#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "rlutil.h"

#define FALLO LIGHTRED
#define ACIERTO GREEN
#define NORMAL GREY

int main()
{
    int secret, intents, i=1, num;
    bool encertat = false;

    // Instrucción que inicializa el generador de números aleatorios
    srand(time(NULL));
    // Obtención de un número aleatorio entero entre 1000 y 9999
    secret = rand()%9000+1000;

    printf("- Algorisme: Mastermind (exercici 29).\n");

    do{
        printf("Introdueix el nombre d'intents per encertar el nombre de 4 xifres de la m%cquina: ", (char)133);
        scanf("%d", &intents);
        // fflush(stdin); Sólo es necesario si leemos caracteres INTERESANTE
    }while(intents<=0);

    while(i<=intents && !(encertat)){

        do{
            printf("Intent %d. %cQui%cn creus que %cs el nombre de la m%cquina%c ", i, (char)168, (char)130, (char)130, (char)133, (char)63);
            scanf("%d", &num);
            // fflush(stdin); Sólo es necesario si leemos caracteres INTERESANTE
        }while(num>9999 && num<1000);

        if(num == secret){
            setColor(ACIERTO);
            encertat = true;
        } else {
            setColor(FALLO);
            if(num < secret){
                printf("El nombre secret %cs SUPERIOR!\n", (char)130);
            }else{
                printf("El nombre secret %cs INFERIOR!\n", (char)130);
            }
            setColor(NORMAL);
        }
        i++;
    }

    if(encertat){
        printf("Has ENCERTAT el nombre secret!\n", num, (char)130);
    }else{
        printf("Has acabat els intents, el nombre de la m%cquina era el %d!\n", (char)133, secret);
    }
    setColor(NORMAL);

    return 0;
}
