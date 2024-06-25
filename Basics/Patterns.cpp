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
1 0 1 0 1
*/
void pattern11(int n)
{
    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        if(i % 2 == 0)
            flag = true;
        for(int j = 0; j <= i; j++)
        {
            flag == true ? cout << "1 " : cout << "0 ";
            flag = !flag;
        }
        cout << endl;
    }
}

/*
1        1
12      21
123    321
1234  4321
1234554321
*/
void pattern12(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << j + 1;
        for(int k = 0; k < 2 * n - (i * 2) - 2; k++)
            cout << " ";
        for(int j = i + 1; j > 0; j--)
            cout << j;
        cout << endl;
    }
}

/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
void pattern13(int n)
{
    int num = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << num++ << " ";

        cout << endl;
    }
}

/*
A
AB
ABC
ABCD
ABCDE
*/
void pattern14(int n)
{
    for(int i = 0; i < n; i++)
    {
        char ch = 'A';
        for(int j = 0; j <= i; j++)
            cout << ch++;
        cout << endl;
    }
}

/*
ABCDE
ABCD
ABC
AB
A
*/
void pattern15(int n)
{
    for(int i = 0; i < n; i++)
    {
        char ch = 'A';
        for(int j = n; j > i; j--)
            cout << ch++;
        cout << endl;
    }
}

/*
A
BB
CCC
DDDD
EEEEE
*/
void pattern16(int n)
{
    for(int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++)
            cout << ch;
        cout << endl;
    }
}

/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
void pattern17(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";
        char ch = 'A';
        for(int k = 0; k <= i; k++)
            cout << ch++;
        ch -= 2;
        for(int l = i; l > 0; l--)
            cout << ch--;
        cout << endl;
    }
}

/*
E
D E
C D E
B C D E
A B C D E
*/
void pattern18(int n)
{
    for(int i = n; i > 0; i--)
    {
        char ch = 'A' + i - 1;
        for(int j = n; j >= i; j--)
            cout << ch++ << " ";
        cout << endl;
    }
}

/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
void pattern19(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - i; j > 0; j--)
            cout << "*";
        for(int k = 0; k < 2 * i ; k ++)
            cout << " ";
        for(int l = n - i; l > 0; l--)
            cout << "*";
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << "*";
        for(int k = 0; k < 2 * n - (2 * i) - 2; k++)
            cout << " ";
        for(int l = 0; l <= i; l++)
            cout << "*";
        cout << endl;
    }
}

/*
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
void pattern20(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << "*";
        for(int k = 0; k < (2 * n) - (2 * (i + 1)); k++)
            cout << " ";
        for(int k = 0; k <= i; k++)
            cout << "*";
        cout << endl;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = n - i; j > 0; j--)
            cout << "*";
        for(int k = 0; k < 2 * i; k++)
            cout << " ";
        for(int l = n - i; l > 0; l--)
            cout << "*";
        cout << endl;
    }
}

/*
*****
*   *
*   *
*   *
*****
*/
void pattern21(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

/*
555555555
544444445
543333345
543222345
543212345
543222345
543333345
544444445
555555555
*/
void pattern22(int n)
{
    for(int i = 0; i < 2 * n - 1; i++)
    {
        for(int j = 0; j < 2 * n - 1; j++)
        {
            // Minimum distance from any side
            int top = i, left = j, bottom = 2 * n - 2 - i, right = 2 * n - 2 - j;
            cout << n - min(min(top, left), min(bottom, right));
        }
        cout << endl;
    }
}

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
    pattern11(n);
    cout << endl;
    pattern12(n);
    cout << endl;
    pattern13(n);
    cout << endl;
    pattern14(n);
    cout << endl;
    pattern15(n);
    cout << endl;
    pattern16(n);
    cout << endl;
    pattern17(n);
    cout << endl;
    pattern18(n);
    cout << endl;
    pattern19(n);
    cout << endl;
    pattern20(n);
    cout << endl;
    pattern21(n);
    cout << endl;
    pattern22(n);
    cout << endl;
    return 0;
}