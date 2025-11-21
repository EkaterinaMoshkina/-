#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>


double men(double a);
double meg(double a);
double bol(double a);
double proizv(double a);
//double extrem(double a);
//int puti(double a)


int main()
{
	double x,f, s=1;
	char c;

	setlocale(LC_ALL, "RUS");
	printf("Введите x для вычисления функции f(x) : ");
	scanf("%lf", &x);
	printf("Выберите операцию\n 1 - вычисление f(x)\n 2 - таблица\n 3 - нахождение экстремумов\n 4 - Поиск x\n 5 - производная в точке\n");
	scanf(" %c", &c);

	//вычисление значений для с=1
	if (x < 1)
		f = men(x);
	else if (x < 5)
		f = meg(x);
	else f = bol(x);

	//панель управления
	switch (c) {
	case '1':
		printf("f(%.3lf) = %.3lf", x, f);
		break;
	case '2':
		printf("__________________________\n|     x     |    f(x)    |\n__________________________\n");
		for (x = 0; x <= 6; x += s)
		{
			if (x < 1)
				f = men(x);
			else if (x < 5)
				f = meg(x);
			else f = bol(x);

			printf("|%7.1lf    |  %8.3lf  |\n", x, f);
		}
		break;
	/*case '3': 
		printf("экстремум - %.3lf", extrem(x));
		break;*/
	//case '4':
	case '5':
		printf("производная в точке %.1lf = %.3lf",x, proizv(x));
		break;
	}
}

//х<1
double men(double a)
{
	double result;
	result=exp(a - 1) / pow(a, 3);
	return result;

}
//если х >= 1 меньше 5
double meg(double a)
{
	double result;
	result = atan(a*a)/pow(1+a,1/3);
	return result;
}
//если х >=5
double bol(double a)
{
	double result;
	result = a*sin(log(1+fabs(a)));
	return result;
}

//производная
double proizv(double a)
{
	double result,h=0.1; //h - шаг производной
	if (a<1)
	result = (men(a+h)-men(a-h))/2/h ;
	else if (a<5)
		result = (meg(a + h) - meg(a - h)) / 2 / h;
	else result = (bol(a + h) - bol(a - h)) / 2 / h;
	return result;
}

//экстремумы
//double extrem(double a)
//{
//	double h = 0.1, con,nach, ex; //h - шаг con-конец промежутка, nach - начало промежутка
//	int fl1 = 2, fl2 = 0;
//	if (a < 1)
//		con = 1;
//	else if (a < 5)
//		con = 5;
//	else con=11;
//
//	nach = a;
//
//	for (nach; nach < con; nach += h)
//	{
//		if (nach = a)
//			if (proizv(nach) < 0)  //запоминаем знак первой производной
//				fl1 = 0;
//			else fl1 = 1;
//		else
//		{
//			if (proizv(nach) < 0)  
//				fl2 = 0;
//			else fl2 = 1;
//		
//			if (fl1 != fl2)
//			{
//				ex = nach;
//			}
//
//		}
//	}
//	return ex;
//}

//int puti(double a)
//{
//	int result;
//	if (x < 1)
//			result = 1;
//	else if (x < 5)
//			result = 2;
//	else	result = 3;
//}
