#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "List.h"

struct _EvenAndOdd
{
    ListPointer Pares;
    ListPointer Impares;
};

typedef struct _EvenAndOdd EvenAndOdd, *PointerEvenAndOdd;

PointerEvenAndOdd FindEvenAndOdd(ListPointer list)
{
    PointerEvenAndOdd even_odd = (PointerEvenAndOdd)malloc(sizeof(EvenAndOdd));
    even_odd->Pares = ListNew();
    even_odd->Impares = ListNew();

    for (size_t i = 0 ; i < list->size ; ++i)
    {
        if (list->data[i] % 2 == 0)
        {
            ListAdd(even_odd->Pares, list->data[i]);
        }
        else
        {
            ListAdd(even_odd->Impares, list->data[i]);
        }
    }

    return even_odd;
}

int32_t main(void)
{
    ListPointer list = ListNew();
    size_t size;
    int32_t value;

    puts("---> Enter a number");
    scanf("%ld", &size);

    puts("\n---> Enter a numbers sequence");

    for (size_t i = 0 ; i < size ; ++i)
    {
        scanf("%d", &value);
        ListAdd(list, value);
    }

    PointerEvenAndOdd even_odd = FindEvenAndOdd(list);

    puts("\nPares");

    for (size_t i = 0; i < even_odd->Pares->size; ++i)
    {
        printf("> %d\n", even_odd->Pares->data[i]);
    }

    puts("\nImpares");

    for (size_t i = 0; i < even_odd->Impares->size; ++i)
    {
        printf("> %d\n", even_odd->Impares->data[i]);
    }

    ListDestroy(list);
    ListDestroy(even_odd->Pares);
    ListDestroy(even_odd->Impares);
    free(even_odd);

    return 0;
}