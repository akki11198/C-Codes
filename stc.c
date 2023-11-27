#include <stdio.h>
#include <string.h>

typedef struct
{
    double price;
    char make[50];
} car_t;

int main()
{
    car_t newcar[5];
    int i, n;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Input make of car: ");

        fgets(newcar[i].make, 50, stdin);

        printf("\nInput price of car: ");

        scanf("%lf", &newcar[i].price);
    }

    for (i = 0; i < n; i++)
    {
        printf("The make is: %s", newcar[i].make);

        printf("The price is: $%lf", newcar[i].price);
    }

    return 0;
}