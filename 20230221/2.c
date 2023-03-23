//一组数据内有一个元素仅出现一次，其余元素均出现2次，请快速找出值出现一次的元素

#include<stdio.h>

int lonely_v2(int * arr, int length)
{
    int sum=0;
    /*总体异或*/
    for (int i = 0; i < length; i++)
    {
        sum ^= arr[i];
        
        // printf("%d\n", sum);

    }
    /*找某一个非零位*/
    int flag = 1;
    while((sum & flag )==0){
        flag = flag << 1;
        printf("%d\n", flag);
    }
    /*分组处理*/
    int group1=0,group2=0;
    for (int i = 0; i < length; i++)
    {
        if(arr[i]&flag){
            group1^= arr[i];
        }
        else{
            group2 ^= arr[i];
        }
    }
    printf("一个是%d,另一个是%d", group1, group2);
    return 0;
}

int main(){
    int array[] = {6, 2, 9, 3, 3, 8, 9, 2};
    int length = sizeof(array) / sizeof(array[0]);
    lonely_v2(array, length);
    return 0;
}