#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* roll_multiple_dice (int n);
void print_dice(int* dice,int n);
void play_yatzy(int number_of_dice);
int ones(int input, int number_of_dices, int dice[], int* hand);
int pairs(int number_of_dice, int handArray[]);
void print_scoreboard(int scores1, int scores2, int scores3, int scores4, int scores5, int scores6, int scores7, int score8, int score9);
int round1(int number_of_dice);
int round2(int number_of_dice);
int round3(int number_of_dice);
int round4(int number_of_dice);
int round5(int number_of_dice);
int round6(int number_of_dice);
int round7(int number_of_dice);
int int_cmp(const void *a, const void *b);
int round8( int number_of_dice);
int round9( int number_of_dice);


int main (void){
    int number_of_dice = 0;
    int* dice = 0; int* hand1 = 0;int* hand2 = 0; int* hand3 = 0; int* hand4 = 0; int* hand5 = 0; int* hand6 = 0; int *hand7 = 0; int *hand8 = 0;
    int *hand9 = 0; int* hand10 = 0; int* hand11 = 0; int* hand12 = 0; int* hand13 = 0;
    int *twoPairs = 0;
    int *sumOfPairs = 0;

    srand(time(NULL));

    printf("Input number of dice: ");
    scanf("%d",&number_of_dice);
    play_yatzy(number_of_dice);
    free(dice);
    return 0;   
}

void play_yatzy(int number_of_dice){
int pointsRound1 = 0;int pointsRound2 = 0;int pointsRound3 = 0;int pointsRound4 = 0;int pointsRound5 = 0;int pointsRound6 = 0; int pointsRound7 = 0; int pointsRound8 = 0; int pointsRound9 = 0;

pointsRound1 = round1(number_of_dice);
pointsRound2 = round2(number_of_dice);
pointsRound3 = round3(number_of_dice);
pointsRound4 = round4(number_of_dice);
pointsRound5 = round5(number_of_dice);
pointsRound6 = round6(number_of_dice);
pointsRound7 = round7(number_of_dice);
pointsRound8 = round8(number_of_dice);
pointsRound9 = round9(number_of_dice);
print_scoreboard(pointsRound1,pointsRound2,pointsRound3,pointsRound4,pointsRound5,pointsRound6, pointsRound7, pointsRound8, pointsRound9);
}

/*1*/
int round1(int number_of_dice)
{
int pointsRound1 = 0;
int* hand1 = roll_multiple_dice(number_of_dice);
printf("ROUND  1: ");
  print_dice(hand1,number_of_dice);
  printf("\n");
  pointsRound1 = ones(1, number_of_dice , hand1, hand1);
  return pointsRound1;
}

int round2(int number_of_dice)
{
int pointsRound2 = 0;
int* hand2 = roll_multiple_dice(number_of_dice);
printf("ROUND  2: ");
  print_dice(hand2,number_of_dice);
  printf("\n");
  pointsRound2 = ones(1, number_of_dice , hand2, hand2);
  return pointsRound2;
}

int round3(int number_of_dice)
{
int pointsRound3 = 0;
int* hand3 = roll_multiple_dice(number_of_dice);
printf("ROUND  3: ");
  print_dice(hand3,number_of_dice);
  printf("\n");
  pointsRound3 = ones(3, number_of_dice , hand3, hand3);
  return pointsRound3;
}

int round4(int number_of_dice)
{
int pointsRound4 = 0;
int* hand4 = roll_multiple_dice(number_of_dice);
printf("ROUND  4: ");
  print_dice(hand4,number_of_dice);
  printf("\n");
  pointsRound4 = ones(4, number_of_dice , hand4, hand4);
  return pointsRound4;
}

int round5(int number_of_dice)
{
int pointsRound5 = 0;
int* hand5 = roll_multiple_dice(number_of_dice);
printf("ROUND  5: ");
  print_dice(hand5,number_of_dice);
  printf("\n");
  pointsRound5 = ones(5, number_of_dice , hand5, hand5);
  return pointsRound5;
}

int round6(int number_of_dice)
{
int pointsRound6 = 0;
int* hand6 = roll_multiple_dice(number_of_dice);
printf("ROUND  6: ");
  print_dice(hand6,number_of_dice);
  printf("\n");
  pointsRound6 = ones(6, number_of_dice , hand6, hand6);
  return pointsRound6;
}

/* ONE PAIR */
int round7(int number_of_dice)
  {
      int pointsRound7 = 0;

    int* hand7 = roll_multiple_dice(number_of_dice);
    printf("Round  7: ");
    print_dice(hand7,number_of_dice);
    printf("\n");
    pointsRound7 = pairs(number_of_dice, hand7);
    return pointsRound7;
  }

/* X AMOUNT OF PAIRS */
int round8(int number_of_dice)
  {
      int pointsRound8 = 0;

    int* hand8 = roll_multiple_dice(number_of_dice);
    printf("Round  8: ");
    print_dice(hand8,number_of_dice);
    printf("\n");
    pointsRound8 = pairs(number_of_dice, hand8);
    return pointsRound8;
  }

/* Three of a Kind: Three dice showing the same number. Score: Sum of those three dice. */
int round9(int number_of_dice)
{
  int i = 0;
  int value1 = 0; int value2 = 0; int value3 = 0; int value4 = 0; int value5 = 0; int value6 = 0;
  int pointsRound9 = 0;
  int* hand9 = roll_multiple_dice(number_of_dice);
  printf("Round  9: ");
  print_dice(hand9, number_of_dice);
  for ( i = 0; i < number_of_dice; i++)
  {
     if (hand9[i] == 1)
     {
       value1 += 1;
     }
     else if (hand9[i] == 2)
     {
       value2 += 1;
     }
     else if (hand9[i] == 3)
     {
       value3 += 1;
     }
     else if (hand9[i] == 4)
     {
       value4 += 1;
     }
     else if (hand9[i] == 5)
     {
       value5 += 1;
     }
     else if (hand9[i] == 6)
     {
       value6 += 1;
     }
  }

  if (value1 >= 3)
  {
    pointsRound9 += value1;
  }
  if (value2 >= 3)
  {
    pointsRound9 += value2*2;
  }
  if (value3 >= 3)
  {
    pointsRound9 += value3*3;
  }
  if (value4 >= 3)
  {
    pointsRound9 += value4*4;
  }
  if (value5 >= 3)
  {
    pointsRound9 += value5*5;
  }
  if (value6 >= 3)
  {
    pointsRound9 += value6*6;
  }

 return pointsRound9;
}

int* roll_multiple_dice (int n)
{
  int *dice = malloc(n * sizeof(int));
  int i;
  for (i=0;i<n;i++)
    {
    dice[i]=rand()%6+1;
    }
  return dice;
}

void print_dice(int* dice,int number_of_dices){
int i;
for(i=0; i < number_of_dices ; i++)
  {
    printf("%d ",dice[i]);
  }
}

int ones(int input, int number_of_dices, int handArray[], int* hand)
{
int i;
int pointsRound1 = 0;
for (i = 0 ; i < number_of_dices; i++)
  {
    if (handArray[i] == input)
      {
        pointsRound1 += 1; /* CAN'T MAKE IT CHANGE VALUE OF INT* IN MAIN */
      }
  }
  return pointsRound1;
}

/* UNTESTED!*/
/* One Pair: Two dice showing the same number. Score: Sum of those two dice. */  
int pairs(int number_of_dice, int hand[])
{
int i = 0;
int j = 0;
int points = 0;

for (i = 0; i < number_of_dice ; i++)
  {
    for (j = i+1; j <= number_of_dice; j++)
      {
        if (hand[i] == hand[j])
          {
           points += hand[i]+hand[j];
          }
      }
  }
  return points;
}


/*compare function from http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml*/
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
}


void print_scoreboard(int pointsRound1,int pointsRound2,int pointsRound3,int pointsRound4,int pointsRound5,int pointsRound6,int pointsRound7,int pointsRound8, int  pointsRound9 )
{ 
 printf("\n\nUppersection: \n");
 printf("ONES...........: %d\n", pointsRound1);
 printf("TWOS...........: %d\n", pointsRound2);
 printf("THREES.........: %d\n", pointsRound3);
 printf("FOURS..........: %d\n", pointsRound4);
 printf("FIVES..........: %d\n", pointsRound5);
 printf("SIXES..........: %d\n", pointsRound6);
 printf("ONE PAIRS......: %d\n", pointsRound7); 
 printf("MULTIPLE PAIRS.: %d\n", pointsRound8); 
printf("THREE OF A KIND.: %d\n", pointsRound9); 
}
