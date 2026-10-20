#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PACKETS 10

int main(void) {
    int packet_size[NUM_PACKETS];
    int bucket_size, output_rate;
    int in_bucket = 0, sent, tick;

    srand((unsigned) time(NULL));

    for (int i = 0; i < NUM_PACKETS; i++) {
        packet_size[i] = (rand() % 6 + 1) * 10;   
        printf("Packet[%d]: %d bytes\n", i + 1, packet_size[i]);
    }

    printf("\nEnter the Output Rate (bytes/unit time): ");
    if (scanf("%d", &output_rate) != 1 || output_rate <= 0) {
        printf("Invalid output rate.\n");
        return 1;
    }

    printf("Enter the Bucket Size (in bytes): ");
    if (scanf("%d", &bucket_size) != 1 || bucket_size <= 0) {
        printf("Invalid bucket size.\n");
        return 1;
    }

    printf("\n");

    for (tick = 1; tick <= NUM_PACKETS; tick++) {
        int size = packet_size[tick - 1];

        if (in_bucket + size > bucket_size) {
            printf("Time %2d: Packet[%d] (%d bytes) REJECTED - bucket overflow\n",
                   tick, tick, size);
        } else {
            in_bucket += size;
            printf("Time %2d: Packet[%d] (%d bytes) accepted, bucket = %d\n",
                   tick, tick, size, in_bucket);
        }

        sent = (in_bucket < output_rate) ? in_bucket : output_rate;
        in_bucket -= sent;
        printf("         Transmitted %d bytes, remaining in bucket: %d\n", sent, in_bucket);
    }

    while (in_bucket > 0) {
        sent = (in_bucket < output_rate) ? in_bucket : output_rate;
        in_bucket -= sent;
        printf("Time %2d: No new packet. Transmitted %d bytes, remaining in bucket: %d\n",
               tick++, sent, in_bucket);
    }

    printf("\nAll accepted data has been transmitted.\n");
    return 0;
}