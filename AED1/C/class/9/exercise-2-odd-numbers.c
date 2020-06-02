#include <stdio.h>

int main(){
    int num = 0, count = 0;

    while(count < 9){
        num++;
        count++;

        if(num % 2 != 0){
            printf("%i\n", num);
        }
    }

    return 0;
}