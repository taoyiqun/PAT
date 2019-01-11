#include <stdio.h>
char xuanze(double pow[], double *sum){
    char res;
    char daan[3]={'W','T','L'};
    double current=pow[0];
    int cus=0;
    for (int i = 0; i < 3; ++i) {
        if(pow[i]>current){
            current=pow[i];
            cus=i;
        }
    }
    *sum=*sum*pow[cus];
    res=daan[cus];
    return res;
}
int main() {
    double pow[4];
    char ze[3];
    double sum=1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%lf",&pow[j]);
        }
        ze[i]=xuanze(pow,&sum);
    }
    printf("%c %c %c %.2f",ze[0],ze[1],ze[2],(sum*0.65-1)*2);
    return 0;
}