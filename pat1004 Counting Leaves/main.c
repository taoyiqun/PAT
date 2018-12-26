//父亲表示法
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int flag;
    int level;
    int father;
}Node;
Node node[110];
int main() {
    int M,N;
    scanf("%d%d",&N,&M);
    int nownode,nodenum,erzi;
    for (int l = 0; l < 110; ++l) {
        node[l].level=0;
        node[l].father=0;
        node[l].flag=0;
    }
    node[1].level=1;
    for (int i = 0; i < M; ++i) {
        scanf("%2d%d",&nownode,&nodenum);
        for (int j = 0; j < nodenum; ++j) {
            scanf(" %2d",&erzi);
            node[nownode].flag=1;
            node[erzi].father=nownode;
        }
    }
    int maxlev=1;
    int res[110];
    memset(res,0, sizeof(res));
    for (int k = 1; k <=N; ++k) {
        for (int i = 1; i <= N; ++i) {
            if(node[i].father==k){
                node[i].level=node[k].level+1;
                if(node[i].level>maxlev){
                    maxlev=node[i].level;
                }
            }
        }
        if(node[k].flag==0){
            res[node[k].level]++;
        }
    }
    for (int m = 1; m <maxlev; ++m) {
        printf("%d ",res[m]);
    }
    printf("%d\n",res[maxlev]);
    return 0;

}