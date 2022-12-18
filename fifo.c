#define FIFO_NAME “fifo_1" 
int main(void)
 { char s[300]; 
int num, fd; 
mknod(FIFO_NAME, S_IFIFO | 0666, 0); 
printf("waiting for readers...\n");
 fd = open(FIFO_NAME, O_WRONLY); 
printf("got a reader--type some stuff\n"); 
while (gets(s), !feof(stdin)) 
{ 
if ((num = write(fd, s, strlen(s))) == -1) 
 perror("write"); 
else printf("speak: wrote %d bytes\n", num); 
} 
return 0; 
}
