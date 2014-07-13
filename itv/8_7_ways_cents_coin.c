/*
 * number of ways of representing n cents 
 * with coins
 */

#include <stdio.h>
#include <stdlib.h>

int make_change(int money_amount, int curr_coin){

  int next_coin = 0;
  switch(curr_coin){
    case 25:
      next_coin = 10;
      break;
    case 10:
      next_coin = 5;
      break;
    case 5:
      next_coin = 1;
      break;
    case 1:
      return 1;
    default:
      return 0;
  }
  int ways = 0;
  for(int i = 0; i * curr_coin <= money_amount; ++i){
    ways += make_change(money_amount - i * curr_coin, next_coin);
  }
  return ways;
}

int main(int argc, char **argv){

  if(argc != 2){
    printf("need one para, amount of money\n");
    return 0;
  }

  int ways = 0;
  int amount = atol(argv[1]);
  printf("%s\n", argv[1]);
  printf("%d\n", amount);
  ways = make_change(amount, 25);
  printf("%d\n", ways);

  return 0;
}
