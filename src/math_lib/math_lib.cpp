#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
		if (b == 0) return a;
		return GCD(b, a % b);
	}
}

double trapez(double(*f)(double), double a, double b, double eps)
{
    double old_i = 0, new_i = old_i+2*eps;
    for(unsigned int n = 1; abs(new_i-old_i) > eps; n *= 2)
    {
        old_i = new_i;
        double h = (b-a)/n, s = -(f(a) + f(b))/2;
        for(int i = 0; i <= n; ++i)
            s += f(a + i*h);
        new_i = s*h;
    }
    return new_i;
}

double y(double x) { return sin(x)*cos(x*x); }

int main(int argc, char * argv[])
{
    cout << trapez(y,0,5,1e-6) << endl;
}


