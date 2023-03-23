#include <stdio.h>

unsigned int FB(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int res = 0;
    res = FB(n - 1) + FB(n - 2);
    return res;
}

unsigned int FB_xunhuan(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int arr[3] = {1, 1, 2};

    for (int i = 3; i <= n; i++){

        arr[2] = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = arr[2];
    }
    return arr[2];
}



int main()
{
    printf("f(30)=%u\n", FB(30));
    printf("f(30)=%u\n", FB_xunhuan(30));
    return 0;
}