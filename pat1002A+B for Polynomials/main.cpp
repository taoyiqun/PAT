#include <iostream>
#include <iomanip>

using namespace std;
typedef struct {
    int per;
    double num;
}node;
int cmp(int a,int b){
    if(a>b){
        return 1;
    }
    if(a==b){
        return 0;
    }
    if(a<b){
        return -1;
    }
}
int main() {
    node k1[11],k2[11];
    node k3[25];
    int num1,num2;
    cin>>num1;
    for(int i=0;i<num1;i++){
        cin>>k1[i].per;
        cin>>k1[i].num;
    }
    cin>>num2;
    for(int i=0;i<num2;i++){
        cin>>k2[i].per;
        cin>>k2[i].num;
    }
    int count=0;
    int m=0,n=0;
    int k=-1;
    while (m<num1&&n<num2){
        switch (cmp(k1[m].per,k2[n].per)){
            case 1:{
                k3[++k].per=k1[m].per;
                k3[k].num=k1[m].num;
                m++;
                count++;
                break;
            }
            case 0:{
                double sum=k1[m].num+k2[n].num;
                if(sum!=0.0){
                    k3[++k].per=k1[m].per;
                    k3[k].num=sum;
                    m++;
                    n++;
                    count++;
                    break;
                } else{
                    m++;
                    n++;
                    break;
                }
            }
            case -1:{
                k3[++k].per=k2[n].per;
                k3[k].num=k2[n].num;
                n++;
                count++;
                break;
            }
        }
    }
    while (m<num1){
        k3[++k].per=k1[m].per;
        k3[k].num=k1[m].num;
        m++;
        count++;
    }
    while (n<num2){
        k3[++k].per=k2[n].per;
        k3[k].num=k2[n].num;
        n++;
        count++;
    }
    cout<<count;
    for(int i=0;i<count;i++){
        cout<<' ';
        cout<<showpoint<<fixed<<setprecision(1);
        cout<<k3[i].per;
        cout<<' ';
        cout<<k3[i].num;
    }
    return 0;
}