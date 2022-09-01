#include <bits/stdc++.h>
using namespace std;

class Bucket
{
public:
    double max = DBL_MIN;
    double min = DBL_MAX;
};

int main()
{
    ifstream in_file("D:\\algorithm\\max_gap\\input.txt");
    ofstream out_file("D:\\algorithm\\max_gap\\output.txt");
    int n;
    in_file >> n;
    double num[n];
    double max = DBL_MIN;
    double min = DBL_MAX;

    for (int i = 0; i < n; i++) //寻找输入最大值和最小值
    {
        in_file >> num[i];
        if (num[i] > max)
        {
            max = num[i];
        }
        if (num[i] < min)
        {
            min = num[i];
        }
    }

    double length = (max - min) / (n - 1); //计算桶宽度
    Bucket bucket[n];                      //桶数组
    for (int i = 0; i < n; i++)
    {                                         //将输入的数字放入桶
        int target = (num[i] - min) / length; //目标桶号
        if (bucket[target].min > num[i])
            bucket[target].min = num[i];
        if (bucket[target].max < num[i])
            bucket[target].max = num[i];
    }
    double max_gap = 0;          //最大间距
    double left = bucket[0].max; //保存区间左端点
    for (int i = 1; i < n; i++)
    {
        if (bucket[i].max > DBL_MIN) //桶中有数，bucket[i].max被覆盖
        {
            double temp_gap = bucket[i].min - left;
            if (temp_gap > max_gap)
                max_gap = temp_gap;
            left = bucket[i].max;
        }
    }
    out_file << max_gap;
}
