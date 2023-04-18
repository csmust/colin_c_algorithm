//约瑟夫环问题
/*n个人围成一圈，编号1n，给一个数字k，从1开始数数，数到第K个出圈，从第k+1个位置重新数，数到第k个出圈.
直到圈内只剩一个人停止，最后剩的人编号是几?*/


#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    int cnt = 0;
    // 入队
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++)
    {
        q.push(arr[i]);
    }
    //计数，不满足条件的重新排队，满足的出队
    while(q.size()!=1){
        if(cnt==k){
            q.pop();
            cnt = 0;
        }
        q.push(q.front());
        q.pop();
        cnt++;
    }
    cout << q.front() << endl;
    return 0;
}