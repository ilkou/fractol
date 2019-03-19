#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_complex
{
        double          re;
        double          im;
}			t_complex;

void ft_power_complex(t_complex *z, int power)
{
        double x;
        double y;
        double argument;
        double module;

        x = z->re;
        y = z->im;
        argument = acos(x / sqrt(abs(x * x) + abs(y * y)));
        module = sqrt(abs(x * x) + abs(y * y));
        z->re = pow(module, power) * cos(power * argument);
        z->im = pow(module, power) * sin(power * argument);
}

int main(int argc, char **argv)
{
	t_complex z;
	z.re = 1.0;
	z.im = 1.7321;
	ft_power_complex(&z, atoi(argv[1]));
	printf("re : %f\nim : %f\n", z.re, z.im);
	return 0;
}
