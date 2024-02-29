# SCHEDULER SJF non PRE-EMPTIVE

## Descrizione
Si tratta di un algoritmo che simula lo scheduler di un sistema operativo che predilige processi di durata più corta e li pone più in alto nella coda.

## Utilizzo
Si possono impostare il numero di processi massimi nella macro `PROCESSI_MAX` nel `main.c` file. 
Per impostare una probabilità più bassa o alta che un processo venga istanziato si può cambiare il valore di `SPAWN_RATE` nel file `main.c`, più alto è il valore più bassa è la probabilità che venga generato un processo (max 32767).

E' inoltre possibile modificare il tempo minimo e massimo della durata dei processi dalle macro nel file `scheduler.h` alle voci `MIN_TIME` e `MAX_TIME`