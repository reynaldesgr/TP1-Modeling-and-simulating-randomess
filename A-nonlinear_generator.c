/**
 * @file A-nonlinear_generator.c
 * @brief This file contains functions for a nonlinear random number generator.
 *
 * This file implements a nonlinear random approach using the middle-square method.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function implements the mathematical function square : f(x) -> x^2.
 *
 * @param number Number to which the square function is applied
 *
 * @return The squared number
*/

#define RUNS 40

unsigned int square(unsigned int number)
{
    return number * number;
}

/**
 * @brief This function implements the middle-square method.
 The middle-square method generates pseudorandom numbers.
 An n-digit starting value is created and squared, producing a 2n-digit number.
 *
 * @param squarenNum Squared number using for the middle-square method
 *
 * @return A pseudorandom number
*/

unsigned int middleSquareRandom(unsigned int squareNumber)
{   
    unsigned int randomNumber;

    squareNumber         /=100;
    randomNumber          = squareNumber % 10000;

    return randomNumber;
}

/**
 * @brief This function test the middleSquareRandom function.
    a certain number of times from a seed given as a parameter.
    Additional/Personal adding : detection of a cycle in the 
    pseudo-random generation
 *
 * @param seed Seed used to generate the pseudo-random number
*/

int test(unsigned int seed)
{
    unsigned int squareNumber;

    // Cycles detection
    int isCycleDetected;
    unsigned int * generatedValues = malloc(RUNS * sizeof(unsigned int));
    
    // Memory allocation error
    if (NULL == generatedValues)
    {
        return -1;
    }

    // Boolean variables checking if a cycle is detected
    isCycleDetected = 0;
    
    printf("\n Seed : %d \n", seed);
    for (int i = 0; i < RUNS; i++)
    {  
        squareNumber = square(seed);
        
        printf("%08d \n", squareNumber);
        printf("N %d : %u  \n", i, seed);
        
        // Check if there is a cycle in the generation
        if (!isCycleDetected)
        {
            for (int j = 0; j < i; j++)
            {
                if (generatedValues[j] == squareNumber)
                {
                    printf("! -- Cycle after %d generations -- !\n", i);
                    isCycleDetected = 1;
                    free(generatedValues);
                    break;
                }
            }
        }

        generatedValues[i]  = squareNumber;
        seed                = middleSquareRandom(squareNumber);
    }
}


int main()
{
    unsigned int seed        = 1234;

    // Cycles
    unsigned int seed2       = 4100;

    // Pseudo-Cycles 
    unsigned int seed3       = 1324;
    //unsigned int seed4     = 1301;

    printf("\n-- Question 1 --\n");
    test(seed);
    printf("\n-- Question 2 --\n");
    test(seed2);
    printf("\n-- Question 3 --\n");
    test(seed3);

    return 0;
}
