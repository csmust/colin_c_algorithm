#include<stdio.h>

typedef struct Stack
{
    int value;
    struct Stack * next;
    Stack() : value(NULL),next(nullptr){}
    Stack(int x) : value(x),next(nullptr){}
}Stack;

Stack * creat_stack(int arr[],int len)
{
    //头增头删
    if (arr==nullptr)
        return nullptr;
    // Stack *sp = new Stack;
    Stack *top = nullptr;
    for (int i; i < len; i++){
        Stack *sp = new Stack(arr[i]);
        sp->next = top;
        top = sp;
    }
}

void Print_stack()
{

}

int stack_pop(){
    
}

int main(){

    int arr[] = { 1, 2, 3, 4, 5 };
    int lenth = sizeof(arr) / sizeof(arr[0]);
    Stack *stack1 = creat_stack(arr, lenth);

    return 0;

}
