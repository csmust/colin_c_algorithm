#include<stdio.h>
/*位运算实现加法*/
int add(int a, int b){
    int jinwei = -1;
    while((jinwei= a & b) != 0){
        b = a ^ b;    // 不需要进位 异或 求得
        a = jinwei << 1;   // 进位
    }
    return a ^ b;
}

int main(){
    printf("%d\n", add(-3, -1));
    printf("%d\n", add(3, 12));
    printf("%d\n", add(100, 12));
    return 0;
}