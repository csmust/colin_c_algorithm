#include<stdio.h>

int binaryChop_xunhuan(int arr[],int len,int ans){
    if(arr==NULL || len <=0)
        return -1;
    int start = 0;
    int end = len - 1;
    int mid;
    while(end>=start){
        mid = start + (end - start) / 2; //取整数向下
        if(arr[mid]==ans){
            printf("id1=%d\n", mid);
            return mid;
        }
        else if(arr[mid]>ans){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    printf("未找到\n");
    return -1;
}

int binaryChop_diGui(int arr[],int low,int high,int target){
    if(arr==NULL || low > high)
        return -1;

    int mid;
    mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;

    else if (arr[mid] > target)
    {
        return binaryChop_diGui(arr, low, mid - 1, target); 
    }
    else
        return binaryChop_diGui(arr, mid + 1, high, target);
}

int main(){
    int arr[] = {2, 6, 8, 9, 12, 14, 15, 19, 21, 28, 30};
    int target = 30;
    int id1 = binaryChop_xunhuan(arr, sizeof(arr) / sizeof(arr[0]), target);
    int id2 = binaryChop_diGui(arr, 0,sizeof(arr) / sizeof(arr[0])-1, target);
    printf("id2=%d", id2);
}