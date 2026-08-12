#include <stdio.h>

int main()
{
    int ip_frame[100], op_frame[200];
    int i, j = 0, n;
    int count = 0;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's and 1's only):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ip_frame[i]);
    }
    for (i = 0; i < n; i++)
    {
        op_frame[j++] = ip_frame[i];

        if (ip_frame[i] == 1)
        {
            count++;

            if (count == 5)
            {
                op_frame[j++] = 0;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    printf("\nOriginal frame: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", ip_frame[i]);
    }

    printf("\nAfter bit stuffing: ");
    for (i = 0; i < j; i++)
    {
        printf("%d", op_frame[i]);
    }

    printf("\n");

    return 0;
}
