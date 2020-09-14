#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <limits.h>


  /***************************************
 / return 1 --- помилка при введенні "а" /
/ return 2 --- помилка при введенні "с" /
***************************************/

int a = 0;
double b = 0;
double c = 0;

int chcp, chcpOut;
void set_chcp();	// Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми

int scanf_check_int (char printf_x);
double scanf_check_double (char printf_x);

int main(void) {
set_chcp();

printf("\r\n\nВведіть ціле число а\r\n");
	a = scanf_check_int ('a');

if (a != 2 && a != 4 && a != 6)
{
	printf("\r\n\nНеможливо обчислити!\r\n\"а\" може мати лише наступні значення: 2, 4, 6.\r\n");
	reset_chcp();
	return 1;
}

printf("\r\nВведіть дійсне число c\r\n");
	c = scanf_check_double ('c');

if (a == 2 && a*c == 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nВиконується ділення на 0\r\n");
	reset_chcp();
	return 2;
}

if (a == 4 && (a*c)-(2*a) < 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nПід квадратним коренем відємне число.\r\n");
	reset_chcp();
	return 2;
}

if (a == 2) b = (pow(a,2)-(4*c))/(a*c);
if (a == 4) b = sqrt((a*c)-(2*a));
if (a == 6) b = pow(c,2)-(2*a);

printf("\r\n\n*************************");
printf("\r\nВведенні дані:\r\n\n");
printf("\ta = %d\r\n", a);
printf("\tc = %g\r\n", c);
printf("\r\nВідповідь: b = %.3g", b);
printf("\r\n*************************\r\n");

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

//-----------------------------------------------------------------------
double scanf_check_double (char printf_x)
{

double check_x = 0;
unsigned char tmp_x1 = 0;
unsigned char tmp_x = 0;
unsigned char test = 0;
unsigned char test2 = 0;

do {

test2 = 0;

do {

		printf("\r\n%c = ", printf_x);
		tmp_x1 = scanf ("%lf", &check_x);
		// printf("-----| scanf_check_double |-------| check_x = %f |--------------\r\n", check_x);	//debug
		// printf("-----| scanf_check_double |-------| tmp_x1 = %d |--------------\r\n", tmp_x1);	//debug

		tmp_x = getchar ();
		// printf("-----| scanf_check_double |-------| tmp_x = %d [%c] |---\r\n", tmp_x, tmp_x);	//debug


			if (tmp_x != 10 || tmp_x1 == 0)
			{
				printf("\r\n\nУвага! Ви ввели неправильне значення \"%c\"\r\n", printf_x);
				getchar ();
				break;

			} else  if (check_x < (-88888888888888800) || check_x > 88888888888888800)
					{
						printf("\r\n\nУпс! Програма не розрахована на обчислення таких великих чисел\r\n");
						break;

					} else test = 1;

test2 = 1;
} while (test != 1);
} while (test2 != 1);

// printf("-----| scanf_check_double |-------| x = %d |---------------------\r\n", x);	//debug

return check_x;
}