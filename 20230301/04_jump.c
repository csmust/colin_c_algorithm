#include<stdio.h>

int jump(unsigned int n){
    if (n==1)
        return 1;
    if (n==2)
        return 2;
    unsigned int a, b, c, i;
    a = 1;
    b = 2;
    // c = 3;
    for (i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    printf("%u", jump(9));
}