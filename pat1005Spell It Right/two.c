//
// Created by hdutyq on 2018/12/26.
//

#include <stdio.h>
#include <string.h>
char num[110];
char *a[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main() {
    gets(num);
    int len=strlen(num);
    int res=0;
    for (int i = 0; i < len; ++i) {
        res=res+num[i]-'0';
    }
    len=sprintf(num,"%d",res);
    for (int j = 0; j < len-1; ++j) {
        printf("%s",a[num[j]-'0']);
        printf(" ");
    }
    printf("%s",a[num[len-1]-'0']);

    return 0;
}