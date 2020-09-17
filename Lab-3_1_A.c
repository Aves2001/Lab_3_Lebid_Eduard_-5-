#include "func.h"

int a = 0;
double b = 0;
double c = 0;
char errors = 0;

int main(void) {
set_chcp();

do{
errors = 0;

printf("\r\n\nВведіть ціле число а\r\n");
	a = scanf_check_int ('a');

if (a != 2 && a != 4 && a != 6)
{
	printf("\r\n\nНеможливо обчислити!\r\n\"а\" може мати лише наступні значення: 2, 4, 6.\r\n");
	errors = 1;
	continue;
}

printf("\r\nВведіть дійсне число c\r\n");
	c = scanf_check_double ('c');

if (a == 2 && a*c == 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nВиконується ділення на 0\r\n");
	errors = 1;
	continue;
}

if (a == 4 && (a*c)-(2*a) < 0)
{
	printf("\r\n\nПомилка при введенні дійсного числа \"с\" \r\nПід квадратним коренем відємне число.\r\n");
	errors = 1;
	continue;
}

}while(errors == 1);

if (a == 2) b = (pow(a,2)-(4*c))/(a*c);
if (a == 4) b = sqrt((a*c)-(2*a));
if (a == 6) b = pow(c,2)-(2*a);

printf("\r\n\n*************************");
printf("\r\nВведенні дані:\r\n\n");
printf("\ta = %d\r\n", a);
printf("\tc = %g\r\n", c);
printf("\r\nВідповідь: b = %.2lf", b);
printf("\r\n*************************\r\n");

	reset_chcp();
	return 0;
}
