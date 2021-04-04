//Code that computes maximum interleave factor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//function that checks for subsequences
bool subsequenceCheck(int sizeA, int sizeX, int Interleave, int *arrayA, int *arrayX)
{
    //initializing subsequnce array size and the array itself
    int subSequenceSize = (sizeX * Interleave);
    int subSequenceArray[subSequenceSize];

    //declaring variables for for loop
    int i, j, temp;
    int position = 0;
    int limit = Interleave;

    //for loop that loops through and fills in the new array
    for (i = 0; i < sizeX; i++)
    {
        for (j = position; j < limit; j++)
        {
            subSequenceArray[position] = arrayX[i]; //fills subsequent array with however many times arrayX value repeats
            position++;
        }

        //increase the limit by the interleave that is passed
        limit += Interleave;
    }

    //variables for loop
    i = 0;
    j = 0;

    //while loop that checks if subsequents are present in the arrayA.
    while (j < sizeA && i < subSequenceSize)
    {
        if (subSequenceArray[i] == arrayA[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    //if statement that checks if we return true or false, given the conditions
    if (subSequenceSize == i)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //initializing variables
    int sizeA, sizeX;
    long inputBuffer;

    //collecting input of the size of Array A and size of Array X
    scanf("%d %d", &sizeA, &sizeX);

    //calculate interleave factor
    int Interleave = sizeA / sizeX;

    //initializing array and dynamically allocate memory for the array
    int *arrayA;
    arrayA = (int *)malloc(sizeA * sizeof(int));

    int *arrayX;
    arrayX = (int *)malloc(sizeX * sizeof(int));

    int i, j; // initializing variables for for loop

    //for loop that scans user input and fills arrays by position for arrayA
    for (i = 0; i < sizeA; i++)
    {
        scanf("%d", &arrayA[i]);
    }
    scanf("%ld", &inputBuffer); // input of that -999999999

    //for loop that scans user input and fills arrays by position for arrayX
    for (j = 0; j < sizeX; j++)
    {
        scanf("%d", &arrayX[j]);
    }
    scanf("%ld", &inputBuffer); // input of that -999999999

    //declaring variables for binary search
    int low = 0;
    int max = 0;
    int mid = 0;
    int high = Interleave;

    //binary search loop that checks for low, mid, high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (subsequenceCheck(sizeA, sizeX, mid, arrayA, arrayX))
        {
            printf("low %d mid %d high %d passed\n", low, mid, high);
            max = mid;
            low = mid + 1;
        }
        else
        {
            printf("low %d mid %d high %d failed\n", low, mid, high);
            high = mid - 1;
        }
    }

    //printing out maximum repeats
    printf("Maximum repeats is %d\n", max);

    //freeing memory
    free(arrayA);
    free(arrayX);

    return 0;
}
