#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int nVertex;
    int nEdge;
    int *pMatrix;
} Graph;

Graph *CreateGraph(){
    int nV;
    int nE;
    printf("请输入顶点个数与边的条数;\n");
    scanf("%d%d",&nV,&nE);

    Graph *pGraph = (Graph *)malloc(sizeof(Graph));
    pGraph->nVertex = nV;
    pGraph->nEdge = nE;

    //用一维数组表示二维矩阵
    pGraph->pMatrix = (int *)malloc(sizeof(int)*nV*nV);
    memset(pGraph->pMatrix, 0, sizeof(int)*nV*nV);

    //边
    int a, b;
    int i;
    for(i=0; i<nE; i++){
        printf("请输入第%d条边的两个顶点:\n", i+1);
        scanf("%d%d", &a, &b);
        if(a>=1 && a<=nV && b>=1 && b<=nV && a!=b && pGraph->pMatrix[(a-1)*nV+b-1]==0){
            a = a - 1;
            b = b - 1;
            pGraph->pMatrix[a * nV + b] = 1;
            pGraph->pMatrix[b*nV+a] = 1;
        }
        else{
            i--;
        }
    }
    return pGraph;
}
void MyDFS(Graph *pGraph,int nBegin,int *pVisited)
{
    printf("%d ", nBegin);
    pVisited[nBegin-1] = 1;
    int i;
    for(i=0; i<pGraph->nVertex; i++){
        if(pGraph->pMatrix[ (nBegin-1) * pGraph->nVertex + i]==1 && pVisited[i]==0){
            MyDFS(pGraph, i+1, pVisited);
        }
    }
}

void DFS(Graph *pGraph , int nBegin)
{
    if(pGraph==NULL || nBegin<1 || nBegin > pGraph->nVertex){
        return;
    }
    int *pVisited = (int *)malloc(sizeof(int)*pGraph->nVertex);
    memset(pVisited, 0, sizeof(int)*pGraph->nVertex);
    //遍历
    MyDFS(pGraph, nBegin, pVisited);
}


int main()
{
    Graph *pGraph = CreateGraph();
    int i;
    for(i=0; i<pGraph->nVertex; i++){
        int j;
        for(j=0; j<pGraph->nVertex; j++){
            printf("%d ", pGraph->pMatrix[i*pGraph->nVertex+j]);
        }
        printf("\n");
    }

    DFS(pGraph, 2);   //2 1 4 3 5
    printf("\n");
    return 0;
}