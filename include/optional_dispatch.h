// optional_dispatch

#ifndef OPTIONAL_DISPATCH_H
#define OPTIONAL_DISPATCH_H

// Seleziona la funzione di divisione
#define divide(a, b)     \
    _Generic((a),        \
        int: divide_int, \
        double: divide_double)(a, b)

// Seleziona il getter dell'opzione
#define option_get(opzione, risultato)    \
    _Generic((opzione),                   \
        Option_int: option_int_get,       \
        Option_double: option_double_get, \
        Option_Utente: option_Utente_get)(opzione, risultato)

#endif