#include <iostream>

int main(int, char **)
{
    int a[10];
    for (int i = 0; i <= 9; i++)
    {
        std::cin >> a[i];
    }
    std::cout << a[a[a[0]]];
}
