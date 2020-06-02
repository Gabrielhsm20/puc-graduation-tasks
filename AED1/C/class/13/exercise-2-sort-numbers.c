#include <stdio.h>

void sortNumbers(int num) {
    printf("%i\n", num);
    
    if(num < 10){
        sortNumbers(num+1);
    }
}

int main() {

    sortNumbers(1);

    return 0;
}