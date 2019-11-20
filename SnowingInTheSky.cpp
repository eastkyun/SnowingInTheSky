#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void Init_Map();//map�ʱ�ȭ
void Menu();//�޴��Լ�
void Print();//����Լ�
void Face();//����
void Back();//�޸�
void Up();//���
void Right();//������
void Left();//����
void make();//�� ���� �Լ�
void down();//�� ������ �Լ�
void Init_arr();//�� �迭 �ʱ�ȭ

int map[10][10][10];
int face[10][10];
int right[10][10];
int left[10][10];
int back[10][10];
int up[10][10];
double q, result;//q �ð� �Է�
int w;//w �����Է�
char ch;
clock_t start, end;
int main() {
	srand(time(NULL));
	Menu();
}
void Init_Map() {
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				map[k][i][j] = 0;
			}
		}
	}
}
void Init_arr() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			face[i][j] = 0;
			up[i][j] = 0;
			left[i][j] = 0;
			right[i][j] = 0;
			back[i][j] = 0;
		}
	}
}
void Menu() {
	printf("--------------------------------\n");
	printf("--------------����------------\n");
	printf("--------------------------------\n");
	printf("����Ű �Է� \n��:����\n��:������\n��:�޸�\n��:����\n");

	printf("���� ���� �ð� �Է�(�� ����) : ");
	scanf("%lf", &q);
	printf("�� ������ ���� �Է�(0.x�ʷ� x���Է�) (3~10): ");
	scanf("%d", &w);
	while (!(w >= 3 && w <= 10)) {
		printf("�� ������ ���� �Է�(0.x�ʷ� x���Է�) (3~10): ");
		scanf("%d", &w);
	}
	result = 0;
	Init_Map(); 
	//make();
	while (1) {
		while (q >= result) {
			start = clock();
			Sleep(w*100);
			system("cls");			
			Print();
			Init_arr();
			down();			
			make();		
			end = clock();
			result = result + (end - start) / (double)1000;
			printf("���� �ð� : %.0f��\n", result);
		}    
		while(ch!=32) {
			ch = getch();
			system("cls");
			Print();
		}
		ch = 0;
		result = 0;
		Init_Map();
		printf("���� ���� �ð� �Է�(�� ����) : ");
		scanf("%lf", &q);
		printf("�� ������ ���� �Է�(0.x�ʷ� x���Է�) (3~10): ");
		scanf("%d", &w); 
		while (!(w >= 3 && w <= 10)) {
			printf("�� ������ ���� �Է�(0.x�ʷ� x���Է�) (3~10): ");
			scanf("%d", &w);
		}
	}
}
void Print() {
	printf("���\n");
	Up();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (up[i][j] == 3) printf("��");
			else printf("��");
		}
		printf("\n");
	}
	printf("\n");
	if (ch == 80) {
		printf("����\n");
		Face();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (face[i][j] == 3) printf("��");
				else printf("��");
			}
			printf("\n");
		}
	}
	else if (ch == 77) {
		printf("������\n");
		Right();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (right[i][j] == 3) printf("��");
				else printf("��");
			}
			printf("\n");
		}
	}
	else if (ch == 75) {
		printf("����\n");
		Left();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (left[i][j] == 3) printf("��");
				else printf("��");//0,1,2
			}
			printf("\n");
		}
	}
	else if (ch == 72) {
		printf("�޸�\n");
		Back();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (back[i][j] == 3) printf("��");
				else printf("��");//0,1,2
			}

			printf("\n");
		}
	}
	if (ch == 32) {
		system("cls");
		result = q + 1;
	}//�����̽�
}
void Face() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (map[k][i][j] == 3) face[i][j] = map[k][i][j];

			}
		}
	}
}
void Back() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (map[k][i][j] == 3) back[i][9 - j] = map[k][i][j];
			}
		}
	}
}
void Up() {
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			for (int i = 0; i < 10; i++) {
				if (map[k][i][j] == 3 ) up[k][j] = map[k][i][j];
			}
		}
	}
}
void Right() {
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[k][i][j] == 3) right[i][k] = map[k][i][j];
			}
		}
	}
}
void Left() {
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[k][i][j] == 3) left[i][9-k] = map[k][i][j];
			}
		}
	}
}

void make() {
	for (int k = 0;k< 10; k++) {
		for (int j = 0; j < 10; j++){
			map[k][0][j] = rand()%20;
		}
	}
}
void down() {
	for (int i = 8; i >= 0; i--){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++) {
				map[k][i][j] = map[k][i - 1][j];
			}
		}
	}
}