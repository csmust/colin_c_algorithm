//一个数组内有n个元素，每个元素值范围在0~n-1之间，判断数据元素是否有重复，如果有，报错
#include<stdio.h>

int chachongshuzu(int  * arr,int n)
{
    int i = 0;
    printf("len = %d\n", n);
    int temp=-1;
    while(i < n)
    {
        if(arr[i] == i){
            i++;
            // printf("%d\n", arr[i]);
        }
        else{
            temp = arr[i];
            if(arr[temp]==temp){
                printf("有重复\n");
                return -1;
            }else{
                arr[i] = arr[temp];
                arr[temp] = temp;
            }
        }
    }
    printf("没有重复\n");
    return 0;
}
int main(){
    int arr[] = {1, 3,4, 0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    chachongshuzu(arr,n);   //数组长度必须从外面传入，函数内部计算不行
    return 0;
}