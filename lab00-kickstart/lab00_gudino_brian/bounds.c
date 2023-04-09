#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;
    
    for (unsigned int i=0; i<length; i++){
        if(value >= arr[i]){
            res.is_lowerbound = false;
        }
        else {
            res.is_upperbound = false;
        }

        if(value == arr[i]){ 
            res.exists = true;
            res.where = i;

            }

    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("Ingrese valor: ");
        scanf("%d",&a[i]);
    }

    printf("Ingrese valor a verificar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    printf("Es mayor a todos: %s\n", (result.is_upperbound==true? "Es cierto":"No es cierto")); 
    printf("Es menor a todos: %s\n", (result.is_lowerbound==true? "Es cierto":"No es cierto")); 
    printf("Existe: %s\n", (result.exists==true? "Si":"No"));    

    if(result.exists == true) {
        printf("En la ubicacion: %u\n", result.where);  
    }

    return EXIT_SUCCESS;
}

