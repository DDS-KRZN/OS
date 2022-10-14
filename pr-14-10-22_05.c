#include <stdlib.h>
char *getenv(const char *name);

int main(int argc, char const *argv[])
{
	char name[20];
	scanf("%s", name);
	printf("%s\n", getenv(name));
	return 0;
}