#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* roll_multiple_dice (int n);
void print_dice(int* dice,int n);
void play_yatzy(int number_of_dice);
int ones(int input, int number_of_dices, int dice[], int* hand);
int pairs(int number_of_dice, int handArray[]);
void print_scoreboard(int scores1, int scores2, int scores3, int scores4, int scores5, int scores6, int scores7, int score8, int score9, int score10, int score11, int score12, int score14, int score15);
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
int round10(int number_of_dice);
int of_a_kind(int* hand, int X_of_kind, int number_of_dice);
int round11(int number_of_dice);
int round12(int number_of_dice);
int straight(int* hand, int number_of_dice, int n1, int n2, int n3, int n4, int n5);
int round13(int number_of_dice);
int fullHouse(int* hand, int number_of_dice);
int round14(int number_of_dice);
int chance(int* hand, int number_of_dice);
int round15(int number_of_dice);
int yatzy(int* hand, int number_of_dice);


int main (void)
{
  int number_of_dice = 0;
  int* dice = 0; int* hand = 0;

  srand(time(NULL));

  printf("Input number of dice: ");
  scanf("%d",&number_of_dice);
  play_yatzy(number_of_dice);
  free(dice);
  return 0;   
}

void play_yatzy(int number_of_dice)
{
  int pointsRound1 = 0;int pointsRound2 = 0;int pointsRound3 = 0;int pointsRound4 = 0;int pointsRound5 = 0;int pointsRound6 = 0; int pointsRound7 = 0; int pointsRound8 = 0; int pointsRound9 = 0; int pointsRound10 = 0;
  int pointsRound11 = 0; int pointsRound12 = 0; int pointsRound13 = 0; int pointsRound14 = 0; int pointsRound15 = 0;

  pointsRound1 = round1(number_of_dice);
  pointsRound2 = round2(number_of_dice);
  pointsRound3 = round3(number_of_dice);
  pointsRound4 = round4(number_of_dice);
  pointsRound5 = round5(number_of_dice);
  pointsRound6 = round6(number_of_dice);
  pointsRound7 = round7(number_of_dice);
  pointsRound8 = round8(number_of_dice);
  pointsRound9 = round9(number_of_dice);
  pointsRound10 = round10(number_of_dice);
  pointsRound11 = round11(number_of_dice);
  pointsRound12 = round12(number_of_dice);
  pointsRound14 = round14(number_of_dice);
  pointsRound15 = round15(number_of_dice);
  print_scoreboard(pointsRound1,pointsRound2,pointsRound3,pointsRound4,pointsRound5,pointsRound6, pointsRound7, pointsRound8, pointsRound9, pointsRound10, pointsRound11,pointsRound12, pointsRound14, pointsRound15);
}

/* Ones: The sum of all dice showing the number 1. */
int round1(int number_of_dice)
{
  int pointsRound1 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  1: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound1 = ones(1, number_of_dice , hand, hand);
  return pointsRound1;
}

/* Twos: The sum of all dice showing the number 2. */
int round2(int number_of_dice)
{
  int pointsRound2 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  2: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound2 = ones(2, number_of_dice , hand, hand);
  return pointsRound2;
}

/* Threes: The sum of all dice showing the number 3. */
int round3(int number_of_dice)
{
  int pointsRound3 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  3: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound3 = ones(3, number_of_dice , hand, hand);
  return pointsRound3;
}

/* Fours: The sum of all dice showing the number 4. */
int round4(int number_of_dice)
{
  int pointsRound4 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  4: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound4 = ones(4, number_of_dice , hand, hand);
  return pointsRound4;
}

/* Fives: The sum of all dice showing the number 5. */
int round5(int number_of_dice)
{
  int pointsRound5 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  5: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound5 = ones(5, number_of_dice , hand, hand);
  return pointsRound5;
}

