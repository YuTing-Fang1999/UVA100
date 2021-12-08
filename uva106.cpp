#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b) //��̤j������
{
   while ((a %= b) && (b %= a))
      ;
   return a + b;
}

int main()
{
   int N;
   while (cin >> N)
   {
      vector<bool> used(N + 5, false);
      int numTriples = 0;

      for (int i = 1; i <= (int)sqrt(N); ++i)
      {
         for (int j = i + 1;; j += 2) //i�Bj �����@�_�@��
         {
            if (gcd(i, j) != 1) //�̤j�����Ƥ���1
            {
               continue;
            }

            int x, y, z;
            x = j * j - i * i;
            y = 2 * j * i;
            z = j * j + i * i;

            if (x > N || y > N || z > N)
            {
               break;
            }

            ++numTriples;
            //�䦳�����ƪ�triple
            for (int otherX = x, otherY = y, otherZ = z;
                 otherX <= N && otherY <= N && otherZ <= N;
                 otherX += x, otherY += y, otherZ += z)
            {
               used[otherX] = used[otherY] = used[otherZ] = true;
            }
         }
      }

      int numNotUsed = 0;
      for (int i = 1; i <= N; ++i)
      {
         if (!used[i])
         {
            ++numNotUsed;
         }
      }

      printf("%d %d\n", numTriples, numNotUsed);
   }
   return 0;
}