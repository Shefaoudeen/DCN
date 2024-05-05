#include<stdio.h> 
#include<time.h> 
#include<stdlib.h> 
int main() { 
 	int nf,N,no=0,i=1; 
 	srand(time(NULL)); 
 	printf("\nEnter the no of frames : "); 
 	scanf("%d",&nf); 
 	printf("\nEnter window size : "); 
 	scanf("%d",&N); 
 	while(i<=nf) { 
  		int x=0; 
  		for(int j=i;j<i+N && j<=nf;j++) { 
  			printf("\nSent frame : %d",j); 
  			no++; 
  		} 
  		for(int j=i;j<i+N && j<=nf;j++)  { 
   		 int flag = rand()%2; 
   		 if(!flag) { 
    		  printf("\nACK for frame : %d",j); 
    		  x++; 
   		} else  { 
   		  printf("\nFrame %d not received",j); 
    		  printf("\nRetransmitting window from frame %d",j); 
   		  break; 
   		} 
  	   } 
  	   printf("\n"); 
   i+=x; 
  } 
  	printf("\nTotal no of transmissions : %d\n\n",no); 
  	return 0; 
}
