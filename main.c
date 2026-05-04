#include <stdio.h>
#include <string.h>
#include "inventory.h"

int main() {
    Inventory *inv = inventory_create(2); 

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

    Item dagger;
    strcpy(dagger.name, "Rusty Dagger");
    dagger.weight = 1.0f;
    dagger.value = 10;

    add_item(inv, sword);
    add_item(inv, potion);   // inventory full here, should grow
    add_item(inv, shield);
    add_item(inv, dagger);   // grows again

    print_inventory(inv);

    printf("\nRemoving index 0...\n\n");
    remove_item(inv, 0);

    print_inventory(inv);

    inventory_destroy(inv);  // always clean up
    return 0;
}