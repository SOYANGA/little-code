//3.3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char password[20] = { 0 };        //输入的密码
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:");
		scanf_s("%s", password);  //输入密码
		if (strcmp("123456", password) == 0)   //比较密码
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i == 3)  //输入3次密码
	{
		printf("三次密码错误！退出程序\n");
		system("pause");
		return 0;
	}
}