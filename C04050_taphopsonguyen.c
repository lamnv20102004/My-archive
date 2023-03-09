#include <stdio.h>
#include <stdbool.h>

// Find the intersection of A and B and store it in result
int intersection(int A[], int n, int B[], int m, int result[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                bool unique = true;
                for (int k = 0; k < count; k++) {
                    if (result[k] == A[i]) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    result[count++] = A[i];
                }
            }
        }
    }
    return count;
}

// Find the difference of A - B and store it in result
int difference(int A[], int n, int B[], int m, int result[]) {
    int count = 0;
    bool unique;
    for (int i = 0; i < n; i++) {
        unique = true;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            for (int k = 0; k < count; k++) {
                if (result[k] == A[i]) { // Check if element is already in result
                    unique = false;
                    break;
                }
            }
            if (unique) {
                result[count++] = A[i];
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n], b[m];
    // Read the values of a[]
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Read the values of b[]
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int result[1000];

    // Intersection of A and B
    int intersection_count = intersection(a, n, b, m, result);
    // Output the intersection of A and B
    for (int i = 0; i < intersection_count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Difference A - B
    int diff_a_b[1000];
    int diff_a_b_count = difference(a, n, b, m, diff_a_b);
    // Output the difference A - B
    for (int i = 0; i < diff_a_b_count; i++) {
        printf("%d ", diff_a_b[i]);
    }
    printf("\n");

    // Difference B - A
    int diff_b_a[1000];
    int diff_b_a_count = difference(b, m, a, n, diff_b_a);
    // Output the difference B - A
    for (int i = 0; i < diff_b_a_count; i++) {
        printf("%d ", diff_b_a[i]);
    }
    printf("\n");

    return 0;
}

/*
1. Read values of n and m from input
2. Read values of a[] and b[] from input
3. Initialize result[] array to store the intersection and difference
4. Find the intersection of a[] and b[] by checking each element of a[] against each element of b[]
   - If an element is present in both a[] and b[], add it to the result[] array
   - If an element is already in the result[] array, skip it
5. Output the intersection of a[] and b[] from the result[] array
6. Find the difference between a[] and b[] by checking each element of a[] against each element of b[]
   - If an element is in a[] but not in b[], add it to the result[] array
   - If an element is already in the result[] array, skip it
7. Output the difference between a[] and b[] from the result[] array
8. Find the difference between b[] and a[] by checking each element of b[] against each element of a[]
   - If an element is in b[] but not in a[], add it to the result[] array
   - If an element is already in the result[] array, skip it
9. Output the difference between b[] and a[] from the result[] array
*/