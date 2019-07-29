#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h> 

void menu_main();
void welcome();

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

// ѧ������ 
struct student S[N];
// �����ַ���
void inputStr(char * c, char * tips)
{
	printf("please enter%s:", tips);
	gets_s(c, sizeof(c));
}
// ��������
void inputNum(int * n, char * tips)
{
	printf("please enter%s:", tips);
	scanf_s("%d", n);
	getchar();
}
// ¼�뺯�� 
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

// ����ַ�����Ϣ
void  outputStr(char * c, char * tips)
{
	printf("%s: %s\n", tips, c);
}

// ���������Ϣ 
void  outputNum(int n, char * tips)
{
	printf("%s: %d\n", tips, n);
}

// д���ַ�����Ϣ
void  exportStr(FILE * f, char * c, char * tips)
{
	fprintf(f, "%s: %s\n", tips, c);
}

// ���������Ϣ 
void  exportNum(FILE * f, int n, char * tips)
{
	fprintf(f, "%s: %d\n", tips, n);
}



// ��ѯ���� 
void query()
{
	system("cls");
	int i;
	char number[10];
	printf("\n\n(input the information to be queried)��");
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
			outputStr(S[i].clazz, "��class��");
			outputStr(S[i].department, "��major��");
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
// ��������
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
	printf("\nThe student registration system has been exported as follows:��export.txt��\n-------------------------\npress any key to continue...");
	getchar();
}

struct grade
{
	char name[10];
	char gender[10];
	int age;
	char grade[10];
	char number[10];
	char clazz[10];
	char department[10];
}gra, *g;

struct grade G[N];


void menu0()
{
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n=====================Grade=====================\n");
		printf("\n0:Sign out \n\t1:Submit grade \n\t2:Find grade \n\t3:Export grade\n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ¼��ɼ�
			entering_grade();
			break;
		case 2: // ��ѯ�ɼ�
			query_grade();
			break;
		case 3: // �����ɼ�
			export_grade();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}


// ¼��ɼ� 
void entering_grade()
{
	system("cls");
	int i;
	for (i = 0; i < N; ++i)
	{
		printf("\n\n---------(input grade)---------\n\n", i + 1);
		inputStr(G[i].name, "name");
		inputStr(G[i].gender, "gender");
		inputNum(&(G[i].age), "age");
		inputStr(G[i].number, "student ID");
		inputStr(G[i].clazz, "class");
		inputStr(G[i].department, "major");
		inputStr(G[i].grade, "grade");
	}
}
// ��ѯ�ɼ�
void query_grade()
{
	system("cls");
	int i;
	char number[10];
	printf("\n\n(input the information to be queried)��");
	scanf_s("%s", number, sizeof(s));
	for (i = 0; i < N; ++i)
	{
		if (strcmp(number, S[i].number) == 0)
		{
			printf("\n--------(registration information)--------\n");
			outputStr(G[i].name, "(name)");
			outputStr(G[i].gender, "(gender)");
			outputNum((G[i].age), "(age)");
			outputStr(G[i].number, "(student ID)");
			outputStr(G[i].clazz, "��class��");
			outputStr(G[i].department, "��major��");
			outputStr(G[i].grade, "(grade)");
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

// �����ɼ�
void export_grade()
{
	FILE *f;
	int i;
	fopen_s(&f, "export.txt", "w");
	printf("\n-------------------------\nIn the process of derivation...\n");
	for (i = 0; i < N; ++i)
	{
		fprintf(f, "\n--------Registration information %d--------\n", i + 1);
		exportStr(f, G[i].name, "name");
		exportStr(f, G[i].gender, "gender");
		exportNum(f, (G[i].age), "age");
		exportStr(f, G[i].number, "student ID");
		exportStr(f, G[i].clazz, "class");
		exportStr(f, G[i].department, "major");
		exportStr(f, G[i].grade, "grade");
		fprintf(f, "\n---------------------------\n");
	}
	fclose(f);
	printf("\nThe student registration system has been exported as follows:��export.txt��\n-------------------------\npress any key to continue...");
	getchar();
}


 
void signin()    //��¼��ע�� 
{
	FILE *fp;
	char password[18];
    char _password[18];
	system("cls");
	int i = 0;
	char k;
	char str[] = "000000";   //��ʼ���� 
	printf("please imput the code:");
	for (;;)              //�˴�Ϊ�������벻���Բ��� 
	{
		k = getch();       //����k 
		if (k == '\r')      //�������kΪ�س���������ѭ�� 
		{
			break;
		}
		else if (k == '\b')  //�������kΪɾ���� 
		{
			if (i>0)       //�������뻹û��ȫɾ�� 
			{
				printf("\b");
				printf(" ");
				printf("\b");
				i--;
			}
		}
		else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
		{
			_password[i] = k;   //��k��ֵ����_password[i]; 
			printf("*");      //���*�ţ������û���˽ 
			i++;              //����λ����1 
		}
	}
	_password[i] = '\0';
	if (strcmp(password, " ") == 0)   //�жϳ����Ƿ��ǵ�һ�����У�
	{
		strcpy(password, str);//����ǣ��򽫳�ʼ����000000��ֵ��password 
		save_password();//��������
		menu_main;
	}
	if (strcmp(password, _password) == 0)   //�ж������Ƿ�������ȷ 
	{
		system("cls");
		printf("loading....");
		menu_main();
	}
	else
	{
		printf("wrong code��");
		welcome();
	}	
}

void save_password()   //��p��ָ������ݱ��浽�ļ��� 
{
	FILE *fp;
	fp = fopen("password", "w");   //��ֻд�ķ�ʽ����Ϊpassword���ļ� 
	if (fp == NULL)
	{
		printf("cannot open file");
	}
	fclose(fp);   //�ر��ļ� 
}

#include<stdio.h>  //ͷ�ļ�
#include<string.h> //ͷ�ļ�
#include<stdlib.h> //ͷ�ļ�
#define M 100      //�����
#define N 100      //���Ŀ
struct activitys       //�������Ϣ��ʽ
{
	int  number;   //����
	char name[20]; //�����
	int  price1;   //��ʼʱ��
	int  price2;   //��ֹʱ��
	int  amount;   //ʣ���λ����
};
struct orderlist           //������ʽ
{
	struct activitys L[M];
};
struct customer            //������Ϣ���ݺ͸�ʽ
{
	char name[20];         //����
	char password[6];      //����
	int count;             //���
};
struct customer khl[N];    //���л��Ϣ
struct activitys base[M];      //������Ϣ
struct orderlist odl[10 * N];//������
struct activitys lackl[M];     //���
struct activitys suml[M + 1];
int PP = 0;                  //����
int QQ = 0;                   //�������
int goodssum = 0;              //�����

							   //�Ӻ���
void  activity()                    //�Ӻ�����ʼ
{
	int welcomeactivity();        //��ӭ���溯������
	int studentregister();            //����ѧ����������
	int realease();        //�������������
	int manager();     //������������
	int goodbye();    //���ͺ�������
	int n, m = 9;       //��������
						//SysUseWay();    //ϵͳʹ��˵����

	while (m == 9)   //ѭ�������
	{
		welcomeactivity();  //��ӭ����
		scanf("%d", &n);
		switch (n) //����ѡ��
		{
			//�����������������ҳ��
			system("cls");
		case 0:; break;
		case 1: studentregister(); break;       //����ѧ��
		case 2: realease(); break;    //�����
		case 3: manager(); break;  //����
		default: printf("Input error! Please exit and re-enter");
		}
		if (n == 0)
			break;
		printf("Continue to enter the main interface, press 9 to exit, press 0 \n");
		scanf("%d", &m);
	}
	goodbye();                  //���ͽ���

}                               //��������!

								//��ӭ���溯������
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

//��ʼ������
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

//���ͽ��溯������
int goodbye()
{
	system("cls");
	//������Ļ
	printf("  ~~~~thank you for your using~~~~\n");
	return 0;
}
//���������
int realease()
{
	int welcomestudent();     //��ӭ����
	int activityrealease();       //�����
	int solvelack();        //��ѯ��������
	int chackbase();        //��ѯ��������
	int n;
	int m = 9;
	while (m == 9)             //ѭ�������
	{
		system("cls");
		welcomestudent();             //��ӭ��ӭ
		scanf("%d", &n);             //��������
		switch (n)
		{
		case 0:; break;            //�˳�
		case 1: solvelack(); break;  //��ѯ��������
		case 2: activityrealease(); break; //�����
		case 3: chackbase(); break;  //��ѯ��������
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

//���������--���������
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

//�����---��ѯ��ǰ������������
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

//�����--��������
int solvelack()
{
	int i = 0, k = 0;
	int printlack();           //�����--��������--�鿴��������
	int supplement();          //�����--��������--���ӻ��������
	printlack();               //�鿴�Ƿ�ȱ��
	printf("If there is a need to increase the number of activities��ress 1 or press 0 \n");
	scanf("%d", &k);
	switch (k)
	{
	case 1:supplement(); break;
	case 0:; break;
	default:printf("input error!\n");
	}
	return 0;
}
int printlack()                //�ɹ�����--����ȱ������--�鿴��������
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

//�����--�������㺯��--��ӻ��������
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

//���������
int studentregister()
{

	int login();                      //ѧ������--��½��������
	int registe();                    //ѧ������--ע�ắ������
	int welcomestudents();                  //ѧ������--��ӭ��������
	int searchkh(int falg);           //ѧ������--��ѯ������ĸ�����ĺ�������
	int order(int falg);              //ѧ������--�������������
	int i, k = 0, flag = 0;
	int n = 9, m = 9;

	system("cls");
	welcomestudents();                     //��ӭ��ӭ
	while (m == 9)                      //��½
	{
		printf("enter press 1��register press 2, or press 0\n");
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

	while (n == 9)                      //��������ѯѭ������·
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


int welcomestudents()                    //ѧ������---��ӭ��������
{
	system("cls");

	printf("...................................................\n");
	printf("~~~~~~~~welcome to take  part in activity~~~~~~~~\n");
	printf("...................................................\n");
	return 0;
}

//ѧ������---��½��������
int login()

{
	system("cls");
	//������Ļ
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

//ѧ����������---ע�ắ������
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

//ѧ������---��ѯ��������
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

//ѧ����������--���������
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

//�����������
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


