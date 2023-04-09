#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 1; i <= t; i++) {
        char s1[201], s2[21];
        fgets(s1, 201, stdin);
        fgets(s2, 21, stdin);
        s1[strcspn(s1, "\n")] = '\0';
        s2[strcspn(s2, "\n")] = '\0';
        int len1 = strlen(s1), len2 = strlen(s2);
        printf("Test %d: ", i);
        for (int j = 0; j < len1; j++) {
            int k;
            for (k = 0; k < len2 && tolower(s1[j + k]) == tolower(s2[k]); k++);
            if (k == len2) {
                j += len2 - 1;
            } else {
                putchar(s1[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}
