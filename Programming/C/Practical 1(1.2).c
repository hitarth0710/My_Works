//program for student details
#include<stdio.h>

void main ()
{
	char name[100],branch[3]="CSD",gender='M';
	int enr;
	float total,avg,phy,chem,math,english=58.00,comp=80.00;
	
	printf("Enter Your Name : ");
	scanf("%s",&name);
	printf("Enter your Enr No. : ");
	scanf("%d",&enr);
	printf("Enter your Physics Marks : ");
	scanf("%f",&phy);
	printf("Enter your Chemistry Marks : ");
	scanf("%f",&chem);
	printf("Enter your Maths Marks : ");
	scanf("%f",&math);
	printf("\n");
	printf("Details of %s \n \n ",name);
	printf("Your Enr No. = %d \n",enr);
	printf("Your Branch is %s \n",branch);
	printf("your Gender is %c \n",gender);
	printf("Your marks in English is %.2f\n",english);
	printf("Your marks in Computer is %.2f\n",comp);
	printf("Your marks in Physics is %.2f\n",phy);
	printf("Your marks in chemistry is %.2f\n",chem);
	printf("Your marks in Maths is %.2f\n",math);
    total=phy+chem+math+english+comp;
    printf("Your Total Marks in PCM is %f\n",total);
    avg=total/5;
    printf("Your Average is %f\n",avg);
}
