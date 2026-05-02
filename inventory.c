#include <stdio.h>
#include "inventory.h"

void print_inventory(Inventory *inv) {
    if (inv->count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("--- Inventory (%d/%d) ---\n", inv->count, MAX_ITEMS);
    for (int i = 0; i < inv->count; i++) {
        printf("[%d] ", i);
        print_item(inv->items[i]);
    }
}

int add_item(Inventory *inv, Item item) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return 0;
    }
    inv->items[inv->count] = item;
    inv->count++;
    return 1;
}

int remove_item(Inventory *inv, int index) {
    if (index < 0 || index >= inv->count) {
        printf("Invalid index.\n");
        return 0;
    }
    for (int i = index; i < inv->count - 1; i++) {
        inv->items[i] = inv->items[i + 1];
    }
    inv->count--;
    return 1;
}