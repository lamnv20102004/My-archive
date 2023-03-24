#include<stdio.h>

int count_pairs(char a, char input[]) {

  int pairs = 0;

  int a1_index = -1; 
  int a2_index = -1; 
  for (int i = 0; i < 52; i++) {
    if (input[i] == a) {
      if (a1_index == -1) {
        a1_index = i; 
      } else {
        a2_index = i; 
        break; 
      }
    }
  }

  
  if (a1_index == -1 || a2_index == -1) {
    return 0; 
  }


  char prev = '\0'; 
  for (int i = a1_index + 1; i < a2_index; i++) {

    if (input[i] == prev) {
      pairs++;
      prev = '\0';
    } else {

      prev = input[i];
    }
  }

  return pairs;
}


int total_pairs(char input[]) {


   int total = 0;

   for (char a = 'A'; a <= 'Z'; a++) {
     total += count_pairs(a, input);
   }

   total /= 2;

   return total;
}

int main() {

   char input[53];
   scanf("%s", input);
   printf("%d\n", total_pairs(input));
  
}
