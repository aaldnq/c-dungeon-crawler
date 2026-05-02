#ifndef ITEM_H
#define ITEM_H

#define MAX_NAME 64

typedef struct {
    char name[MAX_NAME];
    float weight;
    int value;
} Item;

void print_item(Item item);

#endif