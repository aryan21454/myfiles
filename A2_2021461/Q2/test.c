#include<stdio.h>
#include<stdlib.h>
#define kernel_2d_memcpy 451
int  main(){
    float arr[2][2]={{1,2},{3,4}};
    float brr[2][2];
    int s=syscall(451,brr,arr,2,2);
    if(!s){
        for(int i=0;i<2;++i){
                for(int j=0;j<2;++j){

                    printf("%f",brr[i][j]);
                }
                printf("\n");
        }
    }
    return 0;
}