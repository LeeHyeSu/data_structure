#include <stdio.h>
#include <string.h>
void print_reverse(char *str, int end)
{
	if (end >= 0)
	{
		printf("%c", str[end]);
		print_reverse(str, end - 1);
	}
}

int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	printf("Reversed String is: ");
	print_reverse(str, strlen(str) - 1);
	return 0;
}