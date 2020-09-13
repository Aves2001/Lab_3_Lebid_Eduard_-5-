#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>


  /***************************************
 / return 1 --- помилка при введенні "а" /
/ return 2 --- помилка при введенні "с" /
***************************************/

int a = 0;
float b = 0;
float c = 0;

float tmp_a = 0;
char tmp_c = 0;

int chcp, chcpOut;
void set_chcp();	// Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми


int main(void) {
set_chcp();

printf("\r\n\nВведіть ціле число а\r\na = ");
scanf ("%f",&tmp_a);
	a = tmp_a;	// Збереження цілої частини від введеної "а"

//printf("----------------------| a = %d | tmp_a = %f |----------------------\r\n", a, tmp_a);	//debug

if (a != 2 && a != 4 && a != 6)
{
	printf("\r\n\nНеможливо обчислити!\r\n\"а\" може мати лише наступні значення: 2, 4, 6.\r\n");
	reset_chcp();
	getch();
	return 1;
}

if(tmp_a - a != 0)
{
	printf("\r\n\nВведіть будьласка \"ЦІЛЕ\" число \"а\"\r\n");
	reset_chcp();
	getch();
	return 1;
}

printf("\r\nВведіть дійсне число c\r\nc = ");
tmp_c = scanf ("%f",&c);

 
//printf("\r\n----------------------| c = %f | tmp_c = %d |----------------------", c, tmp_c);	//debug

if (tmp_c == 0)
{
	system("cls"); // очистка екрана
	printf("\r\n\nНеможливо обчислити!\r\n\"а\" має бути числом\n");
	reset_chcp();
	getch();
	return 1;
}

if (a == 2 && a*c == 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nВиконується ділення на 0\r\n");
	reset_chcp();
	getch();
	return 2;
}

if (a == 4 && (a*c)-(2*a) < 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nПід квадратним коренем відємне число.\r\n");
	reset_chcp();
	getch();
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