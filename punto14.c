

#include <stdio.h>
#include <pthread.h>

int lineas_totales = 0;

void* contar_lineas(void * arg)
{
    int n_lineas = 0;
    char c;
    // 300-336-0842

    FILE * f = fopen((char *) arg, "r");

    while(1)
    {
        c = fgetc(f);

        if (c == '\n')
        {
            n_lineas++;
            lineas_totales++;
        }
        else if(c == EOF)
            break;
    }

    return (void*) n_lineas;
}

int main(int argc, char **argv)
{
    int i, lineas[argc - 1];
    pthread_t hilos_id[argc - 1];

    for(i = 1; i < argc; i++)
        pthread_create(&hilos_id[i - 1], NULL, contar_lineas, argv[i]);

    for(i = 1; i < argc; i++)
        pthread_join(hilos_id[i-1], (void *) &lineas[i - 1]);

    for(i = 1; i < argc; i++)
        printf("%s: %d lineas\n", argv[i], lineas[i - 1]);

    printf("Total %d lineas\n", lineas_totales);

    return 0;
}

