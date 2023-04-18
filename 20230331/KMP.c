#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int * GetNext(const char *match){
    int len = strlen(match);   //strlen自动判断\0
    //申请空间
    int *Next = NULL;
    Next = (int *)malloc(sizeof(int) * len);
    int i = 1;

    int j = i - 1;
    while (i < len)
    {
        //匹配
        if(match[i] == match[Next[j]])
        {
            Next[i] = Next[j] + 1;
            i++;
            j = i - 1;
        }
        else if(Next[j] == 0)
        {
            Next[i] - 0;
            i++;
            j = i - 1;
        }
        else{
            //确定新的匹配位置
            j = Next[j] - 1;
        }
    }
    return Next;
}

int kmp(const char src[],const char match[]){
    //未对字符串进行修改，传入const指针
    if(src==NULL||match==NULL)
        return -1;
    //获得Next数组
    int *Next = NULL;
    Next = GetNext(match);

    //匹配
    int i = 0;
    int j = 0;
    while (i < strlen(src) && j < strlen(match))

    {
        //相等
        if(src[i]==match[j]){
            i++;
            j++;
        }
        else{
            //匹配串已经回到了头的位置
            if (j == 0)
            {
                i++;
            }
            else{
                //匹配串j的位置跳转
                j = Next[j - 1];
            }
        }
    }
    //检测
    if(j==strlen(match))
    {
        //匹配串走完了,找到源串中的匹配串起始位置
        return i - j;
    }
    else{
        return -1;
    }
}

int main(){
    char source[] = "abcabceabcabcabcabcdabcabcfabcabc";
    char p[] = "abcabcdabcabcf";
    // int slen = strlen(source);
    // int plen = strlen(pp);
    int res=kmp(source, p);
    printf("%d\n", res);
}