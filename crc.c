#include <stdio.h>
#include <string.h>
int main()
{
    char data[100], key[50], temp[150];
    int i, j, k, n;
    printf("Enter the data: ");
    scanf("%s", data);
    printf("Enter the generator: ");
    scanf("%s", key);
    n = strlen(data);
    k = strlen(key);
    strcpy(temp, data);
    for (i = 0; i < k - 1; i++)
    {
        temp[n + i] = '0';
    }
    temp[n + k - 1] = '\0';
    for (i = 0; i < n; i++)
    {
        if (temp[i] == '1')
        {
            for (j = 0; j < k; j++)
            {
                if (temp[i + j] == key[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }
    printf("\nCRC remainder: ");
    for (i = n; i < n + k - 1; i++)
    {
        printf("%c", temp[i]);
    }
    printf("\nTransmitted data: %s", data);
    for (i = n; i < n + k - 1; i++)
    {
        printf("%c", temp[i]);
    }
    printf("\n");
    return 0;
}
