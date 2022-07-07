#include <iostream>

void passBy(int* x)
{
    *x = 100;
}

int main()
{
    int var = 20;
    passBy(&var);
    std::cout << var;
}