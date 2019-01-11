#include <stdio.h>
#include <malloc.h>

int main() {
    int n1;
    scanf("%d",&n1);
    double f1[1001]={0.0};
    double f3[2001]={0.0};
    int expon;
    int n2;
    double coef;
    int count=0;
    for (int i = 0; i < n1; ++i) {
        scanf("%d %lf",&expon,&coef);
        f1[expon]=coef;
    }
    scanf("%d",&n2);
    for (int j = 0; j < n2; ++j) {
        scanf("%d %lf",&expon,&coef);
        for (int i = 0; i < 1001; ++i) {
            f3[expon+i]=f3[expon+i]+f1[i]*coef;
        }
    }
    for (int k = 0; k < 2001; ++k) {
        if(f3[k]!=0.0){
            count++;
        }
    }
    printf("%d",count);
    for (int l = 2000; count>0 ; --l) {
        if(f3[l]!=0){
            printf(" %d %.1f",l,f3[l]);
            count--;
        }
    }
    return 0;


}