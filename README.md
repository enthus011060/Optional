# Optional — Valori opzionali in C

Una piccola libreria in C11 per rappresentare valori opzionali, cioè valori che possono essere presenti oppure assenti.

La libreria utilizza strutture e macro per creare tipi opzionali, rappresentare l'assenza di un valore e recuperare in sicurezza il valore contenuto.

## Caratteristiche

- Tipi opzionali generati tramite macro.
- Supporto agli interi (`int`), ai numeri decimali (`double`) e al tipo personalizzato `Utente`.
- Macro `SOME` per creare un'opzione contenente un valore e `NONE` per rappresentare un'opzione assente.
- Getter che restituiscono `true` se il valore è disponibile e `false` altrimenti.
- Se il getter fallisce, il valore della variabile di output rimane invariato.
- Esempi di divisione, ricerca di utenti e conversione da stringa a intero.

## Requisiti

- Un compilatore C compatibile con C11.
- `clang`, per utilizzare i comandi di compilazione riportati in questo documento.

## Struttura del progetto

```text
optional/
├── include/
│   ├── optional.h
│   ├── optional_dispatch.h
│   ├── my_type.h
│   ├── divide.h
│   ├── conversioni.h
│   └── utenti.h
├── src/
│   ├── divide.c
│   ├── conversioni.c
│   └── utenti.c
├── examples/
│   └── main.c
├── README.md
└── .gitignore
```

## Esempio d'uso

### Creare un'opzione contenente un valore

Per creare un'opzione contenente il numero intero `42`:

```c
Option_int risultato = SOME(int, 42);
```

### Creare un'opzione assente

Per rappresentare l'assenza di un valore:

```c
Option_int risultato = NONE(int);
```

### Recuperare il valore

Il getter permette di verificare se l'opzione contiene un valore e, in caso positivo, di copiarlo nella variabile indicata:

```c
#include <stdio.h>
#include "my_type.h"

int main(void)
{
    Option_int risultato = SOME(int, 42);
    int valore;

    if (option_int_get(risultato, &valore)) {
        printf("Valore: %d\n", valore);
    } else {
        printf("Valore assente\n");
    }

    return 0;
}
```

Il getter restituisce `true` se l'opzione contiene un valore e il puntatore di output è valido. In caso contrario restituisce `false` senza modificare la variabile di output.

Per utilizzare il dispatch generico è disponibile anche la macro `option_get`, definita in `optional_dispatch.h`.

## Compilazione dell'esempio

Dalla directory principale del progetto, eseguire:

```bash
clang -std=c11 -Wall -Wextra -Wpedantic -Iinclude \
  examples/main.c src/divide.c src/utenti.c src/conversioni.c \
  -o programma
```

Per avviare il programma:

```bash
./programma
```

## Licenza

La licenza del progetto deve essere scelta e specificata prima della distribuzione pubblica.