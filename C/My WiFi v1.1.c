#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
int main()
{
	char com1[50]="netsh wlan set hostednetwork ssid=";
	char com2[50]="netsh wlan set hostednetwork key=";
	char ssid[16]={0};
	char key[9]={0};
	int i=0;
	int error=0;
	FILE *fp;
//	HWND hwnd=GetForegroundWindow();
//	SendMessage(hwnd,WM_SETICON,ICON_SMALL,(LPARAM)LoadIcon(NULL,IDI_QUESTION));
	printf("-----Win7�����ȵ㿪������-----\n\n");
	if((fp=fopen("C:\\Windows\\�ҿ���ɾ","w+"))==NULL)
	{
		printf("�޷���ȡ����ԱȨ�ޣ����ڱ������˳����Ҽ�-->�Թ���Ա������С��˳���\n\n��������˳�...\n");
		getch();
		return 0;
	}
	else
	{
		fclose(fp);
		remove("C:\\Windows\\�ҿ���ɾ");
		printf("�ѻ�ȡ����ԱȨ�ޡ�\n\n");
	}
	printf("��ѡ�������\n1.���ü���WiFi\n2.�����µ�WiFi������������\n3.�޸�WiFi�ȵ�\n4.ͣ��WiFi�ȵ㣨Ҫ�õ�����������������ʱ���裩\n");
	while(i!='1'&&i!='2'&&i!='3'&&i!='4')i=getch();
	if(i=='1')
	{
		system("netsh wlan stop hostednetwork");
		system("netsh wlan start hostednetwork");
	}
	if(i=='2')
	{
		printf("��������������(Ӣ�Ļ����ֻ��»��ߣ����15λ)��");
		while(1)
		{
			error=0;
			for(i=0;i<=15;i++)ssid[i]=0;
			fflush(stdin);
			gets(ssid);
			for(i=0;i<=15;i++)
				if(!(isalnum(ssid[i])||ssid[i]=='_'||ssid[i]==0))error=1;;
			if(ssid[15]==0&&ssid[0]!=0&&error==0)break;
			printf("�����ʽ���������������������ƣ�(Ӣ�Ļ����ֻ��»��ߣ����15λ)");
		}
		printf("������8λ���루Ӣ�Ļ����֣���");
		while(1)
		{
			for(i=0;i<=8;i++)key[i]=0;
			fflush(stdin);
			gets(key);
			if(key[7]!=0&&key[8]==0)break;
			printf("�����ʽ��������������8λ���루Ӣ�Ļ����֣���");
		}
		strcat(com1,ssid);
		strcat(com2,key);
		printf("\n��ȴ�..\n");
		system("sc config BFE Start= auto");
		printf("\n��ȴ�...\n");
		system("sc config MpsSvc Start= auto");
		printf("\n��ȴ�....\n");
		system("sc config SharedAccess Start= auto");
		printf("\n��ȴ�.....\n");
		system("net start BFE");
		system("net start MpsSvc");
		system("net start SharedAccess config");
		printf("\n��ȴ�......\n");
		system("netsh wlan set hostednetwork mode=allow");
		system(com1);
		system(com2);
		printf("-------------------\n\n������Ҫ�ֶ������ˡ�\n\n");
		printf("1.�ڴ򿪵����������ô����У��ҵ������������ʣ�û��С�����Ҳ��ǻҵģ��ı������ӣ�Ҳ����������������������磻\n2.�Ҽ��������������->����\n3.��ѡ���������������û�ͨ���˼������Internet���ӡ�ѡ��������˵���ѡ��ղŽ������������磨һ��Ϊ��My WiFi������ȷ����\n\n");
		system("start CONTROL.EXE ncpa.cpl");
		printf("���óɹ��󣬰���y��������\n");
		while(i!='y')i=getch();
		system("netsh wlan start hostednetwork");
		printf("������ɣ�WiFi�����á�\n--------------------\n�Ժ���Ҫʹ��WiFiʱ���������������1�����ɣ��������ԱȨ�����У���\n");
	}
	if(i=='3')
	{
		printf("�޸���...");
		system("netsh interface set interface name=""������������"" admin=disabled");
		system("netsh interface set interface name=""������������"" admin=enabled");
		system("netsh wlan set hostednetwork mode=allow");
		system("netsh wlan stop hostednetwork");
		system("netsh wlan start hostednetwork");
		printf("���޸����ܽ�����⣬�����´���WiFi��\n");
	}
	if(i=='4')
	{
		system("netsh wlan stop hostednetwork");
	}
	printf("\n���!\n\n");
	system("pause");
	return 0;
}