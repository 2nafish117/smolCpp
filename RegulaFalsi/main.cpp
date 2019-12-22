#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//coeff array
float coeff[100];
int degree = 0;
float seed1,seed2;
float resolution = 0.5,height = 150,width = 1000;
int numIterations = 20;

float fi(float var)
{
	float sum = 0.0f;
	int i;

	for(int i = 0;i <= degree;i++)
		sum = sum + coeff[i] * pow(var, i);

	return(sum);
}

//input the seeds as integers from a seeding function
void findseed()
{
	float i, fx;

	printf(" pick the seeds \n");

	for(i = -width;i <= width;i = i + resolution)
	{
		fx = fi(i);

		if(fx < height && fx > -height)
			printf("  {%f,  %f} \n  ", i, fx);
	}

	scanf("%f%f", &seed1, &seed2);
}

void checkCoeff()
{
	int i;
	int num0 = 0;
	for(i = 0;i <= degree;i++)
		if(coeff[i] == 0)
			num0++;

	if(num0 == degree + 1)
	{
		printf("Really Nibba?");
		exit(0);
	}
}

int main()
{
	double fx,fseed2,fseed1;
	double x;
	int i;				//to iterate
    int choice;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

	printf("Input the coefficients of the cubic polynomial\n");
	printf("in decreasing order of powers of x \n  eg: aX^4 + bX^3 + cX^2 + dX + e\n\n");

	for(i = 0;i <= degree;i++)
	{
		scanf("%f", &coeff[i]);
		//printf("%f ", coeff[i]);
	}

	//checks 0 coeff condition
	checkCoeff();

	//smh goto :/
    START:;
    findseed();		//finds seeds

	x = seed1;

	fseed2 = fi(seed2);
	fseed1 = fi(seed2);

	for(i = 0;i < numIterations;i++)
	{
	    fx = fi(x);
		if(fx * fseed2 <= 0)
		{
			//use seed2
			x = seed2 - fseed2*(x - seed2)/(fx - fseed2);
			//printf("  1 %f",fx);
		}

        else
		{
			//use seed1
			x = seed1 - fseed1*(x - seed1)/(fx - fseed1);
			//printf("  2 %f",fx);
        }

	}

	printf("\n\n");
	printf("\tthe approximated solution is  %f.\n\n",x);
	printf("\tthe value of the function at  %f is \n\t%f",x,fi(x));
      printf("\n\n   any more roots? \n\t(1/0)\n\t");

    scanf("%d",&choice);

    if(choice == 1)
        {
            printf("\n\n\n\n");
            goto START;
        }

    else exit(0);

    return(0);
}


