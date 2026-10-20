#include <stdio.h>
#define MAX 100

int main() {
    int windowSize, total, frames[MAX];

    printf("Enter window size: ");
    scanf("%d", &windowSize);
    printf("Enter number of frames to transmit: ");
    scanf("%d", &total);

    if (windowSize <= 0 || total <= 0 || total > MAX) {
        printf("Invalid input (window size > 0, frames between 1 and %d).\n", MAX);
        return 1;
    }

    printf("Enter %d frames: ", total);
    for (int i = 0; i < total; i++)
        scanf("%d", &frames[i]);

    printf("\nSliding Window Protocol Simulation (no loss/corruption)\n\n");

    int base = 0;   
    int next = 0;   

    while (base < total) {
        while (next < total && next - base < windowSize) {
            printf("Sent frame %d\n", frames[next]);
            next++;
        }
        printf("ACK received for frame %d -> window slides forward\n", frames[base]);
        base++;
        if (base < total) {
            printf("Window now: [");
            for (int i = base; i < base + windowSize && i < total; i++)
                printf(" %d", frames[i]);
            printf(" ]\n\n");
        }
    }

    printf("\nAll frames transmitted and acknowledged.\n");
    return 0;
}