#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2d_memcpy 451

int main() 
{
float mymatrix[3][3] = {{1.1,3.3,7.8},{3.5,5.4,2.1},{2.4,5.3,6.6}};
float copied[3][3] ;
int s = syscall(SYS_kernel_2d_memcpy,copied,mymatrix,3,3);

for (int i =0;i<3;i++)
{
for (int j=0;j<3;j++)
{
printf("%f ",copied[i][j]);

}
printf("\n");

}

printf("System call error ");



return 0;

}
