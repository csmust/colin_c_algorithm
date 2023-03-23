#include<stdio.h>

int main(){
    int arr[] ={1,2,3,4,5};
    printf("0x%08x", *((int *) ((int)&arr + 1)) );
    return 0;
}