#include <stdlib.h>
#include <stdio.h>

#include "App.h"

int main(int argc, char ** argv)
{
	char * result = App_run(argc, argv);
	printf("%s", result);
	free(result);
	return 0;
}
