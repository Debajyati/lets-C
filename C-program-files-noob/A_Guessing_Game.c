#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /*Create a Guessing Game*/
    int num, guess,numofguess=1;
    srand(time(0));
    num=rand()%100+1;
    do{
        printf("Enter the number you guessed(*ofcourse between 1 & 100)\n");
        scanf("%d",&guess);
        if (guess<num)
        {
            printf("Pick a higher number ,please...\n");
        }

        else if (guess>num)
        {
            printf("Pick a lower number ,please...\n");
        }

        else
        {
            printf("You guessed it in %d attempts\n",numofguess);
        }

        numofguess++;
        
    } while (guess!=num);
    
    return 0;
}