#include <iostream>
using namespace std;

/*
****
****
****
****
*/
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
}

/*
 *
 **
 ***
 ****
 */
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

/*
1
12
123
1234
12345
*/
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
            cout << j;
        cout << endl;
    }
}

/*
1
22
333
4444
55555
*/
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << i + 1;
        cout << endl;
    }
}

/*
*****
****
***
**
*
*/
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << "*";
        cout << endl;
    }
}

/*
12345
1234
123
12
1
*/
void pattern6(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
}

/*
     *
    ***
   *****
  *******
 *********
 */
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }
}

/*
 *********
  *******
   *****
    ***
     *
 */
void pattern8(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - i - 1; j > 0; j--)
            cout << " ";
        for(int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }
}

/*
     *
    ***
   *****
  *******
 *********
 *********
  *******
   *****
    ***
     *
*/
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - i - 1; j > 0; j--)
            cout << " ";
        for(int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }
}

/*
*
**
***
****
*****
****
***
**
*
*/
void pattern10(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for(int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
1
0 1
1 0 1
0 1 0 1

*/


int main()
{
    int n = 5;
    pattern1(n);
    cout << endl;
    pattern2(n);
    cout << endl;
    pattern3(n);
    cout << endl;
    pattern4(n);
    cout << endl;
    pattern5(n);
    cout << endl;
    pattern6(n);
    cout << endl;
    pattern7(n);
    cout << endl;
    pattern8(n);
    cout << endl;
    pattern9(n);
    cout << endl;
    pattern10(n);
    cout << endl;
    return 0;
}