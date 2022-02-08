#include <cstdio>
#include <cstdlib>
bool between(int a,int b,int c){
    if(a>c){
        int t=c;c=a;a=t;
    }
    if(a<=b&&b<=c) return true;
    return false;
}
int main()
{
    int dir=0,n,i,j,li=1,lj=1,ni=1,nj=1,x_start=1,y_start=1,count=1,y_end,x_end;
    scanf("%d %d %d",&n,&i,&j);
    y_end=x_end=n;
    while(1){
        count+=abs(li-ni)+abs(lj-nj);
        li=ni;
        lj=nj;
        if(dir==0){
            nj=x_end;
            y_start++;
        }if(dir==1){
            ni=y_end;
            x_end--;
        }if(dir==2){
            nj=x_start;
            y_end--;
        }if(dir==3){
            ni=y_start;
            x_start++;
        }dir=(dir+1)%4;
        if(lj==j&&between(ni,i,li)){
            count+=abs(i-li);break;
        }if(li==i&&between(nj,j,lj)){
            count+=abs(j-lj);break;
        }
        printf("%d %d %d %d %d %d\n",li,lj,ni,nj,count,dir);
    }
    printf("%d",count);
    return 0;
}