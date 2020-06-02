#include <stdio.h>
#include <math.h>

struct FortCarsData {
    char agency[30];
    float latitude;
    float longitude;
    int time;
};

void insertRecord(struct FortCarsData fortCar[], int amount) {
    for(int i = 0; i < amount; i++) {
        printf("Digite o nome da agencia, latitude, longitude e tempo (em seg.) parado do ponto %i (Ex: Caixa 10 10 60): ", i+1);
        scanf("%s %f %f %i", &fortCar[i].agency, &fortCar[i].latitude, &fortCar[i].longitude, &fortCar[i].time);
        fflush(stdin);
    }
}

int main() {
    int amount,
        timeTotal = 0,
        longerTime = 0;

    float averageTime = 0,
          distanceTotal = 0,
          lastLat = 0,
          lastLong = 0;

    printf("Quantos registros deseja inserir? (Ex: 10): ");
    scanf("%i", &amount);
    fflush(stdin);

    struct FortCarsData fortCar[amount];
    insertRecord(fortCar, amount);

    printf("\nREGISTROS:\n");
    for(int i = 0; i < amount; i++) {
        printf("|\tID: %i\t|\tAGENCIA: %s\t|\tLATITUDE: %0.2f\t|\tLONGITUDE: %0.2f\t|\tTEMPO PARADO: %i\t|\n", i, fortCar[i].agency, fortCar[i].latitude, fortCar[i].longitude, fortCar[i].time);

        if(i==0 || longerTime < fortCar[i].time)
            longerTime = fortCar[i].time;

        if(i>0)
            distanceTotal += sqrt(pow(fortCar[i].latitude - lastLat, 2) + pow(fortCar[i].longitude - lastLong, 2));
        
        lastLat = fortCar[i].latitude;
        lastLong = fortCar[i].longitude;
        timeTotal += fortCar[i].time;
        averageTime += fortCar[i].time;
    }

    averageTime /= amount;

    printf("\nESTATISTICAS:\n");
    printf("|\tDISTANCIA TOTAL: %0.2f\t|\tTEMPO TOTAL: %i\t|\tMEDIA DE TEMPO: %0.2f\t|\tMAIOR TEMPO: %i\t|\n", distanceTotal, timeTotal, averageTime, longerTime);

    return 0;
}