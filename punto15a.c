

#include <stdio.h>

int main(int argc, char **argv)
{
    int c;
    int total = 0;
    int numero = 0;
    FILE * f = fopen(argv[1], "r");

    while(c = fgetc(f))
    {
        if (c == 0xa || c == EOF)
            break;
        else if (c == ',')
        {
            total += numero;
            numero = 0;
        }
        else
        {
            numero *= 10;
            numero += (c - 48);
        }
    }

    total += numero;

    printf("La suma de los números = %d\n", total);

    fclose(f);
}

