#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b) //т程そ计
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
         for (int j = i + 1;; j += 2) //ij ゲ案
         {
            if (gcd(i, j) != 1) //程そ计ぃ1
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
            //тΤそ计triple
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