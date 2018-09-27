//1.完成猜数字游戏。
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
void menu()
{
	printf("*****************************************\n");
	printf("*************   1.play  *****************\n");
	printf("*************   0.exit   ****************\n");
	printf("*****************************************\n");
}
void game()
{
	int ret = 0;      //接受随机数
	int input = 0;   //输入猜的数
	int i = 0;      //判定反馈信息
	ret = rand() % 100 + 1;   //随机数生成101 到1 之间的数   ret = rand() % (max1 - min1) + min1;
	while (1)
	{
		printf("请输入要猜的数字\n");
		scanf_s("%d", &input);
		if (input > ret)
		{
			printf("猜大了,请再猜\n");
			i++;
		}
		if (input < ret)
		{
			printf("猜小了，请再猜\n");
			i++;
		}
		else if (input == ret && i == 0)
		{
			printf("走了狗屎运了吧，猜对了！！\n");
			break;
		}
		else if (input == ret && i != 0)
		{
			printf("恭喜你，猜对了！！\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));  //随机数生成标志
	do
	{
		menu();                      //菜单模块
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}