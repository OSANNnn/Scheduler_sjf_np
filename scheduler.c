#include "scheduler.h"

processo *istanziaprocesso(const int ID, time_t inizioCoda)
{
    processo *nuovoProcesso = (processo*) malloc(sizeof(processo));

    nuovoProcesso->ID = ID;
    nuovoProcesso->durata = rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
    if (ID == 0)
        { nuovoProcesso->tempoArrivo = 0;
          nuovoProcesso->status = RUNNING;}
    else
        { 
            nuovoProcesso->tempoArrivo = (int) NOW - inizioCoda;
            nuovoProcesso->status = READY; 
        }
    nuovoProcesso->tempoRimanente = nuovoProcesso->durata;

    return nuovoProcesso;
}

void ordinaprocessi(processo **coda, const int inizio, const int lunghezzaCoda)
{
    processo *temp;

    int i;
    int j = 0;
    int hasSwapped;

    do{
        hasSwapped = 0;
        for (i = inizio + 1; i < (lunghezzaCoda - 1) - j; i++){
            if(coda[i]->durata > coda[i + 1]->durata){

                temp = coda[i];
                coda[i] = coda[i + 1];
                coda[i + 1] = temp;
                hasSwapped = 1;
            }
        }
        j++;
    }while (hasSwapped && j < lunghezzaCoda - 1);
}

void stampaprocessi(processo **process, const int lunghezzaCoda)
{
    printf(" ID\tArrivo\tDurata\tTempo Rimanente\n");
    for (int i = 0; i < lunghezzaCoda; i++){
        printf(" %c%d\t%d\t%d\t%d\n",process[i]->status, process[i]->ID, process[i]->tempoArrivo, process[i]->durata, process[i]->tempoRimanente);
    }
}
