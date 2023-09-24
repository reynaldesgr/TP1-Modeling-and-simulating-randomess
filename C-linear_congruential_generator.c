/**
 * @file linear_congruential_generator.c
 * @brief This file implements a Linear Congruential Generator.
    A linear congruential generator (LCG) is an algorithm that yields a sequence
    of pseudo-randomized numbers calculed with a discontinuous picewise linear equation.
    (Wikipedia)
 * 
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long int a = 5;
unsigned long int c = 1;
unsigned long int m = 16;


unsigned long int seed = 5;


/**
 *  For Question 8 : Test with Park-Miller LCG (Wikipedia)
 * Comment the constants (a, c, m) below and uncommented these ones
/*

unsigned long int a = 16807;
unsigned long int c = 0;
unsigned long int m = 2147483647; // 2^31 - 1

*/

/**
 * @brief This function implements a LCG function using integer numbers.
 *
 * @return A pseudo-random number (seed)
*/

unsigned long int intRand()
{
    seed = (a * seed + c) % m;
    
    return seed;
}


/**
 * @brief This function implements a LCG function using real/float numbers.
 *
 * @return A pseudo-random number (seed)
*/

float floatRand()
{
    seed = (a * seed + c) % m;
    
    return (float) seed/16;  
}


/**
 * @brief Testing function for intRand()
*/

void testIntRand()
{
    unsigned long int   res;
    printf("\nintRand() \t \n");
    for (int i = 0; i < 32; i++)
    {
        res = intRand();
        printf("%d : %lu \n", i+1, res);
    }

}

/**
 * @brief Testing function for floatRand()
*/

void testFloatRand()
{
    float res;
    printf("\nfloatRand() \t \n");
    for (int i = 0; i < 32; i++)
    {
        res = floatRand();
        printf("%d : %.4f \n", i+1, res);
    }
}

int main()
{
    printf("\n -- Seed = 5 -- \n");    
    testIntRand();
    testFloatRand();

    // Different seeds
    seed = 189;

    printf("\n -- Seed = 189 -- \n");
    testIntRand();
    testFloatRand();

    seed = 0;

    printf("\n -- Seed = 0 -- \n");
    testIntRand();
    testFloatRand();

    seed = RAND_MAX;

    printf("\n -- Seed = RAND_MAX -- \n");
    testIntRand();
    testFloatRand();

    return 0;
}
