#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用数组模拟哈希 申请255长度的数组


int *GetNext(const char *match)
{
    // int hash[256];
    int *hash = NULL;
    hash = (int *)malloc(sizeof(int) * 256);
    memset(hash, -1, sizeof(hash));
    int len = strlen(match);
    for (int i = 0; i < len; i++){
        hash[(int)(match[i])] = i;
    }
    return hash;
}
int Sunday(const char *src,const char *match){
    if(src==NULL||match==NULL)
        return -1;
    int i=0,j=0,k=0;
    int *Next = NULL;
    Next = GetNext(match);
    int srclen=strlen(src);
    int matlen = strlen(match);

    while (i < srclen && j < matlen)
    {
        if (src[i] == match[j]){
                i++;
                j++;
        }
        else{
                //源串重新定位：先判断越界与否
                if(k + matlen < srclen){
                    k = k + matlen - Next[src[k + matlen]];  //等长的下一个字符 ，不存在NEXT时， 就是-（-1），也就是跳过下个字符
                    i = k;
                    j = 0;
                }
                else
                    return -1;
        }
    }
    if(j == matlen){
        return k;
    }
    else
        return -1;
}

int main(){
    char src[] = "123456789a";
    char match[] = "789a";
    printf("%d\n", Sunday(src, match));
    return 0;
}