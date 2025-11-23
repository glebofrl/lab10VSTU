#include <locale.h>
#include <stdio.h>
#include <math.h>

double fa(double x);
double fb(double x);

int main() {
	setlocale(LC_CTYPE, "RUS");
	double x;
	do {
		printf("Введите число: ");
		scanf("%lf", &x);
		printf("fa(x)=%lf , fb(x)=%lf \n", fa(x), fb(x));
		printf("произведение: %lf; разность квадратов: %lf; удвоенная сумма: %lf\n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));

		char a;
		printf("Выберите желаемое действие, нажав на соответствующую цифру:\n"
			"1. Рассчет значений функции fa.\n"
			"2. Рассчет значений функции fb.\n"
			"3. Рассчет произведения двух функций.\n"
			"4. Рассчет разности квадратов двух функций.\n"
			"5. Рассчет удвоенной суммы двух функций.\n"
			"6. Перезапустить программу.\n"
			"7. Завершить программу.\n");
		while (getchar() != '\n');
		a = getchar();
			switch (a)
			{
			case '1':
				printf("%lf\n", fa(x));
				break;

			case '2':
				printf("%lf\n", fb(x));
				break;

			case '3':
				printf("%lf\n", fa(x) * fb(x));
				break;

			case '4':
				printf("%lf\n", pow(fa(x), 2) - pow(fb(x), 2));
				break;

			case '5':
				printf("%lf\n", 2 * (fa(x) + fb(x)));
				break;

			case '6':
				continue;

			case '7':
				return 0;
				break;
			default:
				printf("Некорректный ввод!\n");
				break;
			}
			printf("\n");
	} while (1);

}

double fa(double x) {
	double y;
	if (x <= 3)
		y = pow(x, 2) - 3 * x + 9;
	else y = 1 / (pow(x, 3) + 3);
	return y;
}

double fb(double x) {
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}



