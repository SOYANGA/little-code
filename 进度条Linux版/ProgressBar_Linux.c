/*************************************************************************
	> File Name: ProgressBar.c
	> Author: SOYANGA
	> Mail: 321830725@qq.com 
	> Created Time: 2018年09月07日 星期五 19时54分05秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<time.h>
#define NONE         "\033[m"     
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"
#define max 200000   //随机生成最大的数为200000
#define min 30000    //随机生成最小的数为30000
int main()
{
	char bar[102]="\0";
	char back[100]="\0";
	int i=0;
	const char* lable="|/-\\-";
	printf("\033[?25l\033[8m%-100s\033[s",back[100]);//隐藏光标，隐藏打印内容，保存光标所在地方
	for(i=0;i<=100;i++)
	{
		srand(time(0));//生成随机数起点
		printf("\033[7;34m%s\033[u\033[0m%d%%[%c]\r",bar,i,lable[i%5]);//反相显示，蓝色打印进度条，取出保存的光标，返回普通模式打印百分数和转动图形
		fflush(stdout);//刷新输出流
		bar[i]=' ';//进度条内容
		usleep(rand() % (max - min) + min);//休眠函数嵌套随机数生成函数
	}
	printf("\n");
	printf("\33[?25h\33[0m");//显示光标
	return 0;
}
