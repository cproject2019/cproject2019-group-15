
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
void Display();//����display��ʾswitch()�˵�
void Register();//ע��
void Enter();//��¼
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

// ѧ������ 
struct student S[N];

// �����ַ���
void inputStr(char * c, char * tips);
// ��������
void inputNum(int * n, char * tips);
// ¼�뺯�� 
void entering();
// ��ѯ���� 
void query();
// ��������
void export();
// ����ַ��� 
void  outputStr(char * c, char * tips);
// ������� 
void  outputNum(int n, char * tips);
// д���ַ�����Ϣ
void  exportStr(FILE * f, char * c, char * tips);
// ���������Ϣ 
void  exportNum(FILE * f, int n, char * tips);
void activity();
void signin();
int chackbase();
void entering_grade();
void query_grade();
void export_grade();



int main()//���˵��������޸ģ�ֻ���˳��͵�¼����
{
	system("color F0");
	system("mode con cols=65 lines=20");//�ı���
	welcome();
	cleardevice();
	//system("slc");
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop) {
		printf("\n======== The management system for student organizations ========\n");
		printf("\n        0:Sign out\n \t1:Log in and register \n");
		printf("\nPlease enter your choice:");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ��¼ 
			menu2();
			break;
		default: break;
		}
	}
}


void welcome()//�˵�
{
	initgraph(323, 202);
	IMAGE img;	//׼��ͼƬ

	loadimage(&img, "D:\\0��Ҫ���½��ļ���\\2018-2019��ѧ��\\C���԰�\\20190704-4\\����.jpg");
	//����ͼƬ  L"����.jpg"��ͼƬ�����·��,Ҳ����ʹ�þ���·��

	putimage(0, 0, &img);
	//��ָ��λ����ͼ  ǰ���(0,0)������  �����&img��Ҫ����ͼƬ
	_getch();

	closegraph();

}

void menu_main()//����������֮��ѡ����ѧ������֯�߻��ǿ�����ģʽ
{
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n===================== The management system for student organizations =====================\n");
		printf("\n0:Sign out \n\t1:Student Version \n\t2:Organizer Version \n\t3:Staff version\n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ¼����Ϣ 
			entering();
			break;
		case 2: // ��ѯ
			query();
			break;
		case 3: // ���� 
			export();
			break;
		default: break;
		}
		printf("\n \
Thank you for usage,the system has exited\n");
		system("cls");
	}
}

void menu_student()//ѧ��ģʽ�������һ���ύ������Ϣ�Ͳ�ѯ�ɼ�
{
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n===================== Student Version =====================\n");
		printf("\n0:Sign out \n\t1:Find Activity \n\t2:Enter registration information \n\t3:Find Grade \n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ���һ 
			chackbase();
			break;
		case 2: // ¼�������Ϣ
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

void menu_organizer()//��֯��ģʽ����¼��ɼ�������ѧ��������Ϣ�ͷ����ɼ�
{
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n===================== Organizer Version =====================\n");
		printf("\n0:Sign out \n\t1:Activity \n\t2:Find Application \n\t3:Publish Grade \n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ¼�� 
			activity();
			break;
		case 2: // ��ѯ������Ϣ
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

void menu_staff()//������ģʽ��������֮ǰ�Ĳ˵���ɾ���˵�¼��ע���ǿ�
{
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n===================== Organizer Version =====================\n");
		printf("\n        0:Sign out\n \t1:Activity registration \n\t2:Activity Release \n\t3:Export Grade \n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ���˵�1 
			menu1();
			break;
		case 2: // ���˵�2
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
	int op; // ������ʽ 
	int loop = 1; // �Ƿ�ѭ��
	while (loop)
	{
		system("cls");
		printf("\n===================== Activity Registration System =====================\n");
		printf("\n0:Sign out \n\t1:Enter registration information \n\t2:Enquiry for registration information \n\t3:Export registration information\n");
		printf("\nPlease enter your choice��");
		scanf_s("%d", &op);
		getchar();
		switch (op)
		{
		case 0: // �˳� 
			loop = 0;
			break;
		case 1: // ¼����Ϣ 
			entering();
			break;
		case 2: // ��ѯ
			query();
			break;
		case 3: // ���� 
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
	Display();//��ʾ�˵�������ע�᣻����¼
	cin.get();
	//return 0;
}
void Register()//ע��
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);//��ע���ID��code���浽web1.txt�ļ�����
	if (!outFile.is_open())//���û�гɹ����ļ�
	{
		cout << "���ź������Ӳ��Ϸ�����";
		cout << "�������";
		cin.get();
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	cout << "Please Enter members name: ";
	cin.get();//�Ե����ַ�
	getline(cin, name);
	//ռλ������������û����������Ȼ�̫��

	outFile << name << endl;//��¼ע������ϵ�web1.txt�ļ���

	cout << "Please Enter members code: ";
	getline(cin, code);
	//ռλ��������������볬�����Ȼ�̫��

	outFile << code << endl;//��¼ע������ϵ�web1.txt�ļ���
	cout << "ע��ɹ���";
	outFile.close();
	Display();
}
void Enter()//��¼
{
	cin.get();
	ifstream inFile;//����ifstream����
	inFile.open("web1.txt");//��ȡweb1.txt�ļ��е�ע������
	if (!inFile.is_open())//����ļ�û�гɹ���
	{
		cout << "���ź������Ӳ��Ϸ�����";
		exit(EXIT_FAILURE);
	}
	string name;
	string code;
	string temp;

	cout << "Please Enter members name: ";
	getline(cin, name);

	while (getline(inFile, temp))//ƥ���û���
	{
		if (temp == name)//���ƥ���û����ɹ�
		{
			cout << "Please Enter members code: ";//����������
			getline(cin, code);//code
			getline(inFile, temp);//ƥ��code
			if (temp == code)//���������ȷ����¼�ɹ�
			{
				cout << "��¼�ɹ�";
				menu_main(); //���������޸ģ���½�ɹ�֮��ת�������� 
							 //ռλ����¼�ɹ�Ӧ��ת����������
			}
			else
			{
				cout << "�������";
				Display();//���أ�
			}
		}
	}
}

void Display()//�˵�
{
	cout << "1)Register or Enter����������2)Exit\n\nChoice:";
	int choice;//ѡ��˵�
	cin >> choice;

	switch (choice)
	{
	case 1://ע��
		signin();//call function���ú���
		break;
	case 2://�˳�
		exit(EXIT_FAILURE);
	}
}





