#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int H, W;
   while (cin >> H >> W)
   {
      if (!H && !W)
         break;

      double C = log(H) / log(W); //�n�ϥ�double!

      //find N using binary search
      int L = 1, R = 2147483645, N = (L + R) / 2;
      double tar = log(N + 1) / log(N) - C; //�n�ϥ�double!
      while (L != R)
      {
         if (tar > 1e-8)
            L = N + 1;
         else if (tar < -1e-8)
            R = N;
         else
            break;
         N = (L + R) / 2;
         tar = log(N + 1) / log(N) - C;
      }
      //compute k
      int k = round(log(H) / log(N + 1));// �n�Υ|�ˤ��J! 

      int NWC = 0; //not working cat
      int MC = 1;  //more cat
      int AH = H;  //all height

      for (int i = 0; i < k; ++i)
      {
         NWC += MC; //1+ ...+N^(k-1)

         MC *= N;
         H /= N + 1;
         AH += H * MC;
      }
      cout << NWC << " " << AH << endl;
   }
}
