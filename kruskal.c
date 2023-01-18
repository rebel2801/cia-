#include <stdlib.h>
#include <stdio.h>
int cycle(int a,int parent[]){
    while(parent[a]) a=parent[a];
    return a;
}
void kruskal(int n,int arr[][n]){
    int parent[n],itr=1,cost=0;
    while(itr<n){
        int min=99999,a,b,c,d;
        for(int i=0;i<n;i++){
            parent[i]=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]<min){
                    min=arr[i][j];
                    a=c=i;b=d=j;
                }
            }
        }
        c=cycle(c,parent);
        d=cycle(d,parent);
        if(c!=d){
            parent[c]=d;
            printf("%d - %d  %d\n",b,a,min);
            cost+=min;
            itr++;
        }
        arr[a][b]=arr[b][a]=99999;
    }
    printf("total cost:%d\n",cost);
}
int main(){
    int n=6;
    int arr[6][6]={ { 0,0,2,0,0,0 },
                    { 1,0,0,0,0,0 },
                    { 0,-2,0,0,0,0 },
                    { -4,0,-1,0,0,0 },
                    { 0,0,0,1,0,0},
                    {10,0,0,0,8,0} };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0) arr[i][j]=99999;
        }
    }
    kruskal(n,arr);
    return 0;
}
