#include <stdio.h>

int i,key;
char msg[100], encode[100], decode[100];

void getDetails(){
	printf("Enter your message : ");
	scanf("%s",msg);
	printf("Enter the key : ");
	scanf("%d",&key);
	key = key%26;
}

char encryptLetter(char letter,int key, int limit){
	if((letter+key) > limit)
		return (letter+key-26);
	return (letter+key);
}

char decryptLetter(char letter,int key, int limit){
	if((letter-key) < limit)
		return (letter - key + 26);
	return (letter-key);
}

int main(){
	getDetails();
	
	for(i=0;msg[i] != '\0';i++){
		if(msg[i]>=65 && msg[i] <= 90)
			encode[i] = encryptLetter(msg[i],key,90);
		else if(msg[i]>=97 && msg[i] <= 122)
			encode[i] = encryptLetter(msg[i],key,122);
		else
			encode[i] = msg[i];
	}
	
	printf("Encrypted message : %s",encode);
	
	for(i=0;encode[i] != '\0';i++){
		if(encode[i]>=65 && encode[i] <= 90)
			decode[i] = decryptLetter(encode[i],key,65);
		else if(encode[i]>=97 && encode[i] <= 122)
			decode[i] = decryptLetter(encode[i],key,97);
		else
			decode[i] = encode[i];
	}
	
	printf("\nDecrypted message : %s\n", decode);
	return 0;
}
