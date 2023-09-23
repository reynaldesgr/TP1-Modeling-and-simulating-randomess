/**
 * @file coin_tossing_simulation.c
 * @brief This file contains tossing simulation using rand() and
    test the equidistribution of these experiments (runs)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX6  6
#define MAX10 10 

#define LIMIT_RUNS 100

/**
 * @brief Simulates flipping a coin.
 * This function simulates flipping a coin.
 *
 * @return 0 for tails, 1 for heads
*/

unsigned int doAFlipCoin()
{
    return rand() % 2;
}

/**
 * @brief Simulate rolling a 6-sided dice
 * This function simulates rolling a 6-sided dice.
 *
 * @return A random number between 1 and 6
*/

unsigned int doAFlipDice6()
{
    return rand() % 7;
}

/**
 * @brief Simulate rolling a 10-sided dice
 * This function simulates rolling a 10-sided dice.
 *
 * @return A random number between 1 and 10
*/

unsigned int doAFlipDice10()
{
    return rand() % 11;
}

/**
 * @brief Display an array of dice results.
 * This function displays the results of a dice simulation.
 *
 * @param dice An array containing a instance of a dice rolling simulation. 
 * Indices represent the faces of a dice. The frequency of appearance corresponding to the index i/face i is contained in dice[i]
 * @param max The maximum value for a dice
*/

void displayDiceArray(unsigned int * dice, int max)
{
    printf("\n--- Simulation ---\n");

    for (int i = 0; i < max; i++)
    {
        printf(" Face %d \t : \t %d \n", i+1, dice[i]);
    }
}

/**
 * @brief Calculate the mean of simulation's values.
 * 
 * @param array Values of a simulation
 * @param size Size of the simulation/Number of experiments
 * 
 * @return Mean of simulation's values
 * 
*/

double calculateMean(unsigned int * array, int size)
{
    int sum;

    for (int i = 0; i < size; i++)
    {
        sum+=array[i];
    }

    return (double) sum / size;

}

/**
 * @brief Calcule the deviation of simulation's values.
 * 
 * @param array Values of a simulation
 * @param size Size of the simulation/Number of experiments
 * @param mean Mean of simulation's values
 * 
 * @return Deviation of simulation's values
 * 
*/

double calculateDeviation(unsigned int * array, int size, double mean)
{
    double sumSquare = 0.0;

    for (int i = 0; i < size; i++)
    {
        double diff = array[i] - mean;
        sumSquare  += diff * diff;
    }
    
    return sqrt(sumSquare / size);
}

int main()
{
    unsigned int coin;
    unsigned int heads;
    unsigned int tails;
    unsigned int face;

    double       meanDice6;
    double       deviationDice6;

    double       meanDice10;
    double       deviationDice10;

    unsigned int dice6[7]   = {0};
    unsigned int dice10[11] = {0};
    
    // tails = 0 / heads = 1
    tails = 0;
    heads = 0;

    printf("\n--- Flip Coin Simulation ---\n");
    // Flip Coin Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        coin = doAFlipCoin();
        if (coin)
        {
            heads++;
        }else{
            tails++;
        }
    }

    printf("Heads : %d | Tails : %d \n", heads, tails);

    printf("\n--- 6-Dice Simulation ---\n");
    
    // 6-Dice Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        face = doAFlipDice6();
        dice6[face]++;
    } 
    displayDiceArray(dice6, MAX6);

    meanDice6      = calculateMean(dice6, 7);
    deviationDice6 = calculateDeviation(dice6, 7, meanDice6);

    printf("Mean of 6-Dice simulation : %.4f\n", meanDice6);
    printf("Deviation of 6-Dice simulation : %.4f\n", deviationDice6);

    
    printf("\n--- 10-Dice Simulation ---\n");
    
    // 10-Dice Simulation
    for (int i = 0; i < LIMIT_RUNS; i++)
    {
        face = doAFlipDice10();
        dice10[face]++;
    } 
    displayDiceArray(dice10, MAX10);

    meanDice10      = calculateMean(dice10, 11);
    deviationDice10 = calculateDeviation(dice10, 11, meanDice10);

    printf("Mean of 10-Dice simulation : %.4f\n", meanDice10);
    printf("Deviation of 10-Dice simulation : %.4f\n", deviationDice10);

    return 0;
}