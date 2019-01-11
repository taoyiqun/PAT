#include <stdio.h>
#include <string.h>
//longlong 也会爆栈
int transnum(char n){
    if(n>='0'&&n<='9'){
        return (n-'0');
    } else{
        return (n-'a'+10);
    }
}

int trans(char n[], long long    *num, long long radis){
    int len=strlen(n);
    *num=0;
    for (int i = 0; i < len; ++i) {
        *num=*num*radis+transnum(n[i]);
        if(*num<0){
            return -1;//longlong爆栈
        }
    }
    return 1;
}

int trans2(char n[], long long    *num, long long radis, long long bidui){
    int len=strlen(n);
    *num=0;
    for (int i = 0; i < len; ++i) {
        *num=*num*radis+transnum(n[i]);
        if(*num<0){
            return -1;
        }
        if(bidui<*num){
            return 0; //剪枝
        }
    }
    return 0;
}
void mybsearch(long long low,long long high,long long bidui, char n[]){
    long long num;
    long long radix;
    int  flag;
    while (low<=high){
        radix=(low+high)/2;
        num=0;
        flag=trans2(n,&num,radix,bidui);
        if(flag==-1){
            num=0;
            high=radix-1;//爆栈 太大了
        }else if(num>bidui){
            num=0;
            high=radix-1;
        }else if(bidui==num){
            printf("%lld",radix);
            return;
        }else if(num<bidui){
            num=0;
            low=radix+1;

        }
    }
    printf("Impossible");

}
void panduan(long long bidui,char n[]){
    int len=strlen(n);
    long long low,high;
    low=transnum(n[0]);
    for (int i = 0; i < len; ++i) {
        if(transnum(n[i])>low){
            low=transnum(n[i]);
        }
    }
    low++;
    high=low>bidui?low:bidui;
    //二分查找剪枝
    mybsearch( low, high, bidui,n);

}
int main() {
    char n1[11],n2[11],n3[11];
    int tag;
    long long radis;
    long long num;
    scanf("%s %s %d %lld",n1,n2,&tag,&radis);
    if(tag==2){
       strcpy(n3,n2);
       strcpy(n2,n1);
       strcpy(n1,n3);
    }
    trans(n1,&num,radis);
    panduan(num,n2);
    return 0;
}