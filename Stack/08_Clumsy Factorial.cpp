// LeetCode : https://leetcode.com/problems/clumsy-factorial/description/

// Way - I (Brute Force)
/* Convert into an expression and use infix to postfix to evaluate the answer */

// Way - II (Better [Vector])
class Solution
{
public:
    int clumsy(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int curr = 1, ans = 1;
        vector<int> singleExpAns, sumElements;

        /* Evaluate every expression separately (* and /) and store them. Also, store the addition elements.*/
        while (n)
        {
            if (curr % 4 == 1)
                ans = n * (n - 1);
            else if (curr % 4 == 2)
                ans /= (n - 1);
            else if (curr % 4 == 3)
                sumElements.push_back(n - 1);
            else
            {
                singleExpAns.push_back(ans);
                // Specificity for n = 2, as it will not be included in the singleExpAns
                if (n == 2)
                    singleExpAns.push_back(1);
                ans = 0;
            }
            curr++;
            n--;
            if (n - 1 == 0)
                break;
        }

        // If case 4(-) is not executed, and there's some answer stored in ans, then push it to singleExpAns
        if (ans != 0)
            singleExpAns.push_back(ans);

        // Minus all the elements of singleExpAns
        ans = singleExpAns[0];
        for (int i = 1; i < singleExpAns.size(); i++)
            ans -= singleExpAns[i];

        // Add all the elements of sumElements
        for (int i = 0; i < sumElements.size(); i++)
            ans += sumElements[i];

        return ans;
    }
};

// Way - III (Stack)
class Solution
{
public:
    int clumsy(int n)
    {
        stack<int> st;
        st.push(n--);
        int idx = 0;
        // Evaluate the *, / expressions, then push +, - elements separately
        while (n)
        {
            if (idx % 4 == 0)
                st.top() *= n;
            else if (idx % 4 == 1)
                st.top() /= n;
            else if (idx % 4 == 2)
                st.push(n);
            else
                st.push(-n);
            idx++;
            n--;
        }
        // At the end, add all the elements of the stack
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Way - IV (Mathematical)
class Solution
{
public:
    int clumsy(int n)
    {
        int sign = 1;
        long long ans = 0;
        for (int i = n; i > 0; i -= 4)
        {
            long long temp = i;
            if (i - 1 > 0)
                temp *= i - 1;
            if (i - 2 > 0)
                temp /= i - 2;
            ans += sign * temp;
            if (i - 3 > 0)
                ans += i - 3;
            sign = -1;
        }
        return (int)ans;
    }
};

// Way - V (Mathematical [Constant Time])
class Solution
{
public:
    int clumsy(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return n + 3;
        if (n == 4)
            return n + 3;
        if (n % 4 == 1)
            return n + 2;
        if (n % 4 == 2)
            return n + 2;
        if (n % 4 == 3)
            return n - 1;
        return n + 1;
    }
};
