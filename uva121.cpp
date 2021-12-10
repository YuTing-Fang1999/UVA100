#include <iostream>
#include <cmath>

using namespace std;
int grid(float w, float h)
{
    return (int)w * (int)h;
}

int skew(float w, float h)
{
    int row = (h >= 1) + (int)((h - 1) / (sqrt(3) / 2));
    //�p�G (w - (int)w) < 0.5 ���Ƽh�|��1
    return ((int)w * row) - (int)(row / 2) * ((w - (int)w) < 0.5);
}
int main()
{
    float w, h;
    while (cin >> w >> h)
    {
        int n1 = grid(w, h);
        int n2 = max(skew(w, h), skew(h, w));
        if (n1 >= n2)
            printf("%d grid\n", n1);
        else
            printf("%d skew\n", n2);
    }

    return 0;
}
