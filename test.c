
#include <stdio.h>
#include <math.h>

int	main(void)
{
	double wallX = 3.5; //where exactly the wall was hit
	wallX -= floor((wallX));
	printf("%f", wallX);
}
