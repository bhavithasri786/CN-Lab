#include <stdio.h>
#include <string.h>

int main()
{
    char data[10][100];
    int n, i;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Frame %d: ", i + 1);
        fgets(data[i], sizeof(data[i]), stdin);

        data[i][strcspn(data[i], "\n")] = '\0';
    }
    printf("\n\t\tAT THE SENDER\n");
    printf("Data as frames:\n");
    for (i = 0; i < n; i++)
    {
        printf("Frame %d: %zu%s\n",
               i + 1,
               strlen(data[i]),
               data[i]);
    }

    printf("\nData transmitted: ");

    for (i = 0; i < n; i++)
    {
        printf("%zu%s", strlen(data[i]), data[i]);
    }
    printf("\n\n\t\tAT THE RECEIVER\n");

    printf("Data received:\n");

    for (i = 0; i < n; i++)
    {
        printf("Frame %d: %s\n", i + 1, data[i]);
    }

    printf("\nData after removing count characters: ");

    for (i = 0; i < n; i++)
    {
        printf("%s", data[i]);
    }

    printf("\n");

    return 0;
}
