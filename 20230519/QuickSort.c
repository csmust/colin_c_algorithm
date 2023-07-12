#include<stdio.h>
#include<stdlib.h>



int Sort(int arr[],int nbegin,int nend){
    int temp = arr[nbegin];
    
    while(nbegin < nend)
    {
        //从右向左找比标准值小的
        while(nbegin < nend)
        {
            if(arr[nend] < temp)
            {
                //放在左侧坑
                arr[nbegin] = arr[nend];
                nbegin++;   // 坑向右一位
                break;
            }
            nend--;
        }
        //从左向右找比标准值大的
        while(nbegin < nend)
        {
            if(arr[nbegin] > temp)
            {
                //放在右侧坑
                arr[nend] = arr[nbegin];
                nend--;
                break;
            }
            nbegin++;
        }
    }

    //标准值放入
    arr[nbegin] = temp;
    return nbegin;
}
int Sort_v2(int arr[],int nbegin,int nend){
    //以最后一个为标准值

    int p = nbegin - 1;

    //begin后移
    while (nbegin<nend)
    {
        if (arr[nbegin]<arr[nend]){
            p++;
            if(p!=nbegin){
                //同空间不必交换 ，若强行交换会变成零；使用中间变量的话则不会清零，但是没必要
                arr[p] = arr[p]^arr[nbegin];
                arr[nbegin] = arr[p] ^ arr[nbegin];
                arr[p] = arr[p] ^ arr[nbegin];
            }
        }
        nbegin++;
    }

    //标准值交换
    if(++p!=nend){
        arr[p] = arr[p]^arr[nend];
        arr[nend] = arr[p] ^ arr[nend];
        arr[p] = arr[p] ^ arr[nend];
    }
    return p;
}

void QuickSort(int arr[],int nbegin,int nend)
{
    if(arr==NULL||nbegin>=nend)
        return;

    int nStand;
    nStand = Sort_v2(arr, nbegin, nend);

    QuickSort(arr, nbegin, nStand - 1);
    QuickSort(arr, nStand + 1, nend);
}



void Print(int arr[],int nlength){
    if (arr==NULL||nlength<=0)
    {
        return;
    }
    int i;
    for (i = 0; i < nlength;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = { 3, 1, 5, 7, 2, 4, 9, 6 ,3,5,7,2,4,9,9,9 };
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    QuickSort(arr, 0, nlength - 1);
    Print(arr, nlength);
    return 0;
}