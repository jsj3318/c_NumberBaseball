#include <stdio.h>				//c���
#include <stdlib.h>				//�������� ���� ���
#include <windows.h>			//�������� ���� ���
#pragma warning(disable:4996)	//scanf�Լ� ���� ����

void main() {
	//��ȸ, ����, �Է� �޴¼�, ��Ʈ����ũ, ��, ���ӿ��� ���� ���� �����
	int life, ans1, ans2, ans3, ans4, num, num1, num2, num3, num4;
	int strike, ball;
	bool gameover;

	//������ �ʱ�ȭ
	srand(GetTickCount());

	//��ü ���� �ݺ�
	while (true) {

		//���ӿ��� ���� �ʱ�ȭ
		gameover = false;

		//��ȸ Ƚ�� �Է¹ޱ�
		printf("��ȸȽ���� �Է��ϼ���(1~100): ");
		scanf("%d", &life);
		while (life < 1 || life >100) {		//���� ���� �� �Է� �� �ٽ� �Է¹ޱ�
			printf("1���� 100������ ���� �Է��ϼ���: ");
			scanf("%d", &life);
		}

		//������ ����� (���� �ߺ� üũ)
		ans1 = rand() % 10;
		do { ans2 = rand() % 10; } while (ans1 == ans2);
		do { ans3 = rand() % 10; } while (ans1 == ans3 || ans2 == ans3);
		do { ans4 = rand() % 10; } while (ans1 == ans4 || ans2 == ans4 || ans3 == ans4);

		//�� ���ߴ� ��
		while (life) {

			//�� �Է¹ޱ�
			printf("\n���� ��ȸ:%d\n�׼��� �Է��ϼ���(���ڸ� �Է� �� ù��° 0): ", life);
			while (true) {
				scanf("%d", &num);
				if (num > 9999) printf("�׼��� �Է��ϼ���: ");	//�ټ��ڸ��̻� �Է� �� �ٽ�
				else if (num > 99) {		//�Է� ���� �׼� �ڸ������� ���ε��� ����
					num1 = num / 1000;
					num2 = num % 1000 / 100;
					num3 = num % 100 / 10;
					num4 = num % 10;

					//�Է� ���� �� �ߺ�Ȯ��
					if (num1 == num2 || num1 == num3 || num1 == num4 || num2 == num3 ||
						num2 == num4 || num3 == num4) {
						printf("�ߺ��Ǵ� ���� ������ �ٽ� �Է�: ");
						continue;
					}
					else break;
				}
				else printf("�׼��� �Է��ϼ���: ");	//���ڸ����� �Է� �� �ٽ�
			}

			//��, ��Ʈ����ũ ���� �ʱ�ȭ
			ball = 0, strike = 0;

			//��� �Է¹��� �� ���ؼ� ��, ��Ʈ����ũ ���
			if (num1 == ans1)	strike++;
			else if (num1 == ans2 || num1 == ans3 || num1 == ans4)	ball++;
			if (num2 == ans2)	strike++;
			else if (num2 == ans1 || num2 == ans3 || num2 == ans4)	ball++;
			if (num3 == ans3)	strike++;
			else if (num3 == ans1 || num3 == ans2 || num3 == ans4)	ball++;
			if (num4 == ans4)	strike++;
			else if (num4 == ans1 || num4 == ans2 || num4 == ans3)	ball++;

			//����Ȯ��, ��ȸ������ ���ӿ��� Ȯ��
			if (strike == 4) gameover = true;
			if (!--life) gameover = true;

			//��Ʈ����ũ, ��, �ƿ� ���
			if (strike && strike != 4)	printf("%d��Ʈ����ũ ", strike);
			if (ball)					printf("%d�� ", ball);
			if (!strike && !ball)		printf("�ƿ�!");
			printf("\n");

			//���� ������ ��� �ٽý��� Ȯ��
			if (gameover) {
				if (strike == 4)	printf("\n����!!\n\n");
				else				printf("\n���ӿ���!!  (����:%d%d%d%d)\n\n", ans1, ans2, ans3, ans4);
				
				printf("(�ٽý���:1 ����:2) �Է�: ");
				int a;	//�ӽ÷� �� ����
				while (true) {
					scanf("%d", &a);	//���� �Է¹ޱ�
					if (a == 1) {		//1�̸� ����� �ٽý���
						system("cls");	//�ܼ� �� ����� �Լ�
						break;
					}
					else if (a == 2) return;	//2�̸� ���α׷� ����
					else printf("1 �Ǵ� 2 �Է�: ");	//1,2�� �ƴϸ� �ٽ�
				}
			}
			if (gameover)	break;
		}
	}
}