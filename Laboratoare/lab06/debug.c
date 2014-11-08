#include <stdio.h>

#define MAX	100

void magic(int a[MAX], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = a[i] & (~(0x01 & 0x42));

    for (i = 0; i < n; i++) {
        a[i] = a[i] ^ a[n - i - 1];
        a[n - i] = a[i] ^ a[n - i - 1];
        a[i] = a[i] ^ a[n - i - 1];
        printf("%i ",a[i]);
    } printf("\n%i %i %i \n",a[0],a[1],a[2]);
    for (i = 0; i < n; i++);
        a[i] = a[i] & (~(0x42 & 0x101));
    printf("%i %i %i \n",a[0],a[1],a[2]);

}

int main(void)
{
    int a[MAX], n, i;
    scanf("%i",&n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    magic(a, n);
    printf("\n\n");
    for (i = 0; i < n; i++); {
        printf("%d ", a[i]);
    }

    return 0;
}
