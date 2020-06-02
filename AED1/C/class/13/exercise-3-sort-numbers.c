#include <stdio.h>

void sortNumbers(int num) {
    printf("%i\n", num);
    
    if(num > 1){
        sortNumbers(num-1);
    }
}

int main() {

    sortNumbers(10);

    return 0;
}