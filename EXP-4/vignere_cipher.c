#include <stdio.h>
#include <string.h>

int main(){
	char msg[100],key[100];
	int i,j;
	printf("Enter the message : ");
	scanf("%s",msg);
	printf("Enter the key : ");
	scanf("%s",key);
	
	int msgLen = strlen(msg), keyLen = strlen(key);
	char newkey[msgLen], encryptmsg[msgLen], decryptmsg[msgLen];
	
	for(i=0,j=0;i<msgLen;++i,++j){
		if(j==keyLen)
			j=0;
		newkey[i] = key[j];
	}
	
	newkey[i] = '\0';
	
	for(i=0;i<msgLen;i++)
		encryptmsg[i] = ((msg[i]+newkey[i])%26)+'A';
	encryptmsg[i] = '\0';
	
	for(i=0;i<msgLen;i++)
		decryptmsg[i] = ((encryptmsg[i]-newkey[i]+26)%26)+'A';
	decryptmsg[i] = '\0';

	printf("Orginial Message \t: %s", msg);
	printf("\n key \t: %s", key);
	printf("\nEncrypted Message : %s", encryptmsg);
	printf("\nDecrypted Message : %s\n", decryptmsg);
	
	return 0;
}
