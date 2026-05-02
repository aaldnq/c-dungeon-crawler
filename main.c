#include <stdio.h>
#include <string.h>

#define MAX_NAME 64
#define MAX_ITEMS 16

typedef struct {
    char name[MAX_NAME];
    float weight;
    int value;
} Item;

void print_item(Item item) {
    printf("%-20s | weight: %.1f | value: %d gold\n", 
        item.name, item.weight, item.value);
}





int main(){
    Item sword;
    Item potion;
    strcpy(sword.name, "Iron Sword");
    sword.weight = 3.5f;
    sword.value = 40;

    strcpy(potion.name, "Health Potion");
    potion.weight = 0.5f;
    potion.value = 15;

    print_item(sword);
    print_item(potion);
    return 0;
}