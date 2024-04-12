#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int n,storage=0,output,bucketSize,inputSize,interval;

void leaking(int packetsize){
	if ((storage-output)>0){
		printf("Transmitted packed size : %d\n",output);
		storage -= output;
	}	else{
		printf("Transmitted packed size : %d\n",storage);
		storage = 0;
	}
}

int main(){

	
	printf("Enter the no. of data packets : ");
	scanf("%d",&n);
	
	printf("\nEnter the Bucket size : ");
	scanf("%d",&bucketSize);
	
	printf("\nEnter the Output flow size : ");
	scanf("%d",&output);
	
	printf("\nEnter the time interval in sec: ");
	scanf("%d",&interval);
	
	for(int i=0; i<n; i++){
		srand(time(NULL));
		int received = 1;
		
		if(received!=0){
			srand(time(NULL));
			int randomPacket = rand()%10+1;
			if(randomPacket+storage<=bucketSize){
				storage += randomPacket;
				printf("\nBuffer contain %d bytes\n\n",storage);
				for(int j=0;j<1;j++){
					leaking(randomPacket);
				}
				printf("\nRemaing storage: %d",storage);
			}	else {
				printf("Overflow condition... packet not received! with size %d \n",randomPacket);
			}
		}	else {
			printf("Packets lost!!\n");
		}
	}

	return 0;
}

/*
Enter the no. of data packets : 10

Enter the Bucket size : 25

Enter the Output flow size : 5

Enter the time interval in sec: 2

Buffer contain 2 bytes

Transmitted packed size : 2

Remaing storage: 2
Buffer contain 4 bytes

Transmitted packed size : 4

Remaing storage: 4
Buffer contain 6 bytes

Transmitted packed size : 5

Remaing storage: 1
Buffer contain 3 bytes

Transmitted packed size : 3

Remaing storage: 3
Buffer contain 5 bytes

Transmitted packed size : 5

Remaing storage: 5
Buffer contain 7 bytes

Transmitted packed size : 5

Remaing storage: 2
Buffer contain 4 bytes

Transmitted packed size : 4

Remaing storage: 4
Buffer contain 6 bytes

Transmitted packed size : 5

Remaing storage: 1
Buffer contain 3 bytes

Transmitted packed size : 3

Remaing storage: 3
Buffer contain 5 bytes

Transmitted packed size : 5
*/
