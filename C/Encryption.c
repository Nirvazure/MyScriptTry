#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void data(char key[],int code[])
{
    int i;
    long long temp=1;
    for(i=0;key[i]!=0;i++)
    {
         temp=key[i]*temp;
         if(temp>2000000000)
             temp=temp%1000000;
     }
     for(i=0;i<30;i++)
         code[i]=temp&((int)pow(2,i));
}
int main()
{
    FILE *fp1,*fp2;
    int i;
    char x=0;
    char key[41]={0};
    int code[30]={0};
	printf("-------This program can encrypt the tgt.txt--------\n\n\n");
    if((fp1=fopen("tgt.txt","r"))==NULL)
    {
        printf("No target file found!\nPlease put the tgt.txt in the same path\n");
		system("pause");
        return(0);
    }
    //if((fp2=fopen("out.txt","r+"))==NULL)
		fp2=fopen("encrypted.txt","w+");
	printf("Please input the key\n");
	for(i=0;i<41;i++)
	{
        key[i]=getch();
        if( key[i]=='\n'||key[i]=='\r')
        {
            key[i]=0;
            putchar('\n');
            break;
        }
        putchar('*');
	}
	printf("Encrypting...\n");
	data(key,code);
	fread(&x,1,1,fp1);
	for(i=0;feof(fp1)==0;i++)
	{
		x=x^(code[i]==0?5:10);
		fprintf(fp2,"%c",x);
		fread(&x,1,1,fp1);
		if(i==29)i=0;
	}
	fclose(fp1);
	fclose(fp2);
	printf("Success!\n");
	system("pause");
	return(0);
}