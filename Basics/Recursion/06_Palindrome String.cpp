// Statement 1 : Palindrome String
// GFG :

// Statement 2 : Valid Palindrome
// LeetCode :

// Statement 1
// Way - I (Iterative)
class Solution
{
public:
    int isPalindrome(string S)
    {
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (S[i] != S[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};

// Way - II (Recursive)
class Solution
{
    int check(string S, int start, int end)
    {
        if (start >= end)
            return 1;
        if (S[start] != S[end])
            return 0;
        return check(S, start + 1, end - 1);
    }

public:
    int isPalindrome(string S)
    {
        int n = S.size();
        return check(S, 0, n - 1);
    }
};

// Statement 2
// Way - I (Brute Force)
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string alphaNum;
        for (char &ch : s)
        {
            // Conversion of uppercase letters into lowercase letters
            if (ch >= 'A' && ch <= 'Z')
                ch += 32;
            // Storing all alphanumeric letters in another string
            if (isalnum(ch))
                alphaNum += ch;
        }
        string revString = alphaNum;
        // Reversing the alphaNum string and checking if it's Palindrome or not
        reverse(revString.begin(), revString.end());
        return alphaNum == revString; // returns true or false
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            // Go until a valid character is reached from the start
            while (!isalnum(s[i]) && i < j)
                i++;
            // Go until a valid character is reached from the end
            while (!isalnum(s[j]) && i < j)
                j--;
            // If characters are not equal, return false otherwise keep checking
            if (toupper(s[i]) != toupper(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
