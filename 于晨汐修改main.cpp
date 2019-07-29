
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
#include<iostream>
#include<fstream>
#include<string>
#include<graphics.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h> 



void welcome();
void menu1();
void menu2();
void Display();//调用display显示switch()菜单
void Register();//注册
void Enter();//登录
void activity();
using namespace std;

struct student
{
	char name[10];
	char gender[10];
	int age;
	char place[10];
	char number[10];
	char clazz[10];
	char department[10];
}stu, *s;

#define N 3

// 学生数组 
struct student S[N];

// 输入字符串
void inputStr(char * c, char * tips);
// 输入数字
void inputNum(int * n, char * tips);
// 录入函数 
void entering();
// 查询函数 
void query();
// 导出函数
void export();
// 输出字符串 
void  outputStr(char * c, char * tips);
// 输出数字 
void  outputNum(int n, char * tips);
// 写出字符串信息
void  exportStr(FILE * f, char * c, char * tips);
// 输出数字信息 
void  exportNum(FILE * f, int n, char * tips);
void activity();
void signin();
int chackbase();
void entering_grade();
void query_grade();
void export_grade();



int main()//主菜单进行了修改，只有退出和登录界面
{
	system("color F0");
	system("mode con cols=65 lines=20");//改变宽高
	welcome();
	cleardevice();
	//system("slc");
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop) {
		printf("\n======== The management system for student organizations ========\n");
		printf("\n        0:Sign out\n \t1:Log in and register \n");
		printf("\nPlease enter your choice:");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 登录 
			menu2();
			break;
		default: break;
		}
	}
}


void welcome()//菜单
{
	initgraph(323, 202);
	IMAGE img;	//准备图片

	loadimage(&img, "D:\\0重要的新建文件夹\\2018-2019下学期\\C语言啊\\20190704-4\\背景.jpg");
	//加载图片  L"背景.jpg"是图片的相对路径,也可以使用绝对路径

	putimage(0, 0, &img);
	//在指定位置贴图  前面的(0,0)是坐标  后面的&img是要贴的图片
	_getch();

	closegraph();

}

void menu_main()//进入主界面之后，选择是学生、组织者还是开发者模式
{
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop)
	{
		system("cls");
		printf("\n===================== The management system for student organizations =====================\n");
		printf("\n0:Sign out \n\t1:Student Version \n\t2:Organizer Version \n\t3:Staff version\n");
		printf("\nPlease enter your choice：");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 录入信息 
			entering();
			break;
		case 2: // 查询
			query();
			break;
		case 3: // 导出 
			export();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}

void menu_student()//学生模式包括查找活动、提交个人信息和查询成绩
{
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop)
	{
		system("cls");
		printf("\n===================== Student Version =====================\n");
		printf("\n0:Sign out \n\t1:Find Activity \n\t2:Enter registration information \n\t3:Find Grade \n");
		printf("\nPlease enter your choice：");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 查找活动 
			chackbase();
			break;
		case 2: // 录入个人信息
			entering();
			break;
		case 3:
			query_grade();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}

void menu_organizer()//组织者模式包括录入成绩、查找学生申请信息和发布成绩
{
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop)
	{
		system("cls");
		printf("\n===================== Organizer Version =====================\n");
		printf("\n0:Sign out \n\t1:Activity \n\t2:Find Application \n\t3:Publish Grade \n");
		printf("\nPlease enter your choice：");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 录入活动 
			activity();
			break;
		case 2: // 查询报名信息
			query();
			break;
		case 3:
			entering_grade();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}

void menu_staff()//开发者模式就是我们之前的菜单，删掉了登录和注册那块
{
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop)
	{
		system("cls");
		printf("\n===================== Organizer Version =====================\n");
		printf("\n        0:Sign out\n \t1:Activity registration \n\t2:Activity Release \n\t3:Export Grade \n");
		printf("\nPlease enter your choice：");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 到菜单1 
			menu1();
			break;
		case 2: // 到菜单2
			activity();
			break;
		case 3:
			export_grade();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}


void menu1()
{
	int op; // 操作方式 
	int loop = 1; // 是否循环
	while (loop)
	{
		system("cls");
		printf("\n===================== Activity Registration System =====================\n");
		printf("\n0:Sign out \n\t1:Enter registration information \n\t2:Enquiry for registration information \n\t3:Export registration information\n");
		printf("\nPlease enter your choice：");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // 退出 
			loop = 0;
			break;
		case 1: // 录入信息 
			entering();
			break;
		case 2: // 查询
			query();
			break;
		case 3: // 导出 
			export();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}






void menu2()
{
	system("cls");
	Display();//显示菜单　　１注册；２登录
	cin.get();
	//return 0;
}
void Register()//注册
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);//把注册的ID、code保存到web1.txt文件当中
	if (!outFile.is_open())//如果没有成功打开文件
	{
		cout << "很遗憾，连接不上服务器";
		cout << "程序结束";
		cin.get();
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	cout << "Please Enter members name: ";
	cin.get();//吃掉空字符
	getline(cin, name);
	//占位，假设输入的用户名超出长度或太短

	outFile << name << endl;//记录注册的资料到web1.txt文件中

	cout << "Please Enter members code: ";
	getline(cin, code);
	//占位，假设输入的密码超出长度或太短

	outFile << code << endl;//记录注册的资料到web1.txt文件中
	cout << "注册成功！";
	outFile.close();
	Display();
}
void Enter()//登录
{
	cin.get();
	ifstream inFile;//定义ifstream对象
	inFile.open("web1.txt");//读取web1.txt文件中的注册资料
	if (!inFile.is_open())//如果文件没有成功打开
	{
		cout << "很遗憾，连接不上服务器";
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	string temp;

	cout << "Please Enter members name: ";
	getline(cin, name);

	while (getline(inFile, temp))//匹配用户名
	{
		if (temp == name)//如果匹配用户名成功
		{
			cout << "Please Enter members code: ";//请输入密码
			getline(cin, code);//code
			getline(inFile, temp);//匹配code
			if (temp == code)//如果密码正确，登录成功
			{
				cout << "登录成功";
				menu_main(); //这里做了修改，登陆成功之后转到主界面 
							 //占位，登录成功应该转到程序主题
			}
			else
			{
				cout << "密码错误";
				Display();//返回！
			}
		}
	}
}

void Display()//菜单
{
	cout << "1)Register or Enter　　　　　2)Exit\n\nChoice:";
	int choice;//选择菜单
	cin >> choice;

	switch (choice)
	{
	case 1://注册
		signin();//call function调用函数
		break;
	case 2://退出
		exit(EXIT_FAILURE);
	}
}





