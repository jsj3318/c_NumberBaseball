#include <stdio.h>				//c헤더
#include <stdlib.h>				//랜덤값을 위한 헤더
#include <windows.h>			//랜덤값을 위한 헤더
#pragma warning(disable:4996)	//scanf함수 에러 무시

void main() {
	//기회, 정답, 입력 받는수, 스트라이크, 볼, 게임오버 여부 변수 만들기
	int life, ans1, ans2, ans3, ans4, num, num1, num2, num3, num4;
	int strike, ball;
	bool gameover;

	//랜덤값 초기화
	srand(GetTickCount());

	//전체 게임 반복
	while (true) {

		//게임오버 변수 초기화
		gameover = false;

		//기회 횟수 입력받기
		printf("기회횟수를 입력하세요(1~100): ");
		scanf("%d", &life);
		while (life < 1 || life >100) {		//범위 밖의 수 입력 시 다시 입력받기
			printf("1부터 100까지의 수를 입력하세요: ");
			scanf("%d", &life);
		}

		//랜덤답 만들기 (숫자 중복 체크)
		ans1 = rand() % 10;
		do { ans2 = rand() % 10; } while (ans1 == ans2);
		do { ans3 = rand() % 10; } while (ans1 == ans3 || ans2 == ans3);
		do { ans4 = rand() % 10; } while (ans1 == ans4 || ans2 == ans4 || ans3 == ans4);

		//답 맞추는 곳
		while (life) {

			//수 입력받기
			printf("\n남은 기회:%d\n네수를 입력하세요(세자리 입력 시 첫번째 0): ", life);
			while (true) {
				scanf("%d", &num);
				if (num > 9999) printf("네수를 입력하세요: ");	//다섯자리이상 입력 시 다시
				else if (num > 99) {		//입력 받은 네수 자릿수마다 따로따로 저장
					num1 = num / 1000;
					num2 = num % 1000 / 100;
					num3 = num % 100 / 10;
					num4 = num % 10;

					//입력 받은 수 중복확인
					if (num1 == num2 || num1 == num3 || num1 == num4 || num2 == num3 ||
						num2 == num4 || num3 == num4) {
						printf("중복되는 수가 있으니 다시 입력: ");
						continue;
					}
					else break;
				}
				else printf("네수를 입력하세요: ");	//세자리이하 입력 시 다시
			}

			//볼, 스트라이크 변수 초기화
			ball = 0, strike = 0;

			//답과 입력받은 수 비교해서 볼, 스트라이크 계산
			if (num1 == ans1)	strike++;
			else if (num1 == ans2 || num1 == ans3 || num1 == ans4)	ball++;
			if (num2 == ans2)	strike++;
			else if (num2 == ans1 || num2 == ans3 || num2 == ans4)	ball++;
			if (num3 == ans3)	strike++;
			else if (num3 == ans1 || num3 == ans2 || num3 == ans4)	ball++;
			if (num4 == ans4)	strike++;
			else if (num4 == ans1 || num4 == ans2 || num4 == ans3)	ball++;

			//정답확인, 기회차감후 게임오버 확인
			if (strike == 4) gameover = true;
			if (!--life) gameover = true;

			//스트라이크, 볼, 아웃 출력
			if (strike && strike != 4)	printf("%d스트라이크 ", strike);
			if (ball)					printf("%d볼 ", ball);
			if (!strike && !ball)		printf("아웃!");
			printf("\n");

			//게임 끝났을 경우 다시시작 확인
			if (gameover) {
				if (strike == 4)	printf("\n정답!!\n\n");
				else				printf("\n게임오버!!  (정답:%d%d%d%d)\n\n", ans1, ans2, ans3, ans4);
				
				printf("(다시시작:1 종료:2) 입력: ");
				int a;	//임시로 쓸 변수
				while (true) {
					scanf("%d", &a);	//숫자 입력받기
					if (a == 1) {		//1이면 지우고 다시시작
						system("cls");	//콘솔 싹 지우는 함수
						break;
					}
					else if (a == 2) return;	//2이면 프로그램 종료
					else printf("1 또는 2 입력: ");	//1,2가 아니면 다시
				}
			}
			if (gameover)	break;
		}
	}
}