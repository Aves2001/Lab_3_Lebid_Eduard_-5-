#include "func.h"

char n = 0;
char errors = 0;

void Error_p (); // Повідомляє користувачеві про те що він допустив помилку при введенні даних

int main(void) {
set_chcp();

do{
errors = 0;

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
		default: Error_p (); errors = 1; break;
	}

}while(errors == 1);

	reset_chcp();
	return 0;
}


void Error_p ()
{
	printf("\r\nНеправильне введення \"n\"\r\nВи можете ввести лише числа від 1, до 7.\r\n");
}
