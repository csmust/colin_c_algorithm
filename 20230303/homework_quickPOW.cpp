#include <iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n == -1)
            return 1 / x;
        else if (n % 2 == 1 || n % 2 == -1)
        {
            return x * (myPow(x, n - 1));
        }
        else
        {
            // 偶数
            double res;
            res = myPow(x, n / 2);
            res = res * res;
            return res;
        }
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.0, -3) << endl;
}