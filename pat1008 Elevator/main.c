#include <stdio.h>

int main() {
    int n;
    int order;
    int now=0;
    int time=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&order);
        if(now>order){
            time=time+(now-order)*4+5;
        } else{
            time=time+(order-now)*6+5;
        }
        now=order;
    }
    printf("%d",time);

    return 0;
}