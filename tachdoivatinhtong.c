#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num_str[201];
    
    // read the integer input as a string
    scanf("%s", num_str);
    
    // repeat until the length of the integer is 1
    while (strlen(num_str) > 1) {
        // split the integer into two halves
        int len = strlen(num_str);
        int mid = len / 2;
        char first_half[mid + 1], second_half[len - mid + 1];
        strncpy(first_half, num_str, mid);
        first_half[mid] = '\0';
        strncpy(second_half, num_str + mid, len - mid);
        second_half[len - mid] = '\0';
        
        // add the two halves and print the result
        int res = atoi(first_half) + atoi(second_half);
        printf("%d\n", res);
        
        // update the input integer with the new result
        sprintf(num_str, "%d", res);
    }
    
    return 0;
}
