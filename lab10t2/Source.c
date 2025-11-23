#include <locale.h>
#include <stdio.h>
#include <math.h>

double sin_n(double x, int N);
double sin_eps(double x, double eps);

int main() {
	setlocale(LC_CTYPE, "RUS");
	double x;
	int n;
	double eps;

	printf("Введите x: ");
	scanf("%lf", &x);
	printf("\nВведите количество членов ряда: ");
	scanf("%d", &n);
	printf("\nВведите точность: ");
	scanf("%lf", &eps);

	printf("\nx: %lf", x);
	printf("\nn: %d", n);
	printf("\neps: %lf", eps);

	printf("\nВычисление с помощью стандартной библиотеки: %lf\n", sin(x));

	printf("Вычисление с помощью создания собственной функции, вычисляющий значение как сумму ряда: %lf\n", sin_n(x, n));

	printf("Вычисление с помощью создания собственной функции, вычисляющий значение через ряд Маклорена с заданной пользователем точностью: %lf\n", sin_eps(x, eps));
}

double sin_n(double x, int N) {
	double res = x;
	double fact = 1;
	for (int i = 3, sign = -1; i <= N; i+=2)
	{
		fact = 1;
		for (int j = 1; j <= i; j++)
			fact *= j;
	
		res += sign * pow(x, i) / fact;
		sign *= -1;
		
	}
	return res;
}

double sin_eps(double x, double eps) {
	double res = x;
	double fact = 1;
	int i = 3;
	int sign = -1;
	double temp;

	do {
		fact = 1;
		for (int k = 1; k <= i; k++)
			fact *= k;

		temp = sign * pow(x, i) / fact;
		res += temp;
		sign *= -1;
		i += 2;


	} while (fabs(temp)>eps);

	return res;
}