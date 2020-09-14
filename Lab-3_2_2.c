#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <limits.h>

char n = 0;

int chcp, chcpOut;
void set_chcp(); // Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми

void Error_p (); // Повідомляє користувачеві про те що він допустив помилку при введенні даних
int scanf_check_int (char printf_x);

int main(void) {
set_chcp();

printf ("\r\n\nВведіть порядковий номер дня тижня (n) для отримання назви дня:\r\n");
	n = scanf_check_int('n');

	switch (n)
	{
		case 1: printf("\r\nПонелілок\r\n"); break;
		case 2: printf("\r\nВівторок\r\n"); break;
		case 3: printf("\r\nСереда\r\n"); break;
		case 4: printf("\r\nЧервер\r\n"); break;
		case 5: printf("\r\nП'ятниця\r\n"); break;
		case 6: printf("\r\nСубота\r\n"); break;
		case 7: printf("\r\nНеділя\r\n"); break;
		default: Error_p ();
	}

	reset_chcp();
	return 0;
}

void reset_chcp()
{
	// Повернення значення chcp яке було до запуску програми
	SetConsoleCP(chcp);
	SetConsoleOutputCP(chcpOut);
	getch();
}

void set_chcp()
{
// Значення chcp у системі
	chcp = GetConsoleCP();
	chcpOut = GetConsoleOutputCP();

//------------UTF-8--------------
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
//-------------------------------
}

void Error_p ()
{
	printf("\r\nНеправильне введення \"n\"\r\nВи можете ввести лише числа від 1, до 7.\r\n");
}

int scanf_check_int (char printf_x)
{

double check_x = 0;
unsigned char tmp_x1 = 0;
unsigned char tmp_x = 0;
int x = 0;
unsigned char test = 0;
unsigned char test2 = 0;

do {

test2 = 0;

do {

		printf("\r\n%c = ", printf_x);
		tmp_x1 = scanf ("%lf", &check_x);
		// printf("-----| scanf_check_int |-------| check_x = %f |--------------\r\n", check_x);	//debug
		// printf("-----| scanf_check_int |-------| tmp_x1 = %d |--------------\r\n", tmp_x1);	//debug

		tmp_x = getchar ();
		// printf("-----| scanf_check_int |-------| tmp_x = %d [%c] |---\r\n", tmp_x, tmp_x);	//debug

		x = check_x; // Збереження цілої частини числа х
		// printf("-----| scanf_check_int |-------| x = %d |-------\r\n", x);	//debug

			if (tmp_x != 10 || tmp_x1 == 0)
			{
				printf("\r\n\nУвага! Ви ввели неправильне значення \"%c\"\r\n", printf_x);
				getchar ();
				break;

			} else  if (check_x < INT_MIN || check_x > INT_MAX)
					{
						printf("\r\n\nУпс! Програма не розрахована на обчислення таких великих чисел\r\n");
						break;

					}else  if(check_x - x != 0)
							{
								printf("\r\n\nВведіть будьласка \"ЦІЛЕ\" число \"%c\"\r\n", printf_x);
								break;

							}else test = 1;
test2 = 1;
} while (test != 1);
} while (test2 != 1);

// printf("-----| scanf_check_int |-------| x = %d |---------------------\r\n", x);	//debug

return x;
}
