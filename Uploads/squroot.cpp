#include <iostream>
using namespace std;

int getTheIntegerPart(int);
double squareRoot(int);


int main()
{
    int x;
    cout << "Enter a integer\t";
    cin >> x;

    cout << "Root(" << x << ") : " << squareRoot(x) << endl;

    return 0;
}

int getTheIntegerPart(int x)
{

    int s = 0, e = x, m;
    int ans = 0;
    m = (s + e) / 2;

    while (s <= e)
    {

        if (m * m == x)
            return m;
        else if (m * m < x)
        {

            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }

        m = (s + e) / 2;
    }

    return ans;
}

double squareRoot(int x)
{

    int d = getTheIntegerPart(x);
    
    double i = 0.0 , j = 1.0 / 1000000;
    double result, ans;

    while (true)
    {

        result = d + i;

        if (result * result == x)
            return result;

        else if (result * result < x)
        {
            ans = result;
        }
        else
            return ans;
        i += j;
    }
}
