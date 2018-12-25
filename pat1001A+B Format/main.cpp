#include <iostream>
using namespace std;
int main() {
    int a,b;
    char num[20];
    cin>>a;
    cin>>b;
    a=a+b;
    if(a<0){
        num[0]='-';
        a=-a;
    } else{
        if(a>0){
            num[0]='+';
        } else{
            cout<<'0';
        }

    }
    int i=0;
    while(a!=0){
        num[++i]='0'+a%10;
        a=a/10;
    }
    num[++i]='\0';
    if(num[0]=='-'){
        cout<<num[0];
    }
    int j=(i-1)/3;
    int m=(i-1)%3;
    int flag=m;
    for(;m>0;m--){
        cout<<num[--i];
    }
    if(flag>0&&j>0){
        cout<<',';
    }
    for(;j>0;j--){
        for(int k=0;k<3;k++){
            cout<<num[--i];
        }
        if(i>1){
            cout<<',';
        }
    }
    return 0;

}