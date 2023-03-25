#include<stdio.h>

int count_pairs(char a, char input[], int check[26]) {

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


/*  char prev = '\0'; 
  for (int i = a1_index + 1; i < a2_index; i++) {

    if (input[i] == prev) {
      pairs++;
      prev = '\0';
    } else {

      prev = input[i];
    }
  }
  */

 int prev[26]={0};

 for (int i=a1_index + 1; i < a2_index; i++){
  if(check[input[i]-'A']<2){
    prev[input[i]-'A']++;
    check[input[i]-'A']++;
  }
 }
 for(int i = 0; i < 26; i++){
  if(prev[i]==2){
    pairs++;
  }
 }

  return pairs;
}


int total_pairs(char input[]) {


   int total = 0;
   int check[26]={0};

   for (char a = 'A'; a <= 'Z'; a++) {
     total += count_pairs(a, input, check);
   }

   //total /= 2;

   return total;
}

int main() {

   char input[53];
   scanf("%s", input);
   printf("%d\n", total_pairs(input));
  
}
