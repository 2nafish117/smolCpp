#include <iostream>

using namespace std;

long ack(int m, int n)
{
	if(m == 0)
		return(n + 1);
	if(m > 0 && n== 0)
		return(ack(m - 1, 1));
	if(m > 0 && n > 0)
		return(ack(m - 1, ack(m, n - 1)));

		return(-1);
}

int main()
{
	long sum = 0;

	for(int i = 0;i < 6 ;i++)
		cout << ack(i, i) << endl;

	//cout << sum;
	return(0);
}
