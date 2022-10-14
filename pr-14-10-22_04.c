#include <stdlib.h>
extern char **environ;

int main(int argc, char const *argv[])
{
	int i;
	for (i = 0; environ[i] != NULL; ++i)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
