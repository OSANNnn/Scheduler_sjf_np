#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOW time(NULL)
#define READY ' '
#define RUNNING '>'
#define DONE 'T'

typedef struct {
    int ID;
    int durata;
    int tempoArrivo;
    int tempoRimanente;
    char status;
} processo;

processo* istanziaprocesso(const int ID, time_t inizioCoda);

void ordinaprocessi(processo **coda, const int inizio, const int lunghezzaCoda);

void stampaprocessi(processo *process, const int processoInEsecuzione, const int lunghezzaCoda);