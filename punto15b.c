

#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define debug()		printf("%d\n", __LINE__)

int total = 0;

void * suma(void * arg)
{
    int i;
    int * num = (int *) arg;

    for(i = 0; i < *num; i++)
        total += num[i + 1];

    return NULL;
}

int main(int argc, char **argv)
{
    int i = 0, c;
    int numeros[100];
    int numeros_1[50];
    int numeros_2[50];
    int numero = 0;
    pthread_t hilo1, hilo2;
    FILE * f = fopen(argv[1], "r");

    while(c = fgetc(f))
    {
        if (c == 0xa || c == EOF)
            break;
        else if (c == ',')
        {
            numeros[i++] = numero;
            numero = 0;
        }
        else
        {
            numero *= 10;
            numero += (c - 48);
        }
    }

    numeros[i++] = numero;

    numeros_1[0] = i / 2;
    memcpy(numeros_1 + 1, numeros, numeros_1[0] * sizeof(int));

    numeros_2[0] = i - numeros_1[0];
    memcpy(numeros_2 + 1, numeros + numeros_1[0], numeros_2[0] * sizeof(int));

    pthread_create(&hilo1, NULL, &suma, numeros_1);
    pthread_create(&hilo2, NULL, &suma, numeros_2);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("La suma de los números = %d\n", total);

    fclose(f);
}

