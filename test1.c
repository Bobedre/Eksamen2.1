#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* roll_multiple_dice (int n);
void print_dice(int* dice,int n);
int play_yatzy(int n);
void ones(int input, int number_of_dices, int dice[], int* hand);

int main (void){
    int number_of_dice = 0;
    int* dice = 0; 
    int* hand1 = 0;
    int* hand2 = 0;

    srand(time(NULL));

    printf("Input number of dice: ");
    scanf("%d",&number_of_dice);
    play_yatzy(number_of_dice);
    


    free(dice);
    return 0;
}



int play_yatzy(number_of_dice){
int pointsOnes = 0; int pointsTwos = 0;
  
/*1*/
  int* hand1 = roll_multiple_dice(number_of_dice);
  print_dice(hand1,number_of_dice);
  ones(1, number_of_dice , hand1, hand1);
/*2*/
  int* hand2 = roll_multiple_dice(number_of_dice);
  ones(2, number_of_dice , hand2, hand2);
/*3*/
    /*4*/
    /*5*/
    /*6*/
    /*one pair*/
    /*two pairs*/
    /*three of a kind*/
    /*four of a kind*/
    /*small straight*/
    /*large straight*/
    /*full house*/
    
    /*chance*/

    /*yatzy*/   
printf("\nUppersection: \n");
printf("ONES : %d\n", hand1);
printf("TWOS : %d\n", hand2);

        return 0;
    }

int* roll_multiple_dice (int n)
{
  int *hand1 = malloc(n * sizeof(int));
  int i;
  for (i=0;i<n;i++)
    {
      hand1[i]=rand()%6+1;
    }
  return hand1;
}

void print_dice(int* dice,int number_of_dices){
int i;
for(i=0; i < number_of_dices ; i++)
  {
    printf("%d ",dice[i]);
  }
}

void ones(int input, int number_of_dices, int handArray[], int* hand)
{
int i;
for (i = 0 ; i < number_of_dices; i++)
  {
    if (handArray[i] == input)
      {
        *hand += 1; /* CAN'T MAKE IT CHANGE VALUE OF INT* IN MAIN */
      }
  }
}

  