/* Sixes: The sum of all dice showing the number 6. */
int round6(int number_of_dice)
{
  int pointsRound6 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("ROUND  6: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound6 = ones(6, number_of_dice , hand, hand);
  return pointsRound6;
}

/* Loops through the array to see if I is equal to the number given. If input is in array it will return the amount of times input occured in array */
int ones(int input, int number_of_dices, int handArray[], int* hand)
{
  int i;
  int pointsRound1 = 0;
  for (i = 0 ; i < number_of_dices; i++)
    {
      if (handArray[i] == input)
        {
          pointsRound1 += 1;
        }
    }
  return pointsRound1;
}



/* One Pair: Two dice showing the same number. Score: Sum of those two dice. */
int round7(int number_of_dice)
{
  int pointsRound7 = 0;

  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round  7: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound7 = pairs(number_of_dice, hand);
  return pointsRound7;
}

/* Two Pairs: Two different pairs of dice. Score: Sum of dice in those two pairs. */
int round8(int number_of_dice)
{
  int pointsRound8 = 0;

  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round  8: ");
  print_dice(hand,number_of_dice);
  printf("\n");
  pointsRound8 = pairs(number_of_dice, hand);
  return pointsRound8;
}

  /* Loops through to see if hand[i] == to hand[j] and returns the sum when this occours. */  
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

/* Three of a Kind: Three dice showing the same number. Score: Sum of those three dice. */
int round9(int number_of_dice)
{
  int pointsround9 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round  9: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround9 = of_a_kind(hand, 3, number_of_dice);
  return pointsround9;
}

/*Four of a Kind: Four dice with the same number. Score: Sum of those four dice.*/
int round10(int number_of_dice)
{
  int pointsround10 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 10: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround10 = of_a_kind(hand, 4, number_of_dice);
  return pointsround10;
}

/* Find the amount of each element in the array and adds it to a value. If amount is higher than the input X_of_kind it calculates the sum of a kind. */
int of_a_kind(int* hand, int X_of_kind, int number_of_dice)
{
  int i = 0;
  int value1 = 0; int value2 = 0; int value3 = 0; int value4 = 0; int value5 = 0; int value6 = 0;
  int points = 0;

  for ( i = 0; i < number_of_dice; i++)
  {
    if (hand[i] == 1)
      {
        value1 += 1;
      }
    else if (hand[i] == 2)
      {
        value2 += 1;
      }
    else if (hand[i] == 3)
      {
        value3 += 1;
      }
    else if (hand[i] == 4)
      {
        value4 += 1;
      }
    else if (hand[i] == 5)
      {
        value5 += 1;
      }
    else if (hand[i] == 6)
      {
        value6 += 1;
      }
  }

  if (value1 >= X_of_kind)
    {
      points += value1;
    }
  if (value2 >= X_of_kind)
    {
      points += value2*2;
    }
  if (value3 >= X_of_kind)
    {
      points += value3*3;
    }
  if (value4 >= X_of_kind)
    {
      points += value4*4;
    }
  if (value5 >= X_of_kind)
    {
      points += value5*5;
    }
  if (value6 >= X_of_kind)
    {
      points+= value6*6;
    }
  return points;
}


/* Small Straight: The combination 1-2-3-4-5. Score: 15 points (sum of all the dice). */
int round11(int number_of_dice)
{
int pointsround11 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 11: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround11 = straight(hand, number_of_dice,1,2,3,4,5);
  return pointsround11;
}

/* Large Straight: The combination 2-3-4-5-6. Score: 20 points (sum of all the dice). */
int round12(int number_of_dice)
{
int pointsround12 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 12: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround12 = straight(hand, number_of_dice,2,3,4,5,6);
  return pointsround12;
}

int straight(int* hand, int number_of_dice, int n1, int n2, int n3, int n4, int n5)
{
int i = 0;
int value1 = 0; int value2 = 0; int value3 = 0; int value4 = 0; int value5 = 0; int value6 = 0;
int points = 0;

    for ( i = 0; i < number_of_dice; i++)
      {
        if (hand[i] == n1)
          {
            value1 += 1;
          }
     else if (hand[i] == n2)
     {
       value2 += 1;
     }
     else if (hand[i] == n3)
     {
       value3 += 1;
     }
     else if (hand[i] == n4)
     {
       value4 += 1;
     }
     else if (hand[i] == n5)
     {
       value5 += 1;
     }
  }

  if (value1 >= 1 && value2 >= 1 && value3 >= 1 && value4 >= 1 && value5)
    {
      points += value1*n1+value2*n2+value3*n3+value4*n4+value5*n5;
      return points;
    }
  else
  {
    return 0;
  }
}
/* Full House: Any set of three combined with a different pair. Score: Sum of all the dice. */
int round13(int number_of_dice)
{
int pointsround13 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 13: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround13 = fullHouse(hand, number_of_dice);
  return pointsround13;
}


int fullHouse(int* hand, int number_of_dice)
{


}


/* Chance: Any combination of dice. Score: Sum of all the dice. */
int round14(int number_of_dice)
{
int pointsround14 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 14: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround14 = chance(hand, number_of_dice);
  return pointsround14;
}

int chance(int* hand, int number_of_dice)
{
int i = 0;
int value1 = 0; int value2 = 0; int value3 = 0; int value4 = 0; int value5 = 0; int value6 = 0;
int points = 0;

    for ( i = 0; i < number_of_dice; i++)
      {
        if (hand[i] == 1)
          {
            value1 += 1;
          }
     else if (hand[i] == 2)
     {
       value2 += 1;
     }
     else if (hand[i] == 3)
     {
       value3 += 1;
     }
     else if (hand[i] == 4)
     {
       value4 += 1;
     }
     else if (hand[i] == 5)
     {
       value5 += 1;
     }
     else if (hand[i] == 6)
     {
       value6 += 1;
     }
  }
return value1+value2*2+value3*3+value4*4+value5*5+value6*6;
}

/* Yatzy: All five dice with the same number. Score: 50 points. */
int round15(int number_of_dice)
{
int pointsround15 = 0;
  int* hand = roll_multiple_dice(number_of_dice);
  printf("Round 15: ");
  print_dice(hand, number_of_dice);
  printf("\n");
  pointsround15 = yatzy(hand, number_of_dice);
  return pointsround15;
}

int yatzy(int* hand, int number_of_dice)
{
int i = 0;
int value1 = 0; int value2 = 0; int value3 = 0; int value4 = 0; int value5 = 0; int value6 = 0;
int points = 0;
    for ( i = 0; i < number_of_dice; i++)
      {
        if (hand[i] == 1)
          {
            value1 += 1;
          }
     else if (hand[i] == 2)
     {
       value2 += 1;
     }
     else if (hand[i] == 3)
     {
       value3 += 1;
     }
     else if (hand[i] == 4)
     {
       value4 += 1;
     }
     else if (hand[i] == 5)
     {
       value5 += 1;
     }
     else if (hand[i] == 6)
     {
       value6 += 1;
     }
  }

  if (value1 == number_of_dice)
  {
    return 50;
  }
  else if (value2 == number_of_dice)
  {
    return 50;
  }
  else if (value3 == number_of_dice)
  {
    return 50;
  }
  else if (value4 == number_of_dice)
  {
    return 50;
  }
  else if (value5 == number_of_dice)
  {
    return 50;
  }
  else if (value6 == number_of_dice)
  {
    return 50;
  }
  else
  {
    return 0;
  }
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

void print_scoreboard(int pointsRound1,int pointsRound2,int pointsRound3,int pointsRound4,int pointsRound5,int pointsRound6,int pointsRound7,int pointsRound8, int  pointsRound9,
int  pointsRound10, int  pointsRound11, int  pointsRound12, int pointsRound14, int pointsRound15 )
{ 
 printf("\n\nUppersection: \n");
 printf("ROUND  1: ONES...........: %d\n", pointsRound1);
 printf("ROUND  2: TWOS...........: %d\n", pointsRound2);
 printf("ROUND  3: THREES.........: %d\n", pointsRound3);
 printf("ROUND  4: FOURS..........: %d\n", pointsRound4);
 printf("ROUND  5: FIVES..........: %d\n", pointsRound5);
 printf("ROUND  6: SIXES..........: %d\n", pointsRound6);
 printf("ROUND  7: ONE PAIRS......: %d\n", pointsRound7); 
 printf("ROUND  8: MULTIPLE PAIRS.: %d\n", pointsRound8); 
 printf("ROUND  9: THREE OF A KIND: %d\n", pointsRound9); 
 printf("ROUND 10: FOUR OF A KIND.: %d\n", pointsRound10);
 printf("ROUND 11: SMALL STRAIGHT.: %d\n", pointsRound11);
 printf("ROUND 12: LARGE STRAIGHT.: %d\n", pointsRound12); 
 printf("ROUND 14: CHANCE.........: %d\n", pointsRound14); 
 printf("ROUND 15: YATZY..........: %d\n", pointsRound15); 
}
