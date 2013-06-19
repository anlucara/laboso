#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>


int main() {

 
   pid_t pid;
   int status = 0, i = 0;
   int factor, numero;

   srand(time(NULL));

   for (i = 1; i <= 3; i++) {
       pid = fork();

       if (pid == 0) { /* Proceso Hijo */

           printf("HIJO #%d\n", i);
           numero = rand () % 10+1;
           factor = factorial(numero);
  	   printf("El factorial del numero %d es: %d\n", numero, factor);            
           exit(0); //El Hijo termina después de Imprimir

       } else if (pid < 0) {
           printf("Error en el fork\n");

       } else { /* Proceso Padre */
           printf("Soy el Padre \n");
       }

   }
   wait(&status); //wait espera a que terminen los hijos para terminar el padre
   return (0);
}

int factorial(int num) //función factorial recursiva
{

 if(num<2)
   return 1;

 else
   return num * factorial(num-1);
}
