#include "../include/minirt.h"

int	double_equal(double a, double b)
{
	printf("** VALOR **: %lf", fabs(a - b));
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}