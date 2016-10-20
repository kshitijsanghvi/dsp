#include<stdio.h>
int n1,n2,p1,p2;
int i,j,k;
int x[100];
int h[100];
int yp[100];
int yn1[100];

int read(){
	int x;
	scanf("%d",&x);
	return x;
}
void linear()
{

p2=(p2)-n2+1;
for(i=0;i<n1;i++)
for(j=0;j<n2;j++)
{
if(i-j>=0){
yp[i-j]=yp[i-j]+x[i]*h[j];
}
else
yn1[-1*(i-j)]=yn1[(i-j)*-1]+x[i]*h[j];

}
printf("Cross Corelation : Y[n] = \n");

int start=p2*-1;
int temp=start;
while(start>0)
{
printf("%d\t",yn1[start]);
start--;
}

for(i=0;i<(n1+n2-1);i++)
printf("%d\t",yp[i]);

printf("\nThe starting Index being : %d\n",(temp*-1));
}

void main()
{

printf("Enter the number elements in X(n) : ");
n1=read();
for(i=0;i<n1;i++)
{
printf("Enter the element at X(%d): ",i);
x[i]=read();
}

printf("Enter the start index X(N) : ");
 p1=read();

printf("Is the Correlation Auto ? 1 : 0?");
int choice=read();
if(choice){

//printf("Enter the number elements in H(n) : ");
 n2=n1;
for(i=0;i<n2;i++)
{
//printf("Enter the element at H(%d): ",i);
h[i]=x[i];
}


//printf("Enter the index H(N) : ");
p2=p1;
}
else
{

printf("Enter the number elements in H(n) : ");
 n2=read();
for(i=0;i<n2;i++)
{
printf("Enter the element at H(%d): ",i);
h[i]=read();
}


printf("Enter the index H(N) : ");
p2=read();

}

linear();
}
