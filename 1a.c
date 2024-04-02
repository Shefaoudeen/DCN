#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char data[20],rdata[20];
int dlen;
int check(char data[20]);

int main()
{
 int i,count=0,tf,rf,t;
 printf("Enter total no of bits:");
 scanf("%d",&dlen);
 printf("Enter data:");
 scanf("%s",data);
 tf=check(data);
 puts("\n Recieved data:\n");
 strcpy(rdata,data);
 
 for(i=0;i<dlen;i++)
  printf("%c",rdata[i]);
  srand(time(NULL));
  t=rand()%2;
  printf("\nrand=%d\n",t);
  rdata[0]=(t>0.5)?'1':'0';
  printf("Recieved data after replacing:");
 
 for(i=0;i<dlen;i++)
  printf("%c",rdata[i]);
  rf=check(rdata);
 
 if(tf==rf)
  printf("\n Success No errors");
 else
  printf("\n Message is erroneous");
 return 0;
}

int check(char data[20])
{
 int i,epar,opar,count=0;
 for(i=0;i<dlen;i++)
{
 if (data[i]=='1')
 count++;
}
 printf("\ncount:%d",count);
 if(count%2)
{
 epar=1;opar=0;
}
 else
{
 epar =0;
 opar=1;
}
 printf("Even parity:%d,Odd parity:%d",epar,opar);
 return opar;
}
