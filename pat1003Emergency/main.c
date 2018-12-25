#include <stdio.h>
#include <string.h>

#define MAX 510
#define MAX_LENGTH 999999
int weight[MAX];
int road[MAX][MAX];
int isvisted[MAX];
int cnt;
int maxweight;
int minlength;
int citynum;
void DFS(int    start, int end, int c_weight, int c_length){
    isvisted[start]=1;
    if(start==end){
        if(c_length<minlength){
            cnt=1;
            minlength=c_length;
            maxweight=c_weight;
        } else if(c_length==minlength){
            cnt++;
            if(c_weight>maxweight){
                maxweight=c_weight;
            }
        }
        return;
    }
    if(c_length>minlength){
        return;
    }
    for (int i = 0; i < citynum; ++i) {
        if(isvisted[i]==0&&road[start][i]!=MAX_LENGTH){
            DFS(i,end,c_weight+weight[i],c_length+road[start][i]);
            isvisted[i]=0;

        }
    }

}
int main(){
    int N,M,c1,c2;
    int start,end,length;
    scanf("%d%d%d%d",&N,&M,&c1,&c2);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&weight[i]);
    }
    citynum=N;
    memset(isvisted,0, sizeof(isvisted));
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N ; ++i) {
            road[k][i]=MAX_LENGTH;
        }
    }
    for (int j = 0; j < M; ++j) {
        scanf("%d%d%d",&start,&end,&length);
        road[start][end]=road[end][start]=length;
    }
    cnt=0;
    minlength=MAX_LENGTH;
    maxweight=0;
    DFS(c1,c2,weight[c1],0);
    printf("%d %d",cnt,maxweight);
    return 0;
}