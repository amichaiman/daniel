#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}


int wordCount(char *a){
    int i=0;
    if (!a || a[0] == '\0'){    // a == NULL, a
        return 0;
    }

    /*  go to first letter or number    */
    while (!isalpha(a[i]) && !isdigit(a[i])){
        if (a[i] == '\0'){
            return 0;
        }
        i++;
    }

    /*  go to non word character   */
    while (isalpha(a[i]) || isdigit(a[i])){
        if (a[i] == '\0'){
            return 1;
        }
        i++;
    }

    return 1 + wordCount(a+i);
}
