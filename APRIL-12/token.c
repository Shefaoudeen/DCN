#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int packets,storage,output_queue,inputSize,token,arrived=0;
	srand(time(NULL));
	printf("\nEnter the initial no. of tokens : ");
	scanf("%d",&token);
	
	for(int i=0;i<10;i++){
		if(token<30)
			++token;
		else
			printf("\nMaximum token size is reached \n");
		
		printf("\nToken size : %d",token);
		arrived = rand()%2;
		
		if(1){
			inputSize = rand()%10+1;
			printf("\nSize of incoming packet : %d\n",inputSize);
			if(inputSize <= token){
				printf("\nPacket sent");
				token -= inputSize;
			}	else {
				printf("\nPacket is discarded\n");
			}
		}
	}
	return 0;
}
