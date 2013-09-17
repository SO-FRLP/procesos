 /*
  *  Ejemplo de hilos desincronizados
  *
  *    Ing. Julian Perelli
  *    Catedra de Sistemas Operativos
  *    UTN - FRLP
  *    2012
  *
  * Posibles prerequisitos:
  *   apt-get install gcc build-essential glibc libc6
  *
  * Compilacion:
  *   gcc hilos.c -ohilos -lpthread
  *
  * Ejecucion:
  *   ./hilos
  *
  */

// libreria de funciones de hilos
#include <pthread.h>

// libreria de manejo de entrada/salida (stdin/out/err)
#include <stdio.h>

// directiva al compilador:
//   se reemplaza NUM_THREADS por el numero, antes de la fase de compilacion
#define NUM_THREADS     100


// funcion que ejecutara el hilo
void *PrintHello(void *threadid)
{
   // declaracion de variable long (mayor rango que int)
   long tid;

   // typecast (era void, ahora es long)
   tid = (long)threadid;

   // imprime en pantalla el thread id
   printf("Soy el hilo #%ld!\n", tid);

   // termina la ejecucion avisando al padre
   pthread_exit(NULL);
}


// funcion principal que se ejecuta
// argc es la cantidad de argumentos
// argv es un array de strings, son los argumentos
int main (int argc, char *argv[])
{
   // vector de threads (cada uno de tipo pthread)
   // longitud del vector = NUM_THREADS
   pthread_t threads[NUM_THREADS];

   // var donde se guarda el thread id
   long t;

   // bucle de repeticion for:
   //   desde t=0
   //   mientras t<NUM_THREADS
   //   realizando t++ (incremento de t en 1) en cada iteracion 
   for ( t = 0; t < NUM_THREADS; t++ ) {

      // Imprimir en pantalla un mensaje previo a la creacion de un hilo
      printf("En el main: creando hilo %ld\n", t);

      // Creacion del hilo:
      //   &threads[t]: puntero a thread id
      //   NULL: atributos de creacion (NULL=default)
      //   PrintHello: funcion que ejecutara el thread
      //   (void *)t: variable t (indice de este bucle), se pasa al thread, y la recibe como unico parametro
      pthread_create(&threads[t], NULL, PrintHello, (void *)t);

   }

   // lo ultimo que main debe hacer
   pthread_exit(NULL);
}
