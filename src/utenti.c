// utenti.c

#include "utenti.h"

static Utente database[] = {
    {"Alice", 30},
    {"Bob", 25}};

Option_Utente cerca_utente_per_id(int id)
{
    size_t numero_utenti = sizeof(database) / sizeof(database[0]);

    if (id < 0 || (size_t)id >= numero_utenti)
    {
        return NONE(Utente);
    }

    return SOME(Utente, database[id]);
}
