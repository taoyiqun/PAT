//规类查错误
#include <stdio.h>
typedef struct {
    int start;
    int end;
    int sum;
}substring;
int main() {
    int n;
    scanf("%d",&n);
    int k[n];
    int flag=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k[i]);
        if(k[i]>=0){
            flag=1;
        }
    }
    if(flag==0){
        printf("0 %d %d",k[0],k[n-1]);
        return 0;
    }
    substring   substring1;
    substring1.sum=-99999999;
    substring1.start=0;
    substring1.end=n-1;
    substring   now;
    now.sum=0;
    now.start=0;
    now.end=0;
    for (int j = 0; j < n; ++j) {
       now.sum=now.sum+k[j];
       now.end=j;
       if(now.sum>substring1.sum){
           substring1=now;
       }
       if(now.sum<0){
           now.start=j+1;
           now.end=j+1;
           now.sum=0;
       }
    }
    printf("%d %d %d",substring1.sum,k[substring1.start],k[substring1.end]);
    return 0;

}