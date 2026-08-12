#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[100], destuffed[100];
    int i, j = 0, count = 0;

    printf("Enter the stuffed bit string: ");
    scanf("%s", stuffed);

    for (i = 0; i < strlen(stuffed); i++) {
        destuffed[j++] = stuffed[i];

        if (stuffed[i] == '1') {
            count++;

            // Remove the 0 inserted after five consecutive 1s
            if (count == 5) {
                if (stuffed[i + 1] == '0') {
                    i++;
                }
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    destuffed[j] = '\0';

    printf("After bit destuffing: %s\n", destuffed);

    return 0;
}
