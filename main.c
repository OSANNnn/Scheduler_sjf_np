#include "scheduler.h"

#define PROCESSI_MAX 5

int main(){
    processo **coda = NULL;
    time_t start;
    time_t ultimoControllo = NOW;
    time_t tempoTrascorso;
    int processiAttivi = 0;
    int processiTerminati = 0;
    int processoInEsecuzione = 0;
    int attesaTotale = 0;
    float mediaAttesa;

    srand(time(NULL));

    while(processiTerminati < PROCESSI_MAX){

        if (rand() % 3 && processiAttivi < PROCESSI_MAX){
            if (processiAttivi = 0) start = NOW;

            coda = (processo**) realloc(coda, sizeof(processo*) * (processiAttivi + 1));
            
            *(coda + processiAttivi) = istanziaprocesso(processiAttivi, start);

            if (coda == NULL){
                printf("Errore nell'allocazione di memoria.\n\n");
                printf("Premi un tasto per uscire...");
                while(!getchar());
                return -1;
            }
            //istanzio processo
            processiAttivi++;

            if (processiAttivi > 2){
            //ordino i processi
            }
        }

        if (NOW != ultimoControllo){
            system("clear");
            tempoTrascorso = NOW - start;
            //stampo la tabella
            ultimoControllo = NOW;
            coda[processoInEsecuzione]->tempoRimanente--;
        }

        if (coda[processoInEsecuzione]->tempoRimanente == 0){
            coda[processoInEsecuzione]->status = DONE;
            processoInEsecuzione++;
            coda[processoInEsecuzione]->status = RUNNING;
            processiTerminati++;
        }

    }

    free(coda);
    return 0;
}
