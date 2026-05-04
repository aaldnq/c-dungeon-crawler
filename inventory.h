#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

typedef struct {
    Item *items;    // pointer to array instead of fixed array
    int count;
    int capacity;   // how much space we've allocated
} Inventory;

Inventory *inventory_create(int initial_capacity);
void inventory_destroy(Inventory *inv);
void print_inventory(Inventory *inv);
int add_item(Inventory *inv, Item item);
int remove_item(Inventory *inv, int index);

#endif