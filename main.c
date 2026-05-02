#include <stdio.h>
#include <string.h>

#define MAX_NAME 64
#define MAX_ITEMS 16

typedef struct {
    char name[MAX_NAME];
    float weight;
    int value;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void print_item(Item item) {
    printf("%-20s | weight: %.1f | value: %d gold\n",
           item.name, item.weight, item.value);
}

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

int remove_item(Inventory *inv, int index){
    if(index < 0 || index >= inv->count){ // if index less than 0 or more than the actual count which wouldnt make sense, so its an error;
        printf("Invalid index \n");
        return 0;
    }
    //moving everything to the left, so basiaclly replacing the current index, which can be anything. And then removing the previous copy that remained.
     for (int i = index; i < inv->count - 1; i++) {
        inv->items[i] = inv->items[i + 1];
         
    }
    inv->count--;
    return 1;
}





int main(){
    Inventory inv;
    inv.count = 0;


    Item sword;
    Item potion;
    strcpy(sword.name, "Iron Sword");
    sword.weight = 3.5f;
    sword.value = 40;

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