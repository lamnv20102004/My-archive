#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, k, pos, extra = 0;
    bool covered[1001] = {0};

    scanf("%d %d %d", &n, &m, &k);

    int a[m];

    // Read the positions of the existing bulbs into an array
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    // Mark the covered positions by the existing bulbs
    for (int i = 0; i < m; i++) {
        pos = a[i];
        for (int j = pos - k; j <= pos + k; j++) {
            if (j >= 1 && j <= n) {
                covered[j] = true;
            }
        }
    }

    // Add extra bulbs at the uncovered positions
    for (int i = 1; i <= n; i++) {
        if (!covered[i]) {
            extra++;
            i += k; // Skip the next k positions covered by the new bulb
        }
    }

    printf("%d\n", extra);

    return 0;
}
