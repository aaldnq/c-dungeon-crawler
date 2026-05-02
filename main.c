#include <stdio.h>
#include <string.h>
#include "inventory.h"

int main() {
    Inventory inv;
    inv.count = 0;

    Item sword;
    strcpy(sword.name, "Iron Sword");
    sword.weight = 3.5f;
    sword.value = 40;

    Item potion;
    strcpy(potion.name, "Health Potion");
    potion.weight = 0.5f;
    potion.value = 15;

    Item shield;
    strcpy(shield.name, "Wooden Shield");
    shield.weight = 5.0f;
    shield.value = 25;

    add_item(&inv, sword);
    add_item(&inv, potion);
    add_item(&inv, shield);

    print_inventory(&inv);

    printf("\nRemoving item at index 1...\n\n");
    remove_item(&inv, 1);

    print_inventory(&inv);

    return 0;
}