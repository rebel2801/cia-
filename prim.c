#include <stdlib.h>
#include <stdio.h>
void prim(int n,int arr[][n]){
    int parent[n],visit[n],weight[n];
    for(int i=0;i<n;i++) {weight[i]=999999;visit[i]=0;}
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n;i++){
        int min=999999,vert;
        for(int j=0;j<n;j++){
            if(visit[j]==0 && weight[j]<min){
                min=weight[j];
                vert=j;
            }
        }
        visit[vert]=1;
        for(int j=0;j<n;j++){
            if(arr[vert][j]!=0 && arr[vert][j]<weight[j]){
                parent[j]=vert;
                weight[j]=arr[vert][j];
            }
        }
    }
    printf("node-prev weight\n");
    for(int i=0;i<n;i++){
        printf("%d - %d \t  %d\n",i,parent[i],weight[i]);
    }
}

int main(){
    int n=6;
    int arr[6][6]={ { 0,0,2,0,0,0 },
                    { 1,0,0,0,0,0 },
                    { 0,-2,0,0,0,0 },
                    { -4,0,-1,0,0,0 },
                    { 0,0,0,1,0,0},
                    {10,0,0,0,8,0} };
    prim(n,arr);
    return 0;
}
