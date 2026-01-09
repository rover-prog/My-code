#include <stdio.h>
#include <math.h>
int LengthOfNumber(int a);

int CheckArmstrong(int a);
int main()
{
    int n, p;
    printf("Enter the exit limit: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        p = CheckArmstrong(i);
        if (p == 1)
        {
            printf("%i\n",i);
        }
        
    }

    return 0;
}
int LengthOfNumber(int a)
{
    int i = 0;
    do
    {
        a =a / 10;
        i++;
    } while (a != 0);
    return i;
}
int CheckArmstrong(int a)
{
    int i = LengthOfNumber(a), sum = 0, a1 = a, a2;
    for (int j = 0; j < i; j++)
    {
        a2 = a1 % 10;
        a1 = a1 / 10;
        sum += (int)round(pow(a2, i));
    }
    if (sum == a)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}