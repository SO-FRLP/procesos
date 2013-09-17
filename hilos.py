#!/usr/bin/python

 ##
  #  Ejemplo de hilos desincronizados
  #
  #    Ing. Julian Perelli
  #    Catedra de Sistemas Operativos
  #    UTN - FRLP
  #    2013
  #
  # Posibles prerequisitos:
  #   apt-get install python
  #
  # Ejecucio:
  #   python hilos.py
  #
  ##

# libreria de manejo de hilos
import threading

# libreria para enviar a dormir threads
from time import sleep

# clase que representa el hilo
class MiThread(threading.Thread):
    
    # funcion que se ejecuta al momento de crear el hilo
    ## self  : objeto de la clase MiThread
    ## numero: argumento pasado al momento de crear el hilo (idx)
    def __init__(self, numero):
        
        # imprimimos que el hilo esta siendo creado
        print "En el main: creando hilo " + str(i) + "\n",

        # llamamos a super init para la creacion de esta clase
        threading.Thread.__init__(self)
        
        # inicializamos una variable num para este hilo
        self.num = numero
    
    
    # funcion que se llama al ejecutar el hilo
    def run(self):
        
        # mandamos al hilo al estado sleep, aca se desincroniza
        sleep(1)
        
        # cuando vuelve de sleep, imprimimos el numero de hilo
        print "Soy el hilo " + str(self.num) + "\n",


## programa principal ##

# bucle de repeticion de 1 a 100
for idx in range(0,100):
    
    # creacion del hilo idx
    t = MiThread(idx)
    
    # ejecucion del hilo idx
    t.start()
