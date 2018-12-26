#include <stdio.h>
#include <string.h>
int main() {
   char idin[20],idout[20],id[20];
   int N;
   int inh,inm,ins;
   int outh,outm,outs;
   int intime;
   int outtime;
   int minin=999999999;
   int maxout=-1;
   scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %2d:%2d:%2d %2d:%2d:%2d",id,&inh,&inm,&ins,&outh,&outm,&outs);
        intime=3600*inh+60*inm+ins;
        outtime=3600*outh+60*outm+outs;
        if(intime<minin){
            strcpy(idin,id);
            minin=intime;
        }
        if(outtime>maxout){
            strcpy(idout,id);
            maxout=outtime;
        }


    }
    printf("%s %s",idin,idout);
    return 0;
}