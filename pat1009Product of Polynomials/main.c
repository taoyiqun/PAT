#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int expon;
    double coef;
    struct node*   next;
}node;
typedef struct {
    int k;
    node* frist;
}Nodes;
void    attach(double   c,int e,node    *rear){

}
int main() {
    Nodes   nodes[3];
    node*   p;
    node*   rear;
    for (int j = 0; j < 2; ++j) {
        scanf("%d",&nodes[j].k);
        rear=NULL;
        for (int i = 0; i < nodes[j].k; ++i) {
            p=(node*)malloc(sizeof(node));
            scanf("%d%lf",&p->expon,&p->coef);
            p->next=rear;
            rear=p;
        }
        nodes[j].frist=rear;
    }
    node    *t1=nodes[0].frist;
    node    *t2=nodes[1].frist;
    node    *t3=NULL;
    rear=NULL;
    nodes[2].k=0;
    while (t1){
        t2=nodes[1].frist;
        while (t2){
            t3=(node    *)malloc(sizeof(node));
            t3->expon=t1->expon+t2->expon;
            t3->coef=t1->coef*t2->coef;
            t3->next=rear;
            nodes[2].k++;
            rear=t3;
            t2=t2->next;
        }
        t1=t1->next;
    }
    nodes[2].frist=rear;
    for (int l = 0; l < nodes[2].k; ++l) {
        
        for (int i = l; i < nodes[2].k; ++i) {
            if()
        }
    }
    printf("%d",nodes[2].k);
    rear=nodes[2].frist;
    for (int k = 0; k < nodes[2].k; ++k) {
        printf(" %d %.1lf",rear->expon,rear->coef);
        rear=rear->next;
    }


    return 0;
}