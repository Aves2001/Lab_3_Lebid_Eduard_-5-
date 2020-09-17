#include "func.h"

double x = 0;
double y = 0;

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
