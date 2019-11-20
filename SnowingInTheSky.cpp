#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void Init_Map();//map초기화
void Menu();//메뉴함수
void Print();//출력함수
void Face();//정면
void Back();//뒷면
void Up();//상단
void Right();//오른쪽
void Left();//왼쪽
void make();//눈 생성 함수
void down();//눈 내리기 함수
void Init_arr();//각 배열 초기화

int map[10][10][10];
int face[10][10];
int right[10][10];
int left[10][10];
int back[10][10];
int up[10][10];
double q, result;//q 시간 입력
int w;//w 간격입력
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
	printf("--------------사용법------------\n");
	printf("--------------------------------\n");
	printf("방향키 입력 \n←:왼쪽\n→:오른쪽\n↑:뒷면\n↓:정면\n");

	printf("게임 지속 시간 입력(초 단위) : ");
	scanf("%lf", &q);
	printf("눈 내리는 간격 입력(0.x초로 x값입력) (3~10): ");
	scanf("%d", &w);
	while (!(w >= 3 && w <= 10)) {
		printf("눈 내리는 간격 입력(0.x초로 x값입력) (3~10): ");
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
			printf("실행 시간 : %.0f초\n", result);
		}    
		while(ch!=32) {
			ch = getch();
			system("cls");
			Print();
		}
		ch = 0;
		result = 0;
		Init_Map();
		printf("게임 지속 시간 입력(초 단위) : ");
		scanf("%lf", &q);
		printf("눈 내리는 간격 입력(0.x초로 x값입력) (3~10): ");
		scanf("%d", &w); 
		while (!(w >= 3 && w <= 10)) {
			printf("눈 내리는 간격 입력(0.x초로 x값입력) (3~10): ");
			scanf("%d", &w);
		}
	}
}
void Print() {
	printf("상단\n");
	Up();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (up[i][j] == 3) printf("○");
			else printf("■");
		}
		printf("\n");
	}
	printf("\n");
	if (ch == 80) {
		printf("정면\n");
		Face();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (face[i][j] == 3) printf("◇");
				else printf("■");
			}
			printf("\n");
		}
	}
	else if (ch == 77) {
		printf("오른쪽\n");
		Right();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (right[i][j] == 3) printf("★");
				else printf("■");
			}
			printf("\n");
		}
	}
	else if (ch == 75) {
		printf("왼쪽\n");
		Left();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (left[i][j] == 3) printf("☆");
				else printf("■");//0,1,2
			}
			printf("\n");
		}
	}
	else if (ch == 72) {
		printf("뒷면\n");
		Back();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (back[i][j] == 3) printf("◎");
				else printf("■");//0,1,2
			}

			printf("\n");
		}
	}
	if (ch == 32) {
		system("cls");
		result = q + 1;
	}//스페이스
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