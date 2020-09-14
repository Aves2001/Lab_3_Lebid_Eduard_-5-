#include <stdio.h>
#include <conio.h>
#include <windows.h>

double x = 0;
double y = 0;

double scanf_check_double (char printf_x);

int chcp, chcpOut;
void set_chcp();	// Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми

int main(void) {
set_chcp();

printf("\r\nВведіть координати точкок:\r\n");
	x = scanf_check_double ('x');
	y = scanf_check_double ('y');

if ((x>0) && (y>0)) printf("\r\n 1 квадрант\n");
	else if ((x<0) && (y>0)) printf("\r\n 2 квадрант\n");
		else if ((x<0) && (y<0)) printf("\r\n 3 квадрант\n");
			else if ((x>0) && (y<0)) printf("\r\n 4 квадрант\n");
				else if (x==0 && y==0) printf("\r\n Точка на початку координат\n");
					else if ((x==0) && (y>0) || (y<0)) printf("\r\n Точка на осі Y\n");
						else if ((x<0) || (x>0) && (y==0)) printf("\r\n Точка на осі X\n");

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