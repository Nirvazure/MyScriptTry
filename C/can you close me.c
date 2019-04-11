#include "windows.h"
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPreInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd)
{
	while(1)
	MessageBox(NULL,"Can you close me?","Hello!",MB_OK);
	return 0;
}
