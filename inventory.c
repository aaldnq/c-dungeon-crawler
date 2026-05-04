#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

Inventory *inventory_create(int initial_capacity) {
    Inventory *inv = malloc(sizeof(Inventory));
    if (inv == NULL) {
        printf("Failed to allocate inventory!\n");
        return NULL;
    }
    inv->items = malloc(sizeof(Item) * initial_capacity);
    if (inv->items == NULL) {
        printf("Failed to allocate items!\n");
        free(inv);
        return NULL;
    }
    inv->count = 0;
    inv->capacity = initial_capacity;
    return inv;
}

void inventory_destroy(Inventory *inv) {
    free(inv->items);
    free(inv);
}

void print_inventory(Inventory *inv) {
    if (inv->count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("--- Inventory (%d/%d) ---\n", inv->count, inv->capacity);
    for (int i = 0; i < inv->count; i++) {
        printf("[%d] ", i);
        print_item(inv->items[i]);
    }
}

int add_item(Inventory *inv, Item item) {
    // if full, double the capacity
    if (inv->count >= inv->capacity) {
        int new_capacity = inv->capacity * 2;
        Item *new_items = realloc(inv->items, sizeof(Item) * new_capacity);
        if (new_items == NULL) {
            printf("Failed to grow inventory!\n");
            return 0;
        }
        inv->items = new_items;
        inv->capacity = new_capacity;
        printf("(inventory grew to %d slots)\n", new_capacity);
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
       //moving everything to the left, so basiaclly replacing the current index, which can be anything. And then removing the previous copy that remained.
    for (int i = index; i < inv->count - 1; i++) {
        inv->items[i] = inv->items[i + 1];
    }
    inv->count--;
    return 1;
}
