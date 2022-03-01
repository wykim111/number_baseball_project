#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//현재 할당된 사이즈만큼 탐색
//같은 숫자면 1 리턴
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
		printf("%c ", arr[i]);//컴퓨터가 설정한 수
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
		//중복되면 스킵하고 다시 랜덤숫자 할당
		if (check_same(comp, i, comp[i]) == 1)
		{
			i = i - 1;// for문의 증감식 i++ 때문에 여기서 i-1로 감소히여 다시 할당하도록 함
			continue;
		}

	}
	comp[i] = '\0';
}
//input
//같은 데이터가 들어오면 다시 입력
int input(char* user)
{
	int strLen = 0;
	int i = 0,j=0;

	printf("숫자 입력(3자리까지 붙여서 입력) ex.123\n");
	
	memset(user, 0, sizeof(user));
	scanf("%s", user);

	strLen = strlen(user);
	if (strLen != 3)
	{
		printf("3자리까지 입력해주세요 ex) 123");
		
	}

	int sameflag = 0;
	for (i = 0; i < 3; i++)
	{
		//중복 체크
		for (j = i + 1; j < 3; j++)
		{
			if (user[i] == user[j])
			{
				sameflag = 1; //입력된 수 중에서 중복된 경우
				break;
			}
		}
		if (sameflag == 1)
			break;
	}

	if (sameflag == 1)//다시 입력을 받음
	{
		printf("중복된 숫자가 있습니다.\n(0~9)사이에 수를 겹치지 않게 입력해주세요\n");
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

		//printf("입력 숫자 : %c %c %c\n", user[0], user[1], user[2]);
		int match_flag = 0;//이게 없으면 user의 데이터 수만큼 out카운트가 늘어나버림,computer의 데이터가 user 데이터에 모두 없으면 flag = 1로 설정
		for (i = 0; i < 3; i++) // computer
		{
			match_flag = 0;
			for (int j = 0; j < 3; j++) // user
			{
				//숫자 일치
				if (comp[i] == user[j])
				{
					if (i == j)// 자릿수 일치
					{
						strike++;
					}
					else//자릿수 다름
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
			printf("시도횟수 = %d\n", cnt);
			printf("맞췄습니다!\n");
			break;
		}
		else
		{
			printf("strike(%d) ball(%d)  out(%d)\n", strike, ball, out);
			printf("다시 시도해주세요\n");
			cnt++;
		}


	}


	return 0;
}