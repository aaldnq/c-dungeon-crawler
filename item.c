#include <stdio.h>
#include "item.h"

void print_item(Item item) {
    printf("%-20s | weight: %.1f | value: %d gold\n",
           item.name, item.weight, item.value);
}