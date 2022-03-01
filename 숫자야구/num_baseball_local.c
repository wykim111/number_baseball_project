#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//���� �Ҵ�� �����ŭ Ž��
//���� ���ڸ� 1 ����
int check_same(char*arr, int size, char n)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			return 1;
		}
	}

	return 0;
}


void debug_comp(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c ", arr[i]);//��ǻ�Ͱ� ������ ��
	}
	printf("\n");
}



void random_com(char* comp)
{
	int i = 0;
	memset(comp, 0, sizeof(comp));

	for (i = 0; i < 3; i++)
	{
		comp[i] = (rand() % 10) + '0';
		//�ߺ��Ǹ� ��ŵ�ϰ� �ٽ� �������� �Ҵ�
		if (check_same(comp, i, comp[i]) == 1)
		{
			i = i - 1;// for���� ������ i++ ������ ���⼭ i-1�� �������� �ٽ� �Ҵ��ϵ��� ��
			continue;
		}

	}
	comp[i] = '\0';
}
//input
//���� �����Ͱ� ������ �ٽ� �Է�
int input(char* user)
{
	int strLen = 0;
	int i = 0,j=0;

	printf("���� �Է�(3�ڸ����� �ٿ��� �Է�) ex.123\n");
	
	memset(user, 0, sizeof(user));
	scanf("%s", user);

	strLen = strlen(user);
	if (strLen != 3)
	{
		printf("3�ڸ����� �Է����ּ��� ex) 123");
		
	}

	int sameflag = 0;
	for (i = 0; i < 3; i++)
	{
		//�ߺ� üũ
		for (j = i + 1; j < 3; j++)
		{
			if (user[i] == user[j])
			{
				sameflag = 1; //�Էµ� �� �߿��� �ߺ��� ���
				break;
			}
		}
		if (sameflag == 1)
			break;
	}

	if (sameflag == 1)//�ٽ� �Է��� ����
	{
		printf("�ߺ��� ���ڰ� �ֽ��ϴ�.\n(0~9)���̿� ���� ��ġ�� �ʰ� �Է����ּ���\n");
		return 0;
	}

	return 1;
}
int main()
{
	char comp[4];
	char user[4];
	int cnt = 1;
	int i = 0, j = 0;
	int com_size = 0;
	srand((unsigned)time(NULL));

	memset(comp, 0, sizeof(comp));
	memset(user, 0, sizeof(user));

	random_com(comp);

	com_size = strlen(comp);
#if 1
	debug_comp(comp, com_size);
#endif

	while (1)
	{
		int strike = 0, ball = 0, out = 0;

		//input
		if (input(user) == FALSE)
		{
			continue;
		}

		//printf("�Է� ���� : %c %c %c\n", user[0], user[1], user[2]);
		int match_flag = 0;//�̰� ������ user�� ������ ����ŭ outī��Ʈ�� �þ����,computer�� �����Ͱ� user �����Ϳ� ��� ������ flag = 1�� ����
		for (i = 0; i < 3; i++) // computer
		{
			match_flag = 0;
			for (int j = 0; j < 3; j++) // user
			{
				//���� ��ġ
				if (comp[i] == user[j])
				{
					if (i == j)// �ڸ��� ��ġ
					{
						strike++;
					}
					else//�ڸ��� �ٸ�
					{
						ball++;
					}
					match_flag = 1;
					break;
				}

			}
			if (strike == 3)
			{
				break;
			}

			if (match_flag == 0)
			{
				out++;
			}


		}


		if (strike == 3)
		{
			printf("�õ�Ƚ�� = %d\n", cnt);
			printf("������ϴ�!\n");
			break;
		}
		else
		{
			printf("strike(%d) ball(%d)  out(%d)\n", strike, ball, out);
			printf("�ٽ� �õ����ּ���\n");
			cnt++;
		}


	}


	return 0;
}