#include <cstdio>
#include <cstdlib>

void hanoi(int n, const char* pegA, const char* pegB, const char* pegC)
{
	if(n == 1)
	{
		printf("move disk %d from %s to %s\n", n, pegA, pegC);
	}

	else
	{
		hanoi(n - 1, pegA, pegC, pegB);
		printf("move disk %d from %s to %s\n", n, pegA, pegC);
		hanoi(n - 1, pegB, pegA, pegC);
	}
}

int main()
{
	int n = 1;
	printf("solve hanoi\n\n");
	printf("enter number of disks :");
	scanf("%d", &n);

	printf("\n\nsolution:\n");
	hanoi(n, "pegA", "pegB", "pegC");

	return(0);
}
