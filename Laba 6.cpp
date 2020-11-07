#include <locale.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int **mas;
	int i, j, n, m;
	srand(time(NULL));
	printf("Введите количество строк и столбцов\n");
	scanf_s("%d%d", &n, &m);
	mas = (int**)calloc(n, sizeof(int*));                  
	for (i = 0; i < n; i++)
	{
		mas[i] = (int*)calloc(m, sizeof(int));            // создаем динамический массив через двойной указатель
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 101 - 50;               // заполняем рандомными числами, чтобы не тратить силы для записи каждого числа
		}
	}
	printf("\nИсходный массив \n");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)                         // выводим зарандомленный массив
		{
			printf("%5d", mas[i][j]);
		}
	}
	printf("\n");

	int t, kk, temp;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n - 1; ++i)
		{
			if (mas[i][j] < 0)
			{
				t = i;
				kk = mas[i][j];
				for (temp = i + 1; temp < n; ++temp)        // сортируем "через отбор" + добавляем 1 условие
				{
					if (mas[temp][j] < kk)
					{
						t = temp;
						kk = mas[temp][j];
					}
				}
				mas[t][j] = mas[i][j];
				mas[i][j] = kk;
				
			}
		}
	}

	printf("\nОтсортированный массив \n");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)                   // выводим уже отсортированный массив
		{
			printf("%5d", mas[i][j]);
		}
	}
	printf("\n");
	return 0;
}