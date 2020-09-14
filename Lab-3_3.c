#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

  /***************************************
 / return 1 --- математична помилка      /
/				при обчисленні			/
***************************************/

int x = 0;
int y = 0;
double f = 0;

int scanf_check_int (char printf_x);

int chcp, chcpOut;
void set_chcp(); // Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми


int main(void){
set_chcp();

  /*---------------------------------------------------------------------------------------------------*/
 /*---------------------------------| Введення та перевірка x і y| ----------------------------------*/
/*---------------------------------------------------------------------------------------------------*/
	printf("\r\nДля обчислення введіть значення \"x\" та \"y\" \r\n");
		x = scanf_check_int('x');
		y = scanf_check_int('y');

  /*---------------------------------------------------------------------------------------------------*/
 /*---------------------| Перевірка чи можливо обчислити введені значення|----------------------------*/
/*---------------------------------------------------------------------------------------------------*/

	if (x*y < 1)
	{
		printf("\r\n Для заданих значень \"x\" та \"y\" у обчислюваному виразі виконується:\r\n Логарифмування числа, меншого за нуль\r\n");
		reset_chcp();
		return 1;

	} else  if (1+pow(x,2)+pow(y,2) == 0)
			{
				printf("\r\n Для заданих значень \"x\" та \"y\" у обчислюваному виразі виконується:\r\n Ділення на 0\r\n");
				reset_chcp();
				return 1;
			}


  /*---------------------------------------------------------------------------------------------------*/
 /*-------------------------| Обчислення та вивід на екран результату|--------------------------------*/
/*---------------------------------------------------------------------------------------------------*/


	f = (pow(x,2)+log2(x*y)-pow(y,2))/(1+pow(x,2)+pow(y,2));

	printf("\r\n*************************");
	printf("\r\nВведенні дані:\r\n\n");
	printf("\tx = %d\r\n", x);
	printf("\ty = %d\r\n", y);
	printf("\r\nВідповідь: f = %.3g", f);
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
