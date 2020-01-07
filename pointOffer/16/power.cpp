#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

double PowerWithUnsignedExp(double base, unsigned int absExp);
bool equal(double x, double y);
bool check_Input = false;
double Power(double base, int exponent)
{
    check_Input = false;
    if(equal(base, 0.0) && exponent<0)
    {
        check_Input = true;
        return 0.0;
    }
    
    unsigned int absExp = (unsigned int)(exponent);
    if(exponent<0)
        absExp = (unsigned int) (-exponent);
    
    double res = PowerWithUnsignedExp(base, absExp);
    if(exponent<0)
        res = 1.0/res;
    return res;
}

double PowerWithUnsignedExp(double base, unsigned int absExp)
{
    double res = 1.0;
    for(int i=1;i<=absExp;++i)
        res *= base;
    return res;
}

bool equal(double x, double y)
{
    if(abs(x-y)<0.0001)
        return true;
    else
        return false;
}


int main()
{
    int base = 2, exp = -3;
    int res;
    res = Power(base,exp);
    cout << "res = " << res << endl;
}
