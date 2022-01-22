#include <iostream>
#include "my_complex.h"

using namespace std;

int main()
{
    my_complex<double> c1;

    cout << c1.imag() << endl;

    return 0;
}
