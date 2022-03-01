


#include <stdio.h>
#include <math.h>


float cos_triangle(int a, int b, int c)
{
	return (float)(a * a + b * b - c * c) / (2 * a * b);
}

void print_float_represent(float floatValue)
{
	int *intPointer;

	intPointer = (int *)(&floatValue);
	for (int loop = 31; loop >= 0; --loop)
	{
		if (0 == (intPointer[0] & (1 << loop)))
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		if (0 == (loop % 4))
		{
			printf(" ");
		}
	}
}

int main(int argc, char *argv[])
{
	float cos1;
	float area;
	int side1 = 11;
	int side2 = 12;
	int side3 = 20;
	int hasInputThreeSideLength = 0;

	cos1 = cos_triangle(side1, side2, side3);
	printf("The cos value of the maximum angle of the triangle whose sides are %d, %d, %d is: %.3f\n",
		side1, side2, side3, cos1);
	printf("The floating-point number %.3f represented in memory is: ", cos1);
	print_float_represent(cos1);
	printf("in binary.\n");
	area = (float)(side1 * side2 * sqrt(1 - cos1 * cos1) / 2);
	printf("The area of the triangle whose sides are %d, %d, %d is: %.3f\n",
		side1, side2, side3, area);
	printf("The floating-point number %.3f represented in memory is: ", area);
	print_float_represent(area);
	printf("in binary.\n");

	while (!hasInputThreeSideLength)
	{
		printf("Please input the first side's length of the triangle:\n");
		scanf("%d", &side1);
		printf("Please input the second side's length of the triangle:\n");
		scanf("%d", &side2);
		printf("Please input the third side's length of the triangle:\n");
		scanf("%d", &side3);
		if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
		{
			printf("The side %d, %d, %d cannot form a triangle\n",
				side1, side2, side3);
		}
		else
		{
			hasInputThreeSideLength = 1;
		}
	}

	cos1 = cos_triangle(side1, side2, side3);
	area = (float)(side1 * side2 * sqrt(1 - cos1 * cos1) / 2);
	printf("The area of the triangle whose sides are %d, %d, %d is: %.3f\n",
		side1, side2, side3, area);

	return 0;
}

