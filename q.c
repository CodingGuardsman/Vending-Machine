//@file q.c
//@author Bryan Lee Kwan Hong (kwanhong.lee)
//@course CSD1121F22
//@section Section A
//@tutorial #Lab 3
//@date 16/9/2022
//@brief This file q.c contains the defintion of the functions 
//tile, and dispense_change

// This file q.c contains the definitions and calculations for
// functions tile and dispense_change

#include <stdio.h>
#include "q.h"

// The tile function uses the inputs TW and WL provides the
// number of pairs and number of tiles as well as the Gap at each end,
// as well as printing the inputs WL and TW used in the function definition.
void tile(float WL, float TW) {
    int NPairs = (int)((WL-TW)/(2*TW));
    int NTiles = 1+(2*NPairs);
    float Gap = ((WL-NTiles*TW)/2);
    printf("Wall length: %0.2f | Tile width: %0.2f\n", WL, TW);
    printf("Number of tiles: %i\n", NTiles);
    printf("Gap at each end: %0.2f\n", Gap);
}

// This dispense_change function reads the inputs purchase in dollars
// and cents as well as the paid money in bill value to produce change
// in the required currency.
void dispense_change(void) {
    int dollars, cents, Bill;
    scanf("%d.%d %d", &dollars, &cents, &Bill);
    int PurchasePrice = (dollars*100)+cents; 
    Bill = Bill*100;
    int Dispchange = Bill - PurchasePrice;
    if (Dispchange < 0)
    {
        printf("Not enough money\n");
        return;
    }
    int NLoonies = Dispchange/100;
    Dispchange = Dispchange%100;
    int NhalfLoonies = Dispchange/50;
    Dispchange = Dispchange%50;
    int Nquarters = Dispchange/25;
    Dispchange = Dispchange%25;
    int Ndimes = Dispchange/10;
    Dispchange = Dispchange%10;
    int NNickels = Dispchange/5;
    Dispchange = Dispchange%5;
    int Ncents = Dispchange/1;
    Dispchange = Dispchange%1;
    printf("%d loonies + %d half-loonies + %d quarters + %d dimes + %d nickels + %d pennies\n", NLoonies, NhalfLoonies, Nquarters, Ndimes, NNickels, Ncents);
}