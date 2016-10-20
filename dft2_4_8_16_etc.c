////////////////////////////////////////////WORKS ONLY WHEN SUBGRAPH LIBRARY IS INSTALLED -lm -lgraph
///////////////////////////////////////////Output : if required ill forward over whatsapp!
#include<stdio.h>
#include<math.h>
#include<complex.h>
#include<graphics.h>
int n;
double mag[100];
int readInt(){int x;scanf("%d",&x); return x;}
char str[30];
int ypixel[100];


displayMag(){
int gd=DETECT,gm;
int ox=20,oy=450;

initgraph(&gd,&gm,NULL);
setbkcolor(BLUE);
setcolor(BLACK);
outtextxy(200,455,"X-Axis");
outtextxy(30,100,"Y-Axis");
outtextxy(200,200,"MAGNITUDE PLOT");

line(20,20,20,450);
line(20,450,620,450);
setcolor(RED);
for(i=0;i<n;i++)
{
ox=ox+xinc;

line(ox,oy-ypixel[i],ox,oy);
tostring(i);
outtextxy(ox,oy+10,str);


}

displayPhase()
{

int gd=DETECT,gm;
int ox=20,oy=270;

initgraph(&gd,&gm,NULL);
setbkcolor(BLUE);
setcolor(BLACK);
outtextxy(200,455,"X-Axis");
outtextxy(30,100,"Y-Axis");
outtextxy(200,200,"PHASE PLOT");

line(20,20,20,450);
line(20,270,620,270);
setcolor(RED);
for(i=0;i<n;i++)
{
ox=ox+xinc;

line(ox,oy-ypixel[i],ox,oy);
tostring(i);
outtextxy(ox,oy+10,str);


}

int zsdf=readInt();
closegraph();

}

int zsdf=readInt();
closegraph();

}

void tostring( int num)

{

    int i, rem, len = 0, n;

 	if(num ==0 ){str[0]='0';str[1]='\0';return;}

    n = num;

    while (n != 0)

    {

        len++;

        n /= 10;

    }

    for (i = 0; i < len; i++)

    {

        rem = num % 10;

        num = num / 10;

        str[len - (i + 1)] = rem + '0';

    }

    str[len] = '\0';

}


void main()
{


int i;
printf("Enter the n point : ");
n=readInt();

int seq[100];

for(i=0;i<n;i++)
{
printf("Enter value : ");
seq[i]=readInt();
}
double real[100];
double imag[100];

double xkreal[100];
double xkimag[100];


int k;

for(k=0;k<n;k++)
{
real[k]=cos(-1*2*3.142*k/n);
imag[k]=sin(-1*2*3.142*k/n);
}

for(i=0;i<n;i++)
{printf("%lf\t+ i%lf\n",real[i],imag[i]);}

double xk[100];
int n1;
for(k=0;k<n;k++)
	{
	double complex z1=real[k] + imag[k]*I;
	double complex sum=0.0 + 0.0*I;
	//printf("m(n,%d) = %.2f%+.2fi\n",k,creal(z1),cimag(z1));
	
	for(n1=0;n1<n;n1++)
	{
	double complex z2=seq[n1]*cpow(z1,n1);
		
	   	//printf("m(%d,%d) = %.2f%+.2fi\n",k,n1,creal(z2),cimag(z2));
		sum=sum+z2;
	}
	//printf("k(%d) = %.2f%+.2fi\n",k,creal(sum),cimag(sum));

		xkreal[k]=creal(sum);
		xkimag[k]=cimag(sum);
	}

printf("\nVector : \n");
for(i=0;i<n;i++)
{
printf("X(%d) = %.2f%+.2fi\n",i,xkreal[i],xkimag[i]);
mag[i]=sqrt(pow(xkreal[i],2)+pow(xkimag[i],2));
}
double sum=0;
printf("Magnitude : \n");
for(i=0;i<n;i++)
{
printf("X(%d) = %lf\n",i,mag[i]);
sum=sum+mag[i];
}


for(i=0;i<n;i++)
{
mag[i]=(atan(xkimag[i]/xkreal[i])*180/3.142);
}
 sum=0;
printf("PHASE (in degree): \n");
for(i=0;i<n;i++)
{
printf("X(%d) = %lf\n",i,mag[i]);
sum=sum+mag[i];
}


for(i=0;i<n;i++)
ypixel[i]=(int)(mag[i]/sum*480);
int xinc=600/n;

displayMag();
displayPhase();

}
