#include <stdio.h>

int main()
{
	int a;
	float V = 0;
	float S = 0;
	printf("Enter radius value\n");
	scanf_s("%d", &a);
	if (a < 0)
		printf("Error");
	else
	{
		V = a * a * a * 3.14 * 4 / 3;
		S = 4 * 3.14 * a * a;
		printf("Volume = %.3f\n", V);
		printf("Sqr area = %.3f\n", S);
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int k;
	printf("Enter number\n");
	scanf_s("%d", &k);
	if (k > 0)
		if (k % 2 == 0)
			printf("even");
		else
			printf("odd");
	else
		printf("Wrong number");
	return 0;
}

#include <stdio.h>

int main()
{
	float a = 0, b = 0, c = 0;
	int i = 0;
	printf("Enter numbers\n");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);
	if (a * b == 1)
		i = i + 1;
	if (a * c == 1)
		i = i + 1;
	if (b * c == 1)
		i = i + 1;
	printf("Pairs = %d\n", i);
	return 0;

}

#include <stdio.h>

int main()
{
	char input;
	printf("Enter a season(ex: 1(summer),2(fall),3(spring), 4(winter))\n");
	scanf_s("%d", &input);
	if (input < 1)
		printf("Error");
	else {
		switch (input)
		{
		case 1: printf("June,Jule,August\n");
			break;
		case 2: printf("September,October,November\n");
			break;
		case 4: printf("December,January,february\n");
			break;
		case 3: printf("March,April,May");
			break;
		}
	}
