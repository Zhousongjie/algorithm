#include <bits/stdc++.h>
using namespace std;

class Mooncake
{
public:
    double store;
    double sell;
    double price;
} cake[1010];
bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}
int main()
{
    int n;
    double D;
    scanf("%d %lf", &n, &D);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= D)
        {
            D -= cake[i].store;
            ans += cake[i].sell;
        }
        else
        {
            ans += cake[i].price * D;
            break;
        }
    }
    printf("%.2f\n", ans);
}