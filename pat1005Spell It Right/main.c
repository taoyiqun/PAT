//第二个测试样例未过
#include <stdio.h>
#include <string.h>

char    num[110];
void out(int k) {
    switch (k) {
        case 0: {
            printf("zero");
            break;
        }
        case 1: {
            printf("one");
            break;
        }
        case 2: {
            printf("two");
            break;
        }
        case 3: {
            printf("three");
            break;
        }
        case 4: {
            printf("four");
            break;
        }
        case 5: {
            printf("five");
            break;
        }
        case 6: {
            printf("six");
            break;
        }
        case 7: {
            printf("seven");
            break;
        }
        case 8: {
            printf("eight");
            break;
        }
        case 9: {
            printf("nine");
            break;
        }
    }
}
int main() {
    gets(num);
    int len=strlen(num);
    int res=0;
    for (int i = 0; i < len; ++i) {
        res=res+num[i]-'0';
    }
    int temp=res;
    int ff=1;
    while (temp!=0){
        temp=temp/10;
        ff=ff*10;
    }
    ff=ff/10;
    while (ff!=0){
       out(res/ff%10);
       if(ff!=1){
           printf(" ");
       }
       ff=ff/10;
    }
    return 0;
}