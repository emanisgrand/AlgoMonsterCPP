#include "solo.h"
string customers[] = { "Alice", "Bob", "Rayan", "Emma", "Ann", "Bruce", "Synthia", "Daniel", "Richard", "Sam", "Nick", "Mary", "Paul" };

void passBy(int* x)
{
	*x = 100;
}

void winners(string* customers, int size, int lucky, int cache)
{
	lucky--;
	for (int i = 0; i < size; i++)
	{
		if (lucky > (size - 1))
		{
			break;
		}
		cout << customers[lucky] << endl;
		lucky = lucky + cache;
	}
}