#include <bits/stdc++.h>
using namespace std;

// const int maxn = 100000;
// int sum[maxn] = {0};
int main()
{
    int num, score, school_id;
    vector<int> sum(100001); 
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> school_id >> score;
        sum[school_id] += score;
    }
    // int *place=max_element(sum,sum+num+1);
    // vector<int>::iterator place=max_element(sum.begin(),sum.end());
    auto place=max_element(sum.begin(),sum.end());
    cout <<place-sum.begin()  << " " << *place;
    // printf("%d %d",place - sum,*place);
    // int k = 1, MAX = -1;
    // for (int i = 1; i <= num; i++)
    // {
    //     if (sum[i] > MAX)
    //     {
    //         MAX = sum[i];
    //         k = i;
    //     }
    // }
    // cout << k << " " << MAX;
}