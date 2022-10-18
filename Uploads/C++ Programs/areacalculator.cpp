#include <iostream>
using namespace std;

// Function Overloading
int sum(int a, int b)
{
    cout << "Using function with 2 arguments." << endl;
    return a + b;
}

int sum(int a, int b, int c)
{
    cout << "Using function with 3 arguments." << endl;
    return a + b + c;
}

// Calculate the volume of cylinder

int volume(double r, int h)
{
    return (3.14 * r * r * h);
}
// Calculate the volume of cube

int volume(int s)
{
    return (s * s * s);
}

// Calculate the volume of rectangular box/ Cuboid
int volume(int l, int b, int h)
{
    return (l * b * h);
}

int main()
{
    cout << "The sum of 3 & 6 is " << sum(3, 6) << endl;
    cout << "The sum of 3 , 7 and 6 is " << sum(3, 7, 6) << endl;

    int t;
    cout << "Welcome to the area calculating program" << endl;
    cout << "Choose number according to your choice \n1.Calculate the volume of cylinder \n2.Calculate the volume of cube\n 3.Calculate the volume of rectangular box/ Cuboid" << endl;
    cin >> t;

    if (t == 1)
    {
        int r;
        cout << "Enter the radius of cylinder" << endl;
        cin >> r;
        int h;
        cout << "Enter the height of  a cylinder" << endl;
        cin >> h;
        cout << "Volume of a cylinder is" << volume(r, h) << endl;
    }
    else if (t == 2)
    {
        int s;
        cout << "Enter the side of cube" << endl;
        cin >> s;
        cout << "Volume of a cube is" << volume(s) << endl;
    }
    else if (t == 3)
    {
        int l;
        cout << "Enter the length of cuboid" << endl;
        cin >> l;
        int b;
        cout << "Enter the breadth of  a cuboid" << endl;
        cin >> b;
        int h;
        cout << "Enter the height of  a cuboid" << endl;
        cin >> h;
        cout << "Volume of a cuboid is" << volume(l, b, h) << endl;
    }
    else
    {
        cout << "Wrong Entry.................................";
    }

    return 0;
}
