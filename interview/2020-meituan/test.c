#include<stdio.h>
#include<string.h>

int size;
int main(void){
	char *s="abcde"; 
	size = sizeof(s);
	printf("%d", size);

	size = sizeof(*s);
	printf("%d", size);
	return 0;
}

