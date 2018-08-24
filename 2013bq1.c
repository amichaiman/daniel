#include <stdio.h>
#include <values.h>

void printArray(int *a, int size);
void setDistance(int *a, int size);
void updateLeft(int *a, int locationOfZero);
void updateRight(int *a, int locationOfZero, int size);

void resetArray(int *a, int size);

int main(){
    int a[] = {0,1,1,1,0,1,1,1,1,1,0,1,1};

    printf("before:\n");
    printArray(a,13);

    setDistance(a,13);

    printf("after:\n");
    printArray(a,13);

    return 0;
}

/*  algorithm:
 *      set distance of all elements apart
 *      from zero in array to max-int
 *      if 0, update value of all neighbors
 *      according to their distance from me.
 *          -if while updating the value of
 *           the neighbor is smaller than the
 *           distance from me, meaning it is
 *           closer to another zero, stop update.
 * */
void setDistance(int *a, int size) {
    int i;

    /*  initialize values   */
    resetArray(a,size);
    for (i=0; i<size; i++){
        if (a[i] == 0){
            /*  update distances    */
            updateLeft(a,i);
            updateRight(a,i,size);
        }
    }
}

void resetArray(int *a, int size) {
    int i;

    for (i=0; i<size; i++){
        if (a[i] != 0){
            /*  max int */
            a[i] = 0x7FFFFFFF;
        }
    }
}

void updateRight(int *a, int locationOfZero, int size) {
    int distance;

    for (distance=1; distance+locationOfZero < size; distance++){
        /*  stop if value is zero or distance in the spot is smaller
         *  than distance from me   */
        if (a[locationOfZero + distance] == 0 ||
                a[locationOfZero + distance] <= distance){
            return;
        }
        a[locationOfZero + distance] = distance;
    }

}

void updateLeft(int *a, int locationOfZero) {
    int distance;

    /*  stop if value is zero or distance in the spot is smaller
         *  than distance from me   */
    for (distance=1; locationOfZero - distance >= 0; distance++){
        if (a[locationOfZero - distance] == 0 ||
            a[locationOfZero - distance] <= distance){
            return;
        }
        a[locationOfZero - distance] = distance;
    }
}

void printArray(int *a, int size) {
    int i;

    for (i=0; i<size; i++){
        printf("%d\t",a[i]);
    }
    putchar('\n');
}


