#include <stdio.h>
#include <string.h>

#define MAX_NAME 64
#define MAX_ITEMS 16

typedef struct {
    char name[MAX_NAME]:
    float weight;
    int value;
} Item;

void print_item(Item item) {
    printf("%-20s | weight: %.1f | value: %d gold\n", 
        item.name, item.wieght, item.value);
}





int main(){
    Item sword;
    strcpy(sword.name, "Iron Sword");
    

    return 0;
}