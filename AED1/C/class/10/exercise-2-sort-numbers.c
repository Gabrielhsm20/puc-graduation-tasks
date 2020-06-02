#include <stdio.h>

int main(){
    float higher = 0, lowest = 0, num;

    for(int i = 0; i < 5; i++){
        printf("Insira o %iº número (Ex: 10): ", i+1);
        scanf("%f", &num);
        fflush(stdin);

        higher = i == 0 ? num : num > higher ? num : higher;
        lowest = i == 0 ? num : num < lowest ? num : lowest;
    }
    
    printf("O maior número é: %f\nO menor número é: %f", higher, lowest);

    return 0;
}