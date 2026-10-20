#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FRAME_TEXT_SIZE 3
#define MAX_NO_OF_FRAMES 127

char inputMessage[FRAME_TEXT_SIZE * MAX_NO_OF_FRAMES];

struct Frame {
    char text[FRAME_TEXT_SIZE];
    int sequenceNumber;
} frames[MAX_NO_OF_FRAMES], shuffledFrames[MAX_NO_OF_FRAMES];

int assignSequenceNumbers() {
    int i = 0, j = 0, frameIndex = 0;

    while (i < strlen(inputMessage)) {
        frames[frameIndex].sequenceNumber = frameIndex;
        for (j = 0; j < FRAME_TEXT_SIZE && inputMessage[i] != '\0'; j++)
            frames[frameIndex].text[j] = inputMessage[i++];
        frameIndex++;
    }

    printf("\nAfter assigning sequence numbers:\n");
    for (i = 0; i < frameIndex; i++)
        printf("%d:%s ", frames[i].sequenceNumber, frames[i].text);

    return frameIndex;
}

void generateRandomArray(int *randomArray, int limit) {
    int r, i = 0, j;
    while (i < limit) {
        r = rand() % limit;
        for (j = 0; j < i; j++)
            if (randomArray[j] == r)
                break;
        if (i == j)
            randomArray[i++] = r;
    }
}

void shuffleFrames(int totalFrames) {
    int randomIndices[totalFrames];
    generateRandomArray(randomIndices, totalFrames);

    for (int i = 0; i < totalFrames; i++)
        shuffledFrames[i] = frames[randomIndices[i]];

    printf("\n\nAfter shuffling:\n");
    for (int i = 0; i < totalFrames; i++)
        printf("%d:%s ", shuffledFrames[i].sequenceNumber, shuffledFrames[i].text);
}

void sortFrames(int totalFrames) {
    int i, j, swapped;
    struct Frame temp;

    for (i = 0; i < totalFrames - 1; i++) {
        swapped = 0;
        for (j = 0; j < totalFrames - i - 1; j++) {
            if (shuffledFrames[j].sequenceNumber > shuffledFrames[j + 1].sequenceNumber) {
                temp = shuffledFrames[j];
                shuffledFrames[j] = shuffledFrames[j + 1];
                shuffledFrames[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int totalFrames;

    printf("Enter the message: ");
    fgets(inputMessage, sizeof(inputMessage), stdin);

    size_t len = strlen(inputMessage);
    if (len > 0 && inputMessage[len - 1] == '\n')
        inputMessage[len - 1] = '\0';

    totalFrames = assignSequenceNumbers();
    shuffleFrames(totalFrames);
    sortFrames(totalFrames);

    printf("\n\nAfter sorting (Reconstructed message):\n");
    for (int i = 0; i < totalFrames; i++)
        printf("%s", shuffledFrames[i].text);
    printf("\n\n");

    return 0;
}