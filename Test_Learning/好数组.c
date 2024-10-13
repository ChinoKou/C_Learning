#include <stdio.h>
int main(){
    int n,k,i,p,k1=0,j,k2;
    scanf("%d %d",&n,&k);
    int all[n];
    for(i=0;i<n;i++){
        scanf("%d ",&all[i]);
    }
    for(i=0;i<=n-k;i++){
        p=0,k2=0;
        for(j=0;j<k/2;j++){
            if(all[i+p]!=all[i+k-1-p]){
                k2++;
            }
            p++;
        }
        if(k2==1){
            k1++;
        }
    }
    printf("%d",k1);
    return 0;
}