#include <stdio.h>

#include "my_type.h"
#include "divide.h"
#include "utenti.h"
#include "optional_dispatch.h"
#include "conversioni.h"

int main(void)
{
    printf("===== TEST 1: DIVISIONE TRA INTERI =====\n");

    Option_int divisione_int = divide(10, 2);
    int risultato_int = 0;

    if (option_get(divisione_int, &risultato_int))
    {
        printf("10 / 2 = %d\n", risultato_int);
    }
    else
    {
        printf("Divisione non riuscita.\n");
    }

    printf("\n===== TEST 2: DIVISIONE TRA DOUBLE =====\n");

    Option_double divisione_double = divide(7.0, 2.0);
    double risultato_double = 0.0;

    if (option_get(divisione_double, &risultato_double))
    {
        printf("7.0 / 2.0 = %.2f\n", risultato_double);
    }
    else
    {
        printf("Divisione non riuscita.\n");
    }

    printf("\n===== TEST 3: DIVISIONE PER ZERO =====\n");

    Option_int divisione_zero = divide(10, 0);

    if (option_get(divisione_zero, &risultato_int))
    {
        printf("Risultato: %d\n", risultato_int);
    }
    else
    {
        printf("Opzione assente: divisione non riuscita.\n");
    }

    printf("\n===== TEST 4: OPZIONE ASSENTE =====\n");

    Option_int opzione_assente = NONE(int);
    risultato_int = 123;

    if (option_get(opzione_assente, &risultato_int))
    {
        printf("Valore: %d\n", risultato_int);
    }
    else
    {
        printf("Getter restituisce false.\n");
        printf("Valore precedente preservato: %d\n", risultato_int);
    }

    printf("\n===== TEST 5: PUNTATORE NULL =====\n");

    Option_int opzione_presente = SOME(int, 42);

    if (option_get(opzione_presente, NULL))
    {
        printf("Estrazione riuscita.\n");
    }
    else
    {
        printf("Getter restituisce false con NULL.\n");
    }

    printf("\n===== TEST 6: RICERCA UTENTE VALIDO =====\n");

    Option_Utente opzione_utente = cerca_utente_per_id(0);
    Utente utente;

    if (option_get(opzione_utente, &utente))
    {
        printf("Nome: %s\n", utente.nome);
        printf("Eta: %d\n", utente.eta);
    }
    else
    {
        printf("Utente non trovato.\n");
    }

    printf("\n===== TEST 7: SECONDO UTENTE =====\n");

    opzione_utente = cerca_utente_per_id(1);

    if (option_get(opzione_utente, &utente))
    {
        printf("Nome: %s\n", utente.nome);
        printf("Eta: %d\n", utente.eta);
    }
    else
    {
        printf("Utente non trovato.\n");
    }

    printf("\n===== TEST 8: INDICE NON VALIDO =====\n");

    opzione_utente = cerca_utente_per_id(2);

    if (option_get(opzione_utente, &utente))
    {
        printf("Nome: %s\n", utente.nome);
    }
    else
    {
        printf("Utente non trovato: indice non valido.\n");
    }

    printf("\n===== TEST 9: INDICE NEGATIVO =====\n");

    opzione_utente = cerca_utente_per_id(-1);

    if (option_get(opzione_utente, &utente))
    {
        printf("Nome: %s\n", utente.nome);
    }
    else
    {
        printf("Utente non trovato: indice negativo.\n");
    }

    printf("\n===== TEST 10: CONVERSIONE STRINGA/NUMERO =====\n");

    Option_int opzione = to_int("-10");
    int risultato;

    if (option_get(opzione, &risultato))
    {
        printf("risultato: %d\n", risultato);
    }
    else
    {
        printf("Conversione non riuscita: opzione assente.\n");
    }

    printf("\n===== TEST COMPLETATI =====\n");

    return 0;
}