
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
void imput_activity();
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
		printf("\n0:Sign out \n\t1:Find Activity \n\t2:Enter registration information \n");
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
		printf("\n0:Sign out \n\t1:Activity \n\t2:Find Application \n");
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
		printf("\n        0:Sign out\n \t1:Activity registration \n\t2:Activity Release \n");
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

// 输入字符串
void inputStr(char * c, char * tips)
{
	printf("please enter%s:", tips);
	gets_s(c, sizeof(c));
}
// 输入数字
void inputNum(int * n, char * tips)
{
	printf("please enter%s:", tips);
	scanf_s("%d", n);
	getchar();
}
// 录入函数 
void entering()
{
	system("cls");
	int i, j = 0;
	for (i = 0; i < N; ++i)
	{
		printf("\n\n---------(input registration) %d (information)---------\n\n", i + 1);
		inputStr(S[i].name, "name");
		inputStr(S[i].gender, "gender");
		inputNum(&(S[i].age), "age");
		inputStr(S[i].place, "native place");
		inputStr(S[i].number, "student ID");
		inputStr(S[i].clazz, "class");
		inputStr(S[i].department, "major");
		printf("Do you want to continue?( 1 for YES and 2 for NO)\n");
		rewind(stdin);
		scanf_s("%d", &j); getchar();
		if (j == 2)
			break;
	}
}

// 输出字符串信息
void  outputStr(char * c, char * tips)
{
	printf("%s: %s\n", tips, c);
}

// 输出数字信息 
void  outputNum(int n, char * tips)
{
	printf("%s: %d\n", tips, n);
}

// 写出字符串信息
void  exportStr(FILE * f, char * c, char * tips)
{
	fprintf(f, "%s: %s\n", tips, c);
}

// 输出数字信息 
void  exportNum(FILE * f, int n, char * tips)
{
	fprintf(f, "%s: %d\n", tips, n);
}



// 查询函数 
void query()
{
	system("cls");
	int i;
	char number[10];
	printf("\n\n(input the information to be queried)：");
	scanf_s("%s", number, sizeof(s));
	for (i = 0; i < N; ++i)
	{
		if (strcmp(number, S[i].number) == 0)
		{
			printf("\n--------(registration information)--------\n");
			outputStr(S[i].name, "(name)");
			outputStr(S[i].gender, "(gender)");
			outputNum((S[i].age), "(age)");
			outputStr(S[i].place, "(native place)");
			outputStr(S[i].number, "(student ID)");
			outputStr(S[i].clazz, "（class）");
			outputStr(S[i].department, "（major）");
			printf("\n------------------------\n");
			break;
		}
	}
	if (i == N)
	{
		printf("\n(Input information not found)\n");
	}
	printf("(press any key to continue...)");
	getchar();
	getchar();
}
// 导出函数
void export()
{
	FILE *f;
	int i;
	fopen_s(&f, "export.txt", "w");
	printf("\n-------------------------\nIn the process of derivation...\n");
	for (i = 0; i < N; ++i)
	{
		fprintf(f, "\n--------Registration information %d--------\n", i + 1);
		exportStr(f, S[i].name, "name");
		exportStr(f, S[i].gender, "gender");
		exportNum(f, (S[i].age), "age");
		exportStr(f, S[i].place, "native place");
		exportStr(f, S[i].number, "student ID");
		exportStr(f, S[i].clazz, "class");
		exportStr(f, S[i].department, "major");
		fprintf(f, "\n---------------------------\n");
	}
	fclose(f);
	printf("\nThe student registration system has been exported as follows:“export.txt”\n-------------------------\npress any key to continue...");
	getchar();
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
	cout << "1)Register　　　　　2)Enter\n3)Exit\n\nChoice:";
	int choice;//选择菜单
	cin >> choice;

	switch (choice)
	{
	case 1://注册
		Register();//call function调用函数
		break;
	case 2://登录
		Enter();//call function调头函数
		break;
	case 3://退出
		exit(EXIT_FAILURE);
	}
}





#include<stdio.h>  //头文件
#include<string.h> //头文件
#include<stdlib.h> //头文件
#define M 100      //活动种类
#define N 100      //活动数目
struct activitys       //单个活动信息格式
{
	int  number;   //活动编号
	char name[20]; //活动名称
	int  price1;   //起始时间
	int  price2;   //终止时间
	int  amount;   //剩余空位数量
};
struct orderlist           //报名格式
{
	struct activitys L[M];
};
struct customer            //报名信息内容和格式
{
	char name[20];         //姓名
	char password[6];      //密码
	int count;             //编号
};
struct customer khl[N];    //所有活动信息
struct activitys base[M];      //人数信息
struct orderlist odl[10 * N];//报名表
struct activitys lackl[M];     //活动表
struct activitys suml[M + 1];
int PP = 0;                  //活动编号
int QQ = 0;                   //报名编号
int goodssum = 0;              //活动总数

							   //子函数
void  activity()                    //子函数开始
{
	int welcomeactivity();        //欢迎界面函数声明
	int studentregister();            //报名学生函数声明
	int realease();        //发布活动函数声明
	int manager();     //管理活动函数声明
	int goodbye();    //欢送函数声明
	int n, m = 9;       //变量声明
						//SysUseWay();    //系统使用说明书

	while (m == 9)   //循环三岔口
	{
		welcomeactivity();  //欢迎界面
		scanf("%d", &n);
		switch (n) //进行选择
		{
			//先清屏，保持整洁的页面
			system("cls");
		case 0:; break;
		case 1: studentregister(); break;       //报名学生
		case 2: realease(); break;    //发布活动
		case 3: manager(); break;  //管理活动
		default: printf("Input error! Please exit and re-enter");
		}
		if (n == 0)
			break;
		printf("Continue to enter the main interface, press 9 to exit, press 0 \n");
		scanf("%d", &m);
	}
	goodbye();                  //欢送界面

}                               //函数结束!

								//欢迎界面函数定义
int welcomeactivity()
{
	system("cls");

	printf("..........................................................\n");
	printf("\n");
	printf("               ~~~~~~~~activity~~~~~~~~\n");
	printf("               student register press       1\n");
	printf("               realease activity press       2\n");
	printf("               manage activities press       3\n");
	printf("       To exit the main interface, please press      0\n");
	return 0;
}

//初始化函数
int chushihua()
{
	int i = 0, j = 0;
	for (i = 0; i<M; i++)
	{
		suml[i].number = lackl[i].number = base[i].number = -1;
		base[i].amount = 0;
		base[i].price1 = base[i].price2 = 0;
		lackl[i].amount = 0;
		suml[i].price1 = 0;
		suml[i].amount = 0;
	}
	suml[M].price1 = 0;
	for (i = 0; i<N; i++)
		khl[i].count = -1;
	for (i = 0; i<10 * N; i++)
	{
		for (j = 0; j<M; j++)
		{
			odl[i].L[j].number = j;
			odl[i].L[j].amount = 0;
			odl[i].L[j].price1 = base[j].price1;
			odl[i].L[j].price2 = base[j].price2;
		}
	}

	return 0;
}

//欢送界面函数定义
int goodbye()
{
	system("cls");
	//清理屏幕
	printf("  ~~~~thank you for your using~~~~\n");
	return 0;
}
//发布活动函数
int realease()
{
	int welcomestudent();     //欢迎函数
	int activityrealease();       //活动发布
	int solvelack();        //查询活动人数情况
	int chackbase();        //查询活动总体情况
	int n;
	int m = 9;
	while (m == 9)             //循环三岔口
	{
		system("cls");
		welcomestudent();             //欢迎欢迎
		scanf("%d", &n);             //各奔东西
		switch (n)
		{
		case 0:; break;            //退出
		case 1: solvelack(); break;  //查询报名人数
		case 2: activityrealease(); break; //发布活动
		case 3: chackbase(); break;  //查询活动总体情况
		default:printf("input error!\n");
		}
		if (n == 0)
			break;
		printf("Continue publishing please press 9 or press 0 \n");
		scanf("%d", &m);
	}
	return 0;
}

int welcomestudent()
{
	system("cls");
	printf("....................................................\n");
	printf("\n");
	printf("         ~~~~~~~~activity realease~~~~~~~~\n");
	printf("        Realease activity press                  1\n");
	printf("        Query number of participants press       2\n");
	printf("        Overall status of activities press       3\n");
	printf("        Exit activity part press                 0\n");
	return 0;
}

//发布活动函数--发布活动函数
int activityrealease()
{
	int i = 0;
	printf("If you want to stop publishing, please enter in the number of people in need.  0\n\n");
	for (i = 0; i<M; i++)
	{
		printf("\nactivity name:");
		scanf("%s", base[i].name);
		base[i].number = i;
		printf("\nactivity number:");
		scanf("%d", &base[i].amount);
		if (base[i].amount <= 0) {
			base[i].amount = 0;
			break;
		}
		goodssum += base[i].amount;
		printf("\nthe people in need:");
		scanf("%d", &base[i].price1);
		printf("\nnumber of registered persons:");
		scanf("%d", &base[i].price2);
	}
	return 0;
}

//活动函数---查询当前活动整体情况函数
int chackbase()
{
	system("cls");
	int i = 0;
	printf("................................................................................\n");
	if (goodssum == 0)
	{
		printf("No activity, please release it in time\n");
		return 0;
	}
	for (i = 0; i<M; i++)
	{
		if (base[i].amount>0) {
			printf("....................................................................\n");
			printf("activity number  activity name             the number of activities         the people in need       number already available\n");
			printf(" %3d      %-20s %6d          %6d     %6d \n", base[i].number, base[i].name, base[i].amount, base[i].price1, base[i].price2);
			printf("................................................................................\n");
		}
		else
			continue;
	}
	printf(".............................................................\n");
	return 0;
}

//活动函数--处理活动函数
int solvelack()
{
	int i = 0, k = 0;
	int printlack();           //活动函数--处理活动函数--查看函数声明
	int supplement();          //活动函数--处理活动函数--增加活动函数声明
	printlack();               //查看是否缺货
	printf("If there is a need to increase the number of activities，ress 1 or press 0 \n");
	scanf("%d", &k);
	switch (k)
	{
	case 1:supplement(); break;
	case 0:; break;
	default:printf("input error!\n");
	}
	return 0;
}
int printlack()                //采购函数--处理缺货函数--查看函数定义
{
	int i = 0, count = 0;
	if (goodssum == 0) {
		printf("No one registered, please release information in time \n");
		return 0;
	}
	printf("................................................................\n");
	for (i = 0; i<M; i++)
	{
		if (lackl[i].amount == 0) {
			count++;
			continue;
		}
		else {
			printf("................................................................................\n");
			printf("activity number  activity name            the people in need\n");
			printf(" %3d      %-20s %6d          \n", lackl[i].number, base[i].name, lackl[i].amount);
		}
	}
	printf("....................................................................\n");
	if (count == M)
		printf(" There is still seats left \n");
	else
		printf(" The number of registers is full\n");
	return 0;
}

//活动函数--处理活动不足函数--添加活动函数定义
int supplement()
{
	int i = 0, j = 1;
	int printlack();
	printlack();
	printf("If you want to stop recruiting, \nplease enter 0 on the number of activity requests. \n");
	while (j>0)
	{
		printf("activity number\n");
		scanf("%d", &i);
		while (i >= M) {
			printf("This activity does not exist. Please re-enter it. \n");
			scanf("%d", &i);
		}
		base[i].number = i;
		printf("activity name:\n");
		scanf("%s", base[i].name);
		printf("the people in need:\n");
		scanf("%d", &j);
		if (j>0) {
			base[i].amount += j;
			goodssum += j;
		}
		else
			break;
		printf("\nthe people in need:");
		scanf("%d", &base[i].price1);
		printf("\nnumber of registered persons :");
		scanf("%d", &base[i].price2);
	}
	return 0;
}

//报名活动函数
int studentregister()
{

	int login();                      //学生函数--登陆函数声明
	int registe();                    //学生函数--注册函数声明
	int welcomestudents();                  //学生函数--欢迎函数声明
	int searchkh(int falg);           //学生函数--查询或贷款哪个情况的函数声明
	int order(int falg);              //学生函数--报名活动函数声明
	int i, k = 0, flag = 0;
	int n = 9, m = 9;

	system("cls");
	welcomestudents();                     //欢迎欢迎
	while (m == 9)                      //登陆
	{
		printf("enter press 1，register press 2, or press 0\n");
		scanf("%d", &i);
		switch (i)
		{
		case 0:; break;
		case 1: flag = login(); break;
		case 2: registe(); break;
		default:printf("input error!\n");
		}
		if (i == 0)
			break;
		printf("enter or register please press 9  or press 0\n");
		scanf("%d", &m);
	}

	while (n == 9)                      //报名？查询循环二岔路
	{
		system("cls");
		printf(" query activities press 1,  \n register activities press 2,\n or press 0\n");
		scanf("%d", &i);
		switch (i)
		{
		case 0:; break;
		case 1: searchkh(flag); break;
		case 2: order(flag); break;
		default:printf("input error!\n");
		}
		if (i == 0)
			break;
		printf("To continue inquiring about related activities,\n press 9 or press 0 \n");
		scanf("%d", &n);
	}
	return 0;
}


int welcomestudents()                    //学生函数---欢迎函数定义
{
	system("cls");

	printf("...................................................\n");
	printf("~~~~~~~~welcome to take  part in activity~~~~~~~~\n");
	printf("...................................................\n");
	return 0;
}

//学生函数---登陆函数定义
int login()

{
	system("cls");
	//清理屏幕
	int n, count = 0;
	char password[6];
	printf("-----------please enter account number------------\n");
	scanf("%d", &n);
	printf("-----------please enter password------------------\n");
	scanf("%s", password);
	while (strcmp(password, khl[n].password))
	{
		printf("~~~~~please reinput six-digit password ~~~~~\n");
		printf("\n");
		printf("sign out please input 123456 \n");
		scanf("%s", password);

		if (!strcmp(password, "123456"))
			welcomeactivity();
		break;
	}
	if (!strcmp(password, "123456"))
		return 0;
	else
		return n;
}

//学生报名函数---注册函数定义
int registe()
{
	system("cls");
	printf("~~~~~your account is: %d ,don't forget it ~~~~~\n", QQ);
	printf("~~~~~please enter your account name:~~~~~~~~\n");
	scanf("%s", khl[QQ].name);
	printf("~~~~~~Please enter a six-digit password :~~~~~~\n");
	printf("\n");
	scanf("%s", khl[QQ].password);
	QQ++;
	return 0;
}

//学生函数---查询函数定义
int searchkh(int flag)
{
	int n, i = 0;
	n = flag;
	system("cls");
	printf("......................................................\n");
	printf("    Hello   %s   your account is: %d\n", khl[n].name, n);
	printf(".......................................................\n");
	if (khl[n].count != -1) {
		for (i = 0; i<M; i++) {
			if (odl[khl[n].count].L[i].amount == 0)
				i++;
			else {
				system("cls");
				printf("................................................................................\n");
				printf("activity number  activity name             number in neeed          Number already available\n");
				printf(" %3d  %-20s %6d  %6d\n", base[i].number, base[i].name, odl[khl[n].count].L[i].amount, base[i].price2);
				printf("................................................................................\n");
			}

		}
	}
	else {
		system("cls");
		printf("\n");
		printf("......................................................\n");
		printf("You are not currently participating in any activities.  \n");
		printf("......................................................\n");
	}
	printf("................................................\n");
	return 0;
}

//学生报名函数--报名活动函数
int order(int flag)
{
	int i = 0, k = 0, m = 0, n = 0, count = 0;
	printf("\n");
	n = flag;
	system("cls");
	printf("activity name  activity number               Number already available\n");
	printf("\n");
	for (i = 0; i<M; i++) {
		if (base[i].number == -1) {
			count++;
			continue;
		}
		else
			printf(" %3d      %-20s %6d\n", base[i].number, base[i].name, base[i].price2);
	}
	if (count == M)
	{
		printf("Sorry, there are no related activities at present.\n");
		return 0;
	}
	printf("Please enter the number and name of the activity. \nIf you want to finish, enter it on the number 0 \n");
	printf("activity number\n");
	scanf("%d", &k);
	while ((k >= M) || (base[k].number == -1)) {
		printf("This activity does not exist. Please re-enter it. \n");
		scanf("%d", &k);
	}
	printf("number\n");
	scanf("%d", &m);
	while (m>0)
	{
		if (base[k].amount<m)
		{
			odl[PP].L[k].amount = base[k].amount;
			base[k].amount = 0;
			printf("Activities are not yet open\n", odl[PP].L[k].amount - base[k].amount, base[k].amount);
			lackl[k].amount += (m - base[k].amount);
		}
		else {
			odl[PP].L[k].amount = m;
			base[k].amount -= m;
		}
		goodssum -= odl[PP].L[k].amount;
		suml[k].price1 += (odl[PP].L[k].amount*(base[k].price2 - base[k].price1));
		suml[M].price1 += suml[k].price1;
		suml[k].amount += odl[PP].L[k].amount;
		printf("activity number\n");
		scanf("%d", &k);
		while ((k >= M) || (base[k].number == -1)) {
			printf("This activity does not exist. Please re-enter it. \n");
			scanf("%d", &k);
		}
		printf("Number of participants\n");
		scanf("%d", &m);
	}
	khl[n].count = PP;
	PP++;
	return 0;
}

//活动管理函数定义
int manager()
{
	system("cls");

	int i = 0;
	for (i = 0; i<M; i++)
	{
		if (suml[i].amount == 0)
			i++;
		else {
			system("cls");
			printf("...................................................................\n");
			printf("activity number  activity name           Estimated number\n");
			printf(" %3d      %-20s %6d          \n", suml[i].number, base[i].name, suml[i].price1);
			printf("....................................................................\n");
		}
	}
	system("cls");
	printf("\n-------the number of whole activities is  %d  -------\n", goodssum);
	printf("\n-------the number of whole participants is  %d -------\n", suml[M].price1);
	return 0;
}

