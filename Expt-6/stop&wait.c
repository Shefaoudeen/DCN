#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
int main() { 
int i,j,no,x,x1= 10,x2; i=j=1; 
printf("\nEnter the no of frames : "); 
scanf("%d",&no); 
printf("Number of frames : %d\n",no); 
srand(time(NULL)); 
while(i<=no)  { 
  		printf("\nSending frame : %d",i); 
 		 x = rand()%10; 
  		while(!(x%2)) { 
   			printf("\nACK for frame %d not received",j); 
  			 printf("\nRetransmitting frame %d",i); 
   			x=rand()%10; 
 		 } 
 		 printf("\nAcknowledgment for frame : %d",j); 
 		 i++;
     j++; 
 	} 
  printf("\nEnd of stop and wait protocol\n\n"); 
  return 0; 
}
