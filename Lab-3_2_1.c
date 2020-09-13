#include <stdio.h>
#include <conio.h>
#include <windows.h>

  /***************************************
 / return 1 --- помилка при введенні "x" /
/ return 2 --- помилка при введенні "y" /
***************************************/

float x = 0;
float y = 0;

char tmp_x = 0; // Перевіряє чи користувач вводить ще щось разом із цифрою
			   //  Наприклад х = 2d || 3 d || d23d2d || 2-3 || 2*3

char tmp_y = 0; // Аналогічно tmp_x

char tmp_x1 = 0; // Перевіряє на відсутність цифр
				//  Наприклад x = + || - || / || . || просто буква

char tmp_y1 = 0; // Аналогічно tmp_x1

int chcp, chcpOut;
void set_chcp();	// Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми

int main(void) {
set_chcp();

printf("\r\nВведіть координати точкок:\r\n");

printf("\r\nx = ");
	tmp_x1 = scanf ("%f", &x);
	tmp_x = getchar ();

// printf("----------------------| x = %f | tmp_x1 = %d |----------------------\r\n", x, tmp_x1);	//debug
// printf("----------------------| x = %f | tmp_x = %d |----------------------\r\n", x, tmp_x);	//debug

if (tmp_x != 10 || tmp_x1 == 0)
{
	printf("\r\nУвага! Ви ввели неправильне значення \"x\"\r\n");
	reset_chcp();
	getch();
	return 1;
}

printf("y = ");
	tmp_y1 = scanf ("%f",&y);
	tmp_y = getchar ();

// printf("----------------------| x = %f | tmp_y1 = %d |----------------------\r\n", x, tmp_y1);	//debug
// printf("----------------------| y = %f | tmp_y = %d |----------------------\r\n", y, tmp_y);	//debug

if (tmp_y != 10 || tmp_y1 == 0)
{
	printf("\r\nУвага! Ви ввели неправильне значення \"y\"\r\n");
	reset_chcp();
	getch();
	return 2;
}

if ((x>0) && (y>0)) printf("\r\n 1 квадрант\n");
	else if ((x<0) && (y>0)) printf("\r\n 2 квадрант\n");
		else if ((x<0) && (y<0)) printf("\r\n 3 квадрант\n");
			else if ((x>0) && (y<0)) printf("\r\n 4 квадрант\n");
				else if (x==0 && y==0) printf("\r\n Точка на початку координат\n");
					else if ((x==0) && (y>0) || (y<0)) printf("\r\n Точка на осі Y\n");
						else if ((x<0) || (x>0) && (y==0)) printf("\r\n Точка на осі X\n");

	reset_chcp();
	getch();
	return 0;
}

void reset_chcp()
{
	// Повернення значення chcp яке було до запуску програми
	SetConsoleCP(chcp);
	SetConsoleOutputCP(chcpOut);
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