Coding Ninjas : 

// Way - I (Map)

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) 
{
    map<int, int> freq;
    vector<int> unionArr;
    for(int i : a)
        freq[i]++;
    
    for(int i : b)
        freq[i]++;
    
    for(auto it : freq)
        unionArr.push_back(it.first);

    return unionArr;
}


// Way - II (Set)

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    set<int> unionSet;
    vector<int> unionArr;
    for(int i : a)
        unionSet.insert(i);
    
    for(int i : b)
        unionSet.insert(i);
    
    for(auto it : unionSet)
        unionArr.push_back(it);

    return unionArr;
}


// Way - III (Two Pointers)
#include <bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) 
{
    vector<int> unionArr;
    int m = a.size(), n = b.size();
    int i = 0, j = 0;

    while(i < m && j < n)
    {
        if(a[i] <= b[j])
        {
            if( unionArr.empty() || a[i] != unionArr.back() )
                unionArr.push_back(a[i]);
            i++;
        }
        else
        {
            if(unionArr.empty() || b[j] != unionArr.back())
                unionArr.push_back(b[j]);
            j++;
        }
    }

    while(i < m)
    {
        if(unionArr.empty() || a[i] != unionArr.back())
            unionArr.push_back(a[i]);
        i++;
    }

    while(j < n)
    {
        if(unionArr.empty() || b[j] != unionArr.back())
            unionArr.push_back(b[j]);
        j++;
    }

    return unionArr;
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:

a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
b[7] =  {2, 3, 4, 4, 5, 11, 12}

i = 0, j = 0
m = 10, n = 7

--> 1
if(a[0] <= b[0]) (T)
if(Empty)
union = {1}
i = 1

--> 2
if(a[1] <= b[0]) (T)
if(2 != 1) (T)
union = {1, 2}
i = 2

--> 3
if(a[0] <= b[0]) (F)
else(T)
if(b[0] != 2) (F)
j = 1

--> 4
if(a[2] <= b[1]) (T)
if(3 != 2) (T)
union = {1, 2, 3}
i = 3

--> 5
if(a[3] <= b[1]) (F)
else
if(3 != 3) (F)
j = 2

--> 6
if(a[3] <= b[2]) (T)
if(4 != 3) (T)
union = {1, 2, 3, 4}
i = 4

--> 7
if(a[4] <= b[2]) (F)
else
if(4 != 4) (F)
j = 3

--> 8
if(a[4] <= b[3]) (F)
else
if(4 != 4) (F)
j = 4

--> 9
if(a[4] <= b[4]) (T)
if(5 != 4) (T)
union = {1, 2, 3, 4, 5}
i = 5

--> 10
if(a[5] <= b[4]) (F)
else
if(5 != 5) (F)
j = 5

--> 11
if(a[5] <= b[5]) (T)
if(6 != 5) (T)
union = {1, 2, 3, 4, 5, 6}
i = 6

--> 12
if(a[6] <= b[5]) (T)
if(7 != 6) (T)
union = {1, 2, 3, 4, 5, 6, 7}
i = 7

--> 13
if(a[7] <= b[5]) (T)
if(8 != 7) (T)
union = {1, 2, 3, 4, 5, 6, 7, 8}
i = 8

--> 14
if(a[8] <= b[5]) (T)
if(9 != 8) (T)
union = {1, 2, 3, 4, 5, 6, 7, 8, 9}
i = 9

--> 15
if(a[9] <= b[5]) (T)
if(10 != 9) (T)
union = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
i = 10

--------------------------------------
while(i < m) --> while(10 < 10) (F)

--------------------------------------
while(j < n) --> while(5 < 7) (T)

--> j = 5
if(11 != 10) (T)
union = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

--> j = 6
if(12 != 11) (T)
union = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

*/