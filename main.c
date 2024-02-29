#include "scheduler.h"

#define PROCESSI_MAX 5
#define SPAWN_RATE 13 //max 32767

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
        //generatore di processi
        if (!(rand() % SPAWN_RATE) && processiAttivi < PROCESSI_MAX && ultimoControllo != NOW)
        {
            if (processiAttivi == 0) start = NOW;
            //aumento la dimensione della coda
            coda = (processo**) realloc(coda, sizeof(processo*) * (processiAttivi + 1));
            //istanzio processo
            *(coda + processiAttivi) = istanziaprocesso(processiAttivi, start);

            if (coda == NULL || *(coda + processiAttivi) == NULL){
                printf("Errore nell'allocazione di memoria.\n\n");
                printf("Premi un tasto per uscire...");
                while(!getchar());
                return -1;
            }
            processiAttivi++;

            if (processiAttivi > 2){
            //ordino i processi
                ordinaprocessi(coda, processoInEsecuzione, processiAttivi);
            }
                        
        }
        //visualizzazione
        if (NOW != ultimoControllo){    
            printf("\e[1;1H\e[2J");
            tempoTrascorso = NOW - start;
            printf("Processi attivi: %d\n\n", processiAttivi);

            if (processiAttivi == 0){
                printf("Nessun processo attivo...");
            }
            else{
                //stampo la tabella
                stampaprocessi(coda, processiAttivi);
                printf("Tempo trascorso: %ld\n", tempoTrascorso);
                
                if(coda[processoInEsecuzione]->tempoRimanente != 0)
                    coda[processoInEsecuzione]->tempoRimanente -= 1;

                if (coda[processoInEsecuzione]->tempoRimanente == 0 && coda[processoInEsecuzione]->status != DONE){
                    coda[processoInEsecuzione]->status = DONE;
                    processiTerminati++;
                }
            }
            ultimoControllo = NOW;
        }

        if ((processiAttivi - processiTerminati) > 0 && coda[processoInEsecuzione]->status == DONE) {
            processoInEsecuzione++;
            coda[processoInEsecuzione]->status = RUNNING;          
        }
    }
    //calcolo della durata dell'attesa a partire dall'arrivo del secondo processo
    for (int i = 1; i < PROCESSI_MAX - 1; i++){
        if (i == 1){
            attesaTotale = coda[0]->durata - coda[1]->tempoArrivo;
        }
        else{
            attesaTotale += coda[i]->durata;
        }
    }
    mediaAttesa = (float) attesaTotale / PROCESSI_MAX;
    //stampo la lista 
    printf("\e[1;1H\e[2J");
    stampaprocessi(coda, processiAttivi);    
    printf("Attesa media: %.2f\n", mediaAttesa);

    printf("\nPremi un tasto per uscire... ");
    while(!getchar());

    free(coda);
    return 0;
}
