// my_type.h

#ifndef MY_TYPE_H
#define MY_TYPE_H

#include "optional.h"

// Tipo opzionale per gli interi e i double
DEFINE_OPTION(int);
DEFINE_OPTION(double);

// Tipo personalizzato
typedef struct
{
    const char *nome;
    int eta;
} Utente;

// Optional per il tipo personalizzato
DEFINE_OPTION(Utente);

// Getter per ogni tipo
DEFINE_OPTION_GETTER(int)
DEFINE_OPTION_GETTER(double)
DEFINE_OPTION_GETTER(Utente)

#endif
