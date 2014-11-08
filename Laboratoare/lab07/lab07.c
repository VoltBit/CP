#include <stdio.h>

int str_length(char *s)
{
	int nr=0;
	while(*s!='\0')
	{
		nr++; s++;
	}
	return nr;
}
void strdel(char *s, int pos, int n)
{
	int i,nr=0;
	char *a;
	a=s;
	for(i=pos;i<str_length(a);i++)
	{
		printf("%c",a[i]);
		//*(a+i)=*(a+i+1);
		//a[i]=a[i+1];
	}printf("\n");
}
int main()
{
	int n = 2;
	char *c = (char*)&n;
	if(*c == 1)printf("Little endian!\n");
	else printf("Big endian!\n");
	printf("%i\n",*(char *)&n );

	printf("numar caractere: %i\n",str_length("mere"));
	strdel("mere",1,2);
	return 0;
}