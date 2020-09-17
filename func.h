#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

// char debug = 1;

int chcp, chcpOut;

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

#define N 11
#define limit_s N-2

char error = 0;
char s[N] = "0";
char scan_sum = 0;
char minus = 0;
int result = 0;

do{
error = 0;
scan_sum = 0;
minus = 0;

printf("\r\n%c = ", printf_x);

fgets(s, N, stdin);
fflush(stdin);

if (s[0] == '\n')
{
	printf("\r\nВведіть хоть щось будьласка\r\n");
	error = 1;
	continue;
} else	if (s[0] == '-' && s[1] == '\n')
		{
			printf("\r\nПросто мінус? Серйозно!?\r\n");
			error = 1;
			continue;
		}

for (int i = 0; i < N; i++)
{
	if (s[i] == '-')
	{
		minus++;

	}

	if (s[i] == '\n')
	{
		break;

	} else scan_sum++;
}

// printf("-------|Кількість мінусів = %d |---------\n", minus); //debug

	if (scan_sum > limit_s || scan_sum < -limit_s)
	{
		printf("\r\n\nУпс! Програма не розрахована на обчислення таких великих чисел\r\n");
		error = 1;
		continue;
	}

	for (int i = 0; i < scan_sum; i++)
	{

		if (s[i] == ' ')
		{
			printf("\r\nПробіл був лишнім введіть нормально будьласка!\r\n");
			error = 1;
			break;
						//45 = -		//від 0 до 9		// не більше 1-го мінуса
		} else  if ((s[i] == 45 || s[i] >= 48 && s[i] <= 57) && (minus <= 1))
				{
				// printf("\r\ns[%d] = %d ---| Добре |---", i, s[i]); //debug
				
				} else {
						// printf("\r\ns[%d] = %d ---| не Добре |---", i, s[i]); //debug
						printf("\r\nУвага! Ви ввели неправильне значення \"%c\"\r\n", printf_x);
						error = 1;
						break;

						}
	}

}while (error == 1);


// printf("\r\n\n"); //debug
// for (int i = 0; i < N; i++) //debug
// { //debug
	// printf("---------| s[%d] = %d [%c]|-------\r\n", i, s[i], s[i]); //debug
// } //debug
// printf("\r\n\n"); //debug

// printf("---------|Кількість введених символів| %d |-------\r\n", scan_sum); //debug

result = atoi(s);
// printf("----|scanf_check_int| result = %d |-----\n", result); //debug

return result;
}

/*-----------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------*/

double scanf_check_double (char printf_x)
{

#define N 11
#define limit_s N-2

char s[N] = "0";
char pislya_krapka[N] = "0";

char error = 0;
char scan_sum = 0;
char krapka = 0;
char point_krapka = 0;
char kinez_s = 0;
double result = 0;
char minus = 0;

do{
error = 0;
scan_sum = 0;
krapka = 0;
point_krapka = 0;
kinez_s = 0;
minus = 0;

printf("\r\n%c = ", printf_x);

fgets(s, N, stdin);
fflush(stdin);

if (s[0] == '\n')
{
	printf("\r\nВведіть хоть щось будьласка\r\n");
	error = 1;
	continue;

} else	if (s[0] == '-' && s[1] == '\n')
		{
			printf("\r\nПросто мінус? Серйозно!?\r\n");
			error = 1;
			continue;
		} else	if (s[0] == '.' && s[1] == '\n')
				{
					printf("\r\nПросто крапка? Серйозно!?\r\n");
					error = 1;
					continue;
				}



for (int i = 0; i < N; i++)
{
	if (s[i] == '\n')
	{
		kinez_s = i;
		break;

	} else scan_sum++;

	if (s[i] == '.')
	{
		krapka++;
		point_krapka = i+1;
	}

		if (s[i] == '-')
	{
		minus++;
	}
}

// printf("-------|Кількість крапок = %d |---------\n", krapka); //debug
// printf("-------|індекс після крапки = %d |---------\n", point_krapka); //debug
// printf("-------|Кількість мінусів = %d |---------\n", minus); //debug


	if (scan_sum > limit_s || scan_sum < -limit_s)
	{
		printf("\r\n\nУпс! Програма не розрахована на обчислення таких великих чисел\r\n");
		error = 1;
		continue;
	}


	for (int i = 0; i < scan_sum; i++)
	{


		if (s[i] == ' ')
		{
			printf("\r\nПробіл був лишнім введіть нормально будьласка!\r\n");
			error = 1;
			break;
						//45 = -	//46 = .			//від 0 до 9		// не більше 1-го мінуса і 1-ї крапки
		} else  if ((s[i] == 45 || s[i] == 46 || s[i] >= 48 && s[i] <= 57) && (minus <= 1 && krapka <= 1))
				{
				// printf("\r\ns[%d] = %d ---| Добре |---", i, s[i]); //debug
				
				} else {
						// printf("\r\ns[%d] = %d ---| не Добре |---", i, s[i]); //debug
						printf("\r\nУвага! Ви ввели неправильне значення \"%c\"\r\n", printf_x);
						error = 1;
						break;

						}
	}

}while (error == 1);


// printf("\r\n\n"); //debug
// for (int i = 0; i < N; i++) //debug
// { //debug
	// printf("---------| s[%d] = %d [%c]|-------\r\n", i, s[i], s[i]); //debug
// } //debug
// printf("\r\n\n"); //debug

// printf("---------|Кількість введених символів| %d |-------\r\n", scan_sum);//debug

char limit_pislya_krapka = kinez_s - point_krapka;

if (krapka == 1)
{
	for (int i = 0; i < limit_pislya_krapka; i++)
	{
			pislya_krapka[i] = s[point_krapka];
			point_krapka++;
	}
}


// printf("\n"); //debug
// for (int i = 0; i < limit_pislya_krapka; i++) //debug
// { //debug
	// printf("---------|Символи після крапки [%d] = %c |-------\r\n", i, pislya_krapka[i]); //debug
// } //debug

int tmp = atoi(pislya_krapka);
// printf("----| Перетворення char[]  int = %d |-----\n", tmp); //debug

double tmp2 = pow(0.1,limit_pislya_krapka);
// printf("----| На скільки множити = %f |-----\n", tmp2); //debug

double tmp3 = tmp * tmp2;
// printf("----| Число після крапки [нормально] = %f |-----\n", tmp3); //debug

if (s[0] == '-')
{
	result = atoi(s) + -tmp3;
	// printf("\r\n---------|Число до крапки = %d |-------\r\n", atoi(s)); //debug
	// printf("----| Число [нормально] = %lf |-----\n", result); //debug

} else	{
		result = atoi(s) + tmp3;
		// printf("---------|Число до крапки = %d |-------\r\n", atoi(s)); //debug
		// printf("----| Число [нормально] = %lf |-----\n", result); //debug
		}

return result;
}