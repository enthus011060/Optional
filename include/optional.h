// optional.h

#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <stdbool.h>
#include <stddef.h>

// Definisce un tipo opzionale
#define DEFINE_OPTION(T) \
    typedef struct       \
    {                    \
        T value;         \
        bool is_some;    \
    } Option_##T

// Crea un'opzione contenente un valore
#define SOME(T, val) \
    ((Option_##T){.value = (val), .is_some = true})

// Crea un'opzione assente
#define NONE(T) \
    ((Option_##T){.is_some = false})

// Genera la funzione per estrarre il valore
#define DEFINE_OPTION_GETTER(T)                                       \
    static inline bool option_##T##_get(Option_##T opt, T *risultato) \
    {                                                                 \
        if (!opt.is_some || risultato == NULL)                        \
        {                                                             \
            return false;                                             \
        }                                                             \
        *risultato = opt.value;                                       \
        return true;                                                  \
    }

#endif
