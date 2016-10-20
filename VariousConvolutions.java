#include<stdio.h>
int n1, n2, p1, p2;
int i, j, k;
int x[100];
int h[100];
int y[100];
int xo[100];
int ho[100];
int yo[100];
void restarts()
{
	int i = 0;
	for (; i < 100; i++)
	{
		x[i] = xo[i];
		y[i] = 0;
		h[i] = ho[i];
	}
}
void linearcircular()
{
	int k;
	int m = n1 + n2 - 1;
	k = m - n1;
	i = n1;
	while (k>0)
	{
		x[i++] = 0;
		k--;
	}
	k = m - n2;
	i = n2;
	while (k>0)
	{
		h[i++] = 0;
		k--;
	}
	for (i = 0; i<m; i++)
	for (j = 0; j<m; j++)
	{
		y[(i + j) % m] = y[(i + j) % m] + x[i] * h[j];
	}
	printf("Linear using Circular Convolution : Y[n] = \n");
	for (i = 0; i<m; i++)
		printf("%d\t", y[i]);
	printf("\nThe starting Index being : %d\n", (p1 + p2));
}
//////////////////////////////////////////////////////////////////////////
void circularlinear()
{
	int m = 0;
	int max = 0;
	if (n1>n2)
	{
		m = n1;
		int k = n1 - n2;
		i = n2;
		while (k>0)
		{
			h[i++] = 0;
			k--;
		}
	}
	if (n2>n1)
	{
		m = n2;
		int k = n2 - n1;
		i = n1;
		while (k>0)
		{
			x[i++] = 0;
			k--;
		}
	}
	for (i = 0; i<m; i++)
	for (j = 0; j<m; j++)
	{
		y[(i + j)] = y[(i + j)] + x[i] * h[j];
	}
	int z, z1 = 0;
	for (z = m; z<2 * m; z++)
	{
		y[z1] = y[z1] + y[z];
		z1++;
	}
	printf("Circular using Linear  Convolution : Y[n] = \n");
	for (i = 0; i<m; i++)
		printf("%d\t", y[i]);
	printf("\nThe starting Index being : %d\n", (p1 + p2));
}
//////////////////////////////////////////////////////////////////////
void linear()
{
	for (i = 0; i<n1; i++)
	for (j = 0; j<n2; j++)
	{
		y[i + j] = y[i + j] + x[i] * h[j];
	}
	printf("Linear Convolution : Y[n] = \n");
	for (i = 0; i<(n1 + n2 - 1); i++)
		printf("%d\t", y[i]);
	printf("\nThe starting Index being : %d\n", (p1 + p2));
}
/////////////////////////////////////////////////////////////////////
void circular()
{
	int m = 0;
	int max = 0;
	if (n1>n2)
	{
		m = n1;
		int k = n1 - n2;
		i = n2;
		while (k>0)
		{
			h[i++] = 0;
			k--;
		}
	}
	if (n2>n1)
	{
		m = n2;
		int k = n2 - n1;
		i = n1;
		while (k>0)
		{
			x[i++] = 0;
			k--;
		}
	}
	for (i = 0; i<m; i++)
	for (j = 0; j<m; j++)
	{
		y[(i + j) % m] = y[(i + j) % m] + x[i] * h[j];
	}
	printf("Circular Convolution : Y[n] = \n");
	for (i = 0; i<m; i++)
		printf("%d\t", y[i]);

	printf("\nThe starting Index being : %d\n", (p1 + p2));
}
////////////////////////////////////////////////////////////////////
int read(){
	int x;
	scanf("%d", &x);
	return x;
}
void main()
{
	printf("Enter the number elements in X(n) : ");
	n1 = read();
	for (i = 0; i<n1; i++)
	{
		printf("Enter the element at X(%d): ", i);
		xo[i]=x[i] = read();
	}
	printf("Enter the start index X(N) : ");
	p1 = read();
	printf("Enter the number elements in H(n) : ");
	n2 = read();
	for (i = 0; i<n2; i++)
	{
		printf("Enter the element at H(%d): ", i);
		ho[i]=h[i] = read();
	}
	printf("Enter the index H(N) : ");
	p2 = read();
	printf("Enter the Convolution : \n1.Linear\n2.Circular\n3.Linear From Circular\n4.Circular from Linear\nEnter Option ");
	switch(read())
	{
	case 1: linear();break;
	case 2: circular();break;
	case 3: linearcircular();break;
	case 4: circularlinear();break;
	}
}
