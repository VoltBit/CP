#include <stdio.h>
#include <string.h>

int func1(int a, double b, char *s)
{
	printf("functia 1!: \n %i %lg \n",a,b);
	puts(s);
	return 0;
}

int main(void)
{
char s[100];
fgets(s,100,stdin);
puts(s);
printf("%c",*(s+2));

int (*f1)(int,double,char*);
f1 = func1;
f1(1,2.3,s);
return 0;
}
