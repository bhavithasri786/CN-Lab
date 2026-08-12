#include <stdio.h>

int main()
{
    char data[100], destuffed[100];
    int i = 0, j = 0;

    printf("Enter stuffed data: ");
    scanf("%s", data);

    while (data[i] != '\0')
    {
        if (data[i] == '#' && data[i + 1] == '#')
        {
            destuffed[j++] = '#';
            i = i + 2;
        }
        else
        {
            destuffed[j++] = data[i];
            i++;
        }
    }

    destuffed[j] = '\0';

    printf("Destuffed data: %s\n", destuffed);

    return 0;
}
