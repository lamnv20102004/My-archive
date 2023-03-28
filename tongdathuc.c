#include <stdio.h>

#define MAX 10001

typedef struct {
    int heso;
    int bac;
    int tmp1;
    int tmp2;
} dathuc;

dathuc term[MAX], term1[MAX], term2[MAX];



void input1(char poly[]) {
    int tmp1=0, tmp2=0;
    char *ptr = poly; // pointer to the current character
    char *start = poly; // pointer to the start of the term
    while (*ptr) {
        if (*ptr == '*') {
            // convert the substring from start to ptr-1 to an integer using strtol
            term1[tmp1].heso = strtol(start, NULL, 10);
            tmp1++;
        }
        if (*ptr == '^') {
            sscanf(ptr + 1, "%d", &term1[tmp2].bac);
            tmp2++;
            // move the start pointer to the next term after the +
            start = strchr(ptr, '+') + 1;
        }
        ptr++;
    }
}

void input2(char poly[]) {
    int tmp1=0, tmp2=0;
    char *ptr = poly; // pointer to the current character
    char *start = poly; // pointer to the start of the term
    while (*ptr) {
        if (*ptr == '*') {
            // convert the substring from start to ptr-1 to an integer using strtol
            term2[tmp1].heso = strtol(start, NULL, 10);
            tmp1++;
        }
        if (*ptr == '^') {
            sscanf(ptr + 1, "%d", &term2[tmp2].bac);
            tmp2++;
            // move the start pointer to the next term after the +
            start = strchr(ptr, '+') + 1;
        }
        ptr++;
    }
}


int size(dathuc term[MAX]){
    int count=0;
    for(int i=0;i<MAX;i++){
        if(term[i].heso==0){
            return count;
        }
        else count++;
    }
}


void add(int n, int k){
    int temp=0, ans;
    ans = (term1[0].bac>term2[0].bac) ? term1[0].bac : term2[0].bac ;
    ans++;
    // create arrays of exponents for both polynomials
    int exp1[ans], exp2[ans];
    int index;
    index=n-1;
    for(int i=0;i<ans;i++){
        if(i==term1[index].bac){
            exp1[i]=term1[index].heso;
            index--;
        }
        else{
            exp1[i]=-1;
        }
    }

    index=k-1;
    for(int i=0;i<ans;i++){
        if(i==term2[index].bac){
            exp2[i]=term2[index].heso;
            index--;
        }
        else{
            exp2[i]=-1;
        }
    }

    for(int i=0;i<ans;i++){
        term[i].heso=0;
    }

    for(int i=0;i<ans;i++){
        if(exp1[i] != -1 && exp2[i] != -1){
            term[i].heso=exp1[i]+exp2[i];
            index++;
        }
        if(exp1[i] != -1 && exp2[i] == -1){
            term[i].heso=exp1[i];
            index++;
        }
        if(exp1[i] == -1 && exp2[i] != -1){
            term[i].heso=exp2[i];
        }
    }

    // output the result
    for (int i = ans-1; i >= 0 ; i--) {
        if (term[i].heso != 0) {
            printf("%d*x^%d", term[i].heso, i);
            if (i != 0) {
                printf(" + ");
            }
        }
    }  
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--){
        char poly1[100001], poly2[100001];
        fgets(poly1, sizeof(poly1), stdin);
        fgets(poly2, sizeof(poly2), stdin);
        input1(poly1);
        input2(poly2);
        int n = size(term1);
        int k = size(term2);
        add(n,k);
        printf("\n");
    }
}