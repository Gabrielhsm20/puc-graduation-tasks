#include <stdio.h>

int main(){
    float average = 0, score;

    for(int i = 0; i < 10; i++){
        printf("Insira a %iª nota (Ex: 10): ", i+1);
        scanf("%f", &score);
        fflush(stdin);

        average += score > 0 ? score : 0;
    }
    
    printf("A média aritimética das notas é %f", average/10);

    return 0;
}