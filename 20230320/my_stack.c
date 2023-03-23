#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    int count;
    struct node *next;
    struct node *top;
} Data;

void Push(Data **s, int nNum){
    if ((*s)== NULL) {
        printf("栈不存在\n");
        return;
    }

    Data *pTemp =(Data *) malloc(sizeof(Data));
    pTemp->value = nNum;
    pTemp->next = (*s)->top;
    (*s)->top = pTemp;
    (*s)->count += 1;
}


void Pop(Data **s){
    if((*s)->top==NULL)
        return;
    Data *pDel = (*s)->top;
    int nNum = pDel->value;
    (*s)->top = (*s)->top->next;
    free(pDel);
    pDel = NULL;
    (*s)->count -= 1;
    printf("出栈%d\n", nNum);
}

void Init(Data **s){
    (*s)->count = 0;
    (*s)->top = NULL;
}
int GetCount(Data *s){
    return (s)->count;
}

void Clear(Data **s){
    while((*s)->top){
        Pop(s);
    }
    return;
}
int Gettop(Data *s){
    return (s)->top->value;
}

void Destroy(Data **s){
    Clear(s);
    free(*s);
    *s = NULL;
}

int main(){
    Data *s1 = (Data *)malloc(sizeof(Data));
    Init(&s1);
    Push(&s1, 1);
    printf("%d个栈元素\n", GetCount(s1));
    Push(&s1, 2);
    printf("%d个栈元素\n", GetCount(s1));
    Pop(&s1);
    printf("%d个栈元素\n", GetCount(s1));
    Pop(&s1);
    printf("%d个栈元素\n", GetCount(s1));
    //---------------
    Push(&s1, 100);
    Push(&s1, 99);
    printf("栈顶元素%d\n", Gettop(s1));
    Clear(&s1);
    if(s1==NULL)
        printf("已销毁s1\n");
    
    Destroy(&s1);
    Push(&s1, 88);
    if(s1==NULL)
        printf("已销毁s1\n");
    return 0;
}