//4.4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)    //获取键盘输入的值，直到出现EFO  和while ((ch = getc(stdin)) != EOF) 相同
	if (ch >= 'A' && ch <= 'Z')    //大写转小写
	{
		putchar(ch + 32);
	}
	else if (ch >= 'a'&& ch <= 'z')  //小写转大写 
		putchar(ch - 32);
	else if (ch >= '0' && ch <= '9')   //如果是数字则不输出    
	{
		;
	}
	else      //都不是则输出原来打的字符
	{
		putchar(ch);
	}
}
//getchar 只有遇到enter 时才向标准输入流输入字符（一个一个的字符）