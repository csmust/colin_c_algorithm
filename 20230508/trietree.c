//字典树，字符串的搜索问题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//宏定义
#define MAX 26

typedef struct node
{
    int nCount;
    char *str; //nCount>0时，节点存储单词
    struct node *next[26];
} TrieTree;

TrieTree* GetNode(){
    TrieTree *p = (TrieTree *)malloc(sizeof(TrieTree));
    memset(p, 0, sizeof(TrieTree));
    return p;
}

void AddWord(TrieTree *pTree, char *str){
    int i = 0;
    int len = strlen(str);
    while(i<len){
        //字符是否有对应节点
        if(pTree->next[str[i]-'a'] == NULL){
            //创建
            pTree->next[str[i]-'a'] = GetNode();
        }
        //指向下一个节点
        pTree = pTree->next[str[i]-'a'];
        i++;
    }
    //pTree到达末尾
    pTree->nCount++;
    pTree->str = str; //首地址也可以
}

TrieTree *CreateTree(char *strarr[], int n){
    if(strarr == NULL || n<=0){
        return NULL;
    }
    TrieTree *pRoot = GetNode();

    //添加单词
    int i = 0;
    for(i=0; i<n; i++){
        AddWord(pRoot, strarr[i]);
    }
    return pRoot;
}

void Preorder(TrieTree *pTree){
    if(pTree == NULL){
        return;
    }
    if(pTree->nCount > 0){
        printf("%s\n", pTree->str);
    }
    int i;
    for(i=0; i<26; i++){
        Preorder(pTree->next[i]);
    }
}

void Search(TrieTree* pTree,char *str){
    int i = 0;
    int len = strlen(str);
    while(i<len){
        //第i个字符是否有对应节点
        if(pTree->next[str[i]-'a'] == NULL){
            printf("No match and no have subword\n");
            return;
        }
        pTree = pTree->next[str[i]-'a'];
        i++;
    }
    //pTree到达末尾
    if(pTree->nCount > 0){
        printf("%s\n", pTree->str);
    }else{
        printf("No match but have subword \n");
    }
}

int main(){
    char *str[] ={"energy" ,"break","grand","continue", "beautiful","play" ,"station", "beach","socket", "ocean" ,"awesome" ,"accept"};
    TrieTree *pTree = CreateTree(str, sizeof(str)/sizeof(str[0]));
    Preorder(pTree);
    printf("Please input a word to search:\n");
    char buf[100];
    scanf("%s", buf);
    Search(pTree, buf);
    return 0;
}

