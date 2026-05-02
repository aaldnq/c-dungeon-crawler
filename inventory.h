#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

#define MAX_ITEMS 16

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void print_inventory(Inventory *inv);
int add_item(Inventory *inv, Item item);
int remove_item(Inventory *inv, int index);

#endif