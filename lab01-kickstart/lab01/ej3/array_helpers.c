#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *archivo;
    archivo = fopen(filepath,"r");

    assert(archivo != NULL);

    unsigned int length = 0;
    unsigned int i = 0;
    int valor;
    int length_file;
    fscanf(archivo, "%d", &length_file);
    
    while(1){

        assert(length<=max_size);

        fscanf(archivo, "%d", &valor);
        if(feof(archivo)) break;

        array[i] = valor;

        ++length;
        ++i;
    }

    if(length != length_file){
        printf("Length error.\n");
        exit(0);
    }

    fclose(archivo);
    
    return length;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for(unsigned int i = 0;i<length;i++){
        printf("%d",a[i]);

        if(i!=length-1) printf(", ");
    }
    printf("]");
}