#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

    /***************************************
   / return 1 --- помилка при введенні "x" /
  / return 2 --- помилка при введенні "y" /
 / return 3 --- математична помилка      /
/				при обчисленні			/
***************************************/

int x = 0;
int y = 0;
double f = 0;
float check_x = 0;
float check_y = 0;

char tmp_x = 0;   // Перевіряє чи користувач вводить ще щось разом із цифрою
			   	 //  Наприклад х = 2d || 3 d || d23d2d || 2-3 || 2*3
char tmp_y = 0;	// Аналогічно tmp_x


char tmp_x1 = 0;   // Перевіряє на відсутність цифр
				  //  Наприклад x = + || - || / || . || просто буква
char tmp_y1 = 0; // Аналогічно tmp_x1


int chcp, chcpOut;
void set_chcp(); // Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми


int main(void){
set_chcp();

  /*---------------------------------------------------------------------------------------------------*/
 /*---------------------------------| Введення та перевірка x і y| ----------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

	printf ("\r\nx = ");

	tmp_x1 = scanf ("%f", &check_x);
	tmp_x = getchar ();
	x = check_x; // Збереження цілої частини числа х

// printf("----------------------| x = %d | tmp_x1 = %d |----------------------\r\n", x, tmp_x1);	//debug
// printf("----------------------| x = %d | tmp_x = %d |----------------------\r\n", x, tmp_x);	//debug

	if (tmp_x != 10 || tmp_x1 == 0)
	{
		printf("\r\nУвага! Ви ввели неправильне значення \"x\"\r\n");
		reset_chcp();
		getch();
		return 1;

	} else  if(check_x - x != 0)
			{
				printf("\r\nВведіть будьласка \"ЦІЛЕ\" число \"x\"\r\n");
				reset_chcp();
				getch();
				return 1;
			}

	printf ("y = ");
	tmp_y1 = scanf ("%f", &check_y);
	tmp_y = getchar ();
	y = check_y;

// printf("----------------------| y = %d | tmp_y1 = %d |----------------------\r\n", y, tmp_y1);	//debug
// printf("----------------------| y = %d | tmp_y = %d |----------------------\r\n", y, tmp_y);	//debug

	if (tmp_y != 10 || tmp_y1 == 0)
	{
		printf("\r\nУвага! Ви ввели неправильне значення \"y\"\r\n");
		reset_chcp();
		getch();
		return 2;
	} else	if(check_y - y != 0)
			{
				printf("\r\nВведіть будьласка \"ЦІЛЕ\" число \"y\"\r\n");
				reset_chcp();
				getch();
				return 2;
			}


  /*---------------------------------------------------------------------------------------------------*/
 /*---------------------| Перевірка чи можливо обчислити введені значення|----------------------------*/
/*---------------------------------------------------------------------------------------------------*/

	if (x*y < 1)
	{
		printf("\r\n Для заданих значень \"x\" та \"y\" у обчислюваному виразі виконується:\r\n Логарифмування числа, меншого за нуль\r\n");
		reset_chcp();
		getch();
		return 3;

	} else  if (1+pow(x,2)+pow(y,2) == 0)
			{
				printf("\r\n Для заданих значень \"x\" та \"y\" у обчислюваному виразі виконується:\r\n Ділення на 0\r\n");
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