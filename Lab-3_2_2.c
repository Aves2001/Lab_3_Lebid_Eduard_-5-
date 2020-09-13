#include <stdio.h>
#include <conio.h>
#include <windows.h>

  /***************************************
 / return 1 --- помилка при введенні "n" /
/ 	Користувач неадекватно ввів дані	/
***************************************/

char n = 0;

char tmp_n = 0; // Перевіряє чи користувач вводить ще щось разом із цифрою
			   //  Наприклад n = 2d || 3 d || d23d2d || 2-3 || 2*3

char tmp_n1 = 0; // Перевіряє на відсутність цифр
				//  Наприклад n = + || - || / || . || просто буква


int chcp, chcpOut;
void set_chcp(); // Зберігає значення chcp яке було до запуску програми, та встановлює підтримку UTF-8
void reset_chcp(); // Повертає значення chcp яке було до запуску програми

void Error_p (); // Повідомляє користувачеві про те що він допустив помилку при введенні даних

int main(void) {
set_chcp();

printf ("\r\n\nВведіть порядковий номер дня тижня (n) для отримання назви дня:\r\nn = ");
tmp_n1 = scanf ("%d", &n);
tmp_n = getchar ();

// printf("----------------------| n = %d | tmp_n1 = %d |----------------------\r\n", n, tmp_n1);	//debug

if (tmp_n != 10 || tmp_n1 == 0)
{
	Error_p ();
	reset_chcp();
	getch();
	return 1;
}
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

void Error_p ()
{
	printf("\r\nНеправильне введення \"n\"\r\nВи можете ввести лише числа від 1, до 7.\r\n\"n\" ЦІЛЕ число.\r\n");
}