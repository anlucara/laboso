#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

  pid_t pid;
	int status;
	char programa[50];

	printf("Nombre de programa:\n(nota: anteponer ./ antes de ingresar el nombre del Programa)");
	scanf("%s",programa); // lee una palabra 

   if (pid = fork() == 0){ 
      execlp(programa, programa, NULL);
   }
   wait(&status);
   return (0);
}
