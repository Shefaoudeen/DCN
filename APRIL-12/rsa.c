//21EC1023
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define SIZE 100

int gcd(int n1,int n2) {
	if(n2!=0)
	return gcd(n2,n1%n2);
	else
	return n1;
}

int main(){
	char msg[SIZE];
	int p,q,e,phi,n,c[30],m[30],d;
	printf("\nEnter the message:");
	scanf("%s",msg);
	printf("\nEnter the first prime number:");
	scanf("%d",&p);
	printf("\nEnter the second prime number:");
	scanf("%d",&q);
	n=p*q;
	phi=(p-1)*(q-1);
	for(e=2;(e<phi)&&(gcd(e,phi)!=1);++e);
	for(int i=2;i<phi;++i)
	if((i*e)%phi==1){	
			d=i;
			break;
		}
	printf("\nPublic key:%d",d);
	printf("\nPrivate key:%d",e);
	
	printf("\nEncrypted message:");
	for(int i=0;i<strlen(msg);i++){
		c[i]=fmod(pow((double)msg[i]-'A'+1,e),n);
		printf("%c",(int)(c[i]+'A'-1));
	}
	
	printf("\nDecrypted message:");
	for(int i=0;i<strlen(msg);i++){
		m[i]=fmod(pow((double)c[i],d),n);
		printf("%c",(m[i]+'A'-1));
	}
	printf("\n");
	return 0;
}
		
	
	
	
