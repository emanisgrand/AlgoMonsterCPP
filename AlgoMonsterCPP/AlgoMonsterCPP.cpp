#include "solo.h"

int main()
{   
	int megabytes;
	cin >> megabytes;
	cout << "Before promotion: " << megabytes << endl;
	promotion(&megabytes);
	cout << "After promotion: " << megabytes << endl;
}