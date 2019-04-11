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
	printf("-----Win7无线热点开启工具-----\n\n");
	if((fp=fopen("C:\\Windows\\我可以删","w+"))==NULL)
	{
		printf("无法获取管理员权限，请在本程序退出后‘右键-->以管理员身份运行’此程序。\n\n按任意键退出...\n");
		getch();
		return 0;
	}
	else
	{
		fclose(fp);
		remove("C:\\Windows\\我可以删");
		printf("已获取管理员权限。\n\n");
	}
	printf("请选择操作：\n1.启用既有WiFi\n2.创建新的WiFi网络名和密码\n3.修复WiFi热点\n4.停用WiFi热点（要用电脑连接其他无线网时必需）\n");
	while(i!='1'&&i!='2'&&i!='3'&&i!='4')i=getch();
	if(i=='1')
	{
		system("netsh wlan stop hostednetwork");
		system("netsh wlan start hostednetwork");
	}
	if(i=='2')
	{
		printf("请输入网络名称(英文或数字或下划线，最多15位)：");
		while(1)
		{
			error=0;
			for(i=0;i<=15;i++)ssid[i]=0;
			fflush(stdin);
			gets(ssid);
			for(i=0;i<=15;i++)
				if(!(isalnum(ssid[i])||ssid[i]=='_'||ssid[i]==0))error=1;;
			if(ssid[15]==0&&ssid[0]!=0&&error==0)break;
			printf("输入格式错误，请重新输入网络名称：(英文或数字或下划线，最多15位)");
		}
		printf("请输入8位密码（英文或数字）：");
		while(1)
		{
			for(i=0;i<=8;i++)key[i]=0;
			fflush(stdin);
			gets(key);
			if(key[7]!=0&&key[8]==0)break;
			printf("输入格式错误，请重新输入8位密码（英文或数字）：");
		}
		strcat(com1,ssid);
		strcat(com2,key);
		printf("\n请等待..\n");
		system("sc config BFE Start= auto");
		printf("\n请等待...\n");
		system("sc config MpsSvc Start= auto");
		printf("\n请等待....\n");
		system("sc config SharedAccess Start= auto");
		printf("\n请等待.....\n");
		system("net start BFE");
		system("net start MpsSvc");
		system("net start SharedAccess config");
		printf("\n请等待......\n");
		system("netsh wlan set hostednetwork mode=allow");
		system(com1);
		system(com2);
		printf("-------------------\n\n接下来要手动配置了。\n\n");
		printf("1.在打开的适配器设置窗口中，找到你的有网络访问（没有小红叉而且不是灰的）的本地连接，也就是你连入网络的有线网络；\n2.右键点击它，打开属性->共享\n3.勾选“允许其他网络用户通过此计算机的Internet连接”选项，在下拉菜单中选择刚才建立的虚拟网络（一般为“My WiFi”）并确定。\n\n");
		system("start CONTROL.EXE ncpa.cpl");
		printf("设置成功后，按‘y’继续…\n");
		while(i!='y')i=getch();
		system("netsh wlan start hostednetwork");
		printf("创建完成，WiFi已启用。\n--------------------\n以后需要使用WiFi时，启动本软件按‘1’即可（仍需管理员权限运行）。\n");
	}
	if(i=='3')
	{
		printf("修复中...");
		system("netsh interface set interface name=""无线网络连接"" admin=disabled");
		system("netsh interface set interface name=""无线网络连接"" admin=enabled");
		system("netsh wlan set hostednetwork mode=allow");
		system("netsh wlan stop hostednetwork");
		system("netsh wlan start hostednetwork");
		printf("若修复不能解决问题，请重新创建WiFi。\n");
	}
	if(i=='4')
	{
		system("netsh wlan stop hostednetwork");
	}
	printf("\n完成!\n\n");
	system("pause");
	return 0;
}