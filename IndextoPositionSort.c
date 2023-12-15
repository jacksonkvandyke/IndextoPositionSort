#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int main() {
    //Create the sort array
    int array[17] = {1, 10, 2, 3, 5, 7, 6, 154, 21312, 32, 123, 535, 34, 443, 65, 45, 87};
    int sortedArray[17] = {0};

    //Check if array is empty
    if (sizeof(array) / sizeof(array[0]) == 0){
        printf("%s", "Empty array");
        return 0;

    }

    //Get largest and smallest value of array
    int min = array[0];
    int max = array[0];
    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
        if (array[i] < min){
            min = array[i];

        }
        if (array[i] > max){
            max = array[i];
            
        }

    }

    //Create and assign values to position array
    int* positionArray = malloc(sizeof(array[0]) * (max - min + 2));
    memset(positionArray, 0, sizeof(array[0]) * (max - min + 2));
    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
        positionArray[array[i]] = array[i];

    }

    //Assign values to sorted position
    int sortedIndex = 0;
    for (int i = 0; i < (max - min + 2); i++){
       if (positionArray[i] > 0){
        if (sortedIndex < (sizeof(array) / sizeof(array[0]))){
            sortedArray[sortedIndex] = positionArray[i];
            sortedIndex += 1;

        }
       }

    }

    //Print sorted array
    printf("%s", "Sorted array: [");
    for (int i = 0; i < (sizeof(sortedArray) / sizeof(sortedArray[0])); i++){
        if (i < (sizeof(sortedArray) / sizeof(sortedArray[0])) - 1){
            printf("%d%s", sortedArray[i], ", ");

        }else {
            printf("%d", sortedArray[i]);

        }

    }
    printf("%s", "]");
    
    //Free allocated memory
    free(positionArray);

    return 0;

}