#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void menu()
{
	printf("---------------------     Contact   ---------------------------\n");
	printf("-------------1.添加联系人         2.删除联系人-----------------\n");
	printf("-------------3.查找联系人         4.修改联系人-----------------\n");
	printf("-------------5.显示联系人         6.清空联系人-----------------\n");
	printf("-------------7.排序联系人         0.退出Contact----------------\n");
}
int main()
{
	int input = 0;
	date people;
	initdate(&people);
	do
	{
		menu();
		printf("请输入你想要执行的操作。\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add(&people);
			break;
		case 2:
			Del(&people);
			break;
		case 3:
			Find(&people);
			break;
		case 4:
			change(&people);
			break;
		case 5:
			show(&people);
			break;
		case 6:
			initdate(&people);
			break;
		case 7:
			sort(&people);
			break;
		case 0:
			Desdate(&people);
			printf("成功退出，谢谢使用。\n");
			break;
			return 0;
		default:
			printf("输入非法指令！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}