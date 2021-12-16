#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Poly
{
   int x;
   int y;
   int coef;
};

void input_x_y(int &x, int &y, string &str, int &i)
{
   if (i < str.length())
   {
      char c = str[i];
      int v = 0;
      ++i;
      while ('0' <= str[i] && str[i] <= '9')
      {
         v = v * 10 + (int)(str[i] - '0');
         ++i;
      }
      if (c == 'x')
      {
         if (v == 0)
            x = 1;
         else
            x = v;
      }

      else if (c == 'y')
      {
         if (v == 0)
            y = 1;
         else
            y = v;
      }
   }
}

void input_poly(vector<Poly> &poly, string str)
{
   //   cout << str << endl;
   int x = 0;
   int y = 0;
   int coef = 0;

   int i = 1;
   while ('0' <= str[i] && str[i] <= '9')
   {
      coef = coef * 10 + (int)(str[i] - '0');
      ++i;
   }
   if (coef == 0)
      coef = 1;
   if (str[0] == '-')
      coef = -coef;

   input_x_y(x, y, str, i);
   input_x_y(x, y, str, i);

   //   printf("coef=%d, x=%d,y=%d\n", coef, x, y);

   Poly p;
   p.coef = coef;
   p.x = x;
   p.y = y;

   poly.push_back(p);
}

void input(vector<Poly> &poly, string str)
{
   if (str[0] != '-')
      str = "+" + str;

   int startIdx = 0;
   int subLen = 0;
   for (int i = 1; i < str.length(); ++i)
   {
      ++subLen;
      if (str[i] == '+' || str[i] == '-')
      {
         //         printf("%d %d\n", startIdx, subLen);
         input_poly(poly, str.substr(startIdx, subLen));
         startIdx += subLen;
         subLen = 0;
      }
   }
   input_poly(poly, str.substr(startIdx));
}

void print_poly(vector<Poly> poly)
{
   for (int i = 0; i < poly.size(); ++i)
   {
      printf("coef=%d, x=%d,y=%d\n", poly[i].coef, poly[i].x, poly[i].y);
   }
}

bool poly_cmp(Poly p2, Poly p1)
{
   //x decreasing
   if (p2.x > p1.x)
      return true;
   //y increasing
   if (p2.x == p1.x && p2.y < p1.y)
      return true;

   return false;
}
int main()
{
   string str;
   vector<Poly> poly1;
   vector<Poly> poly2;
   vector<Poly> poly3;
   while (getline(cin, str) && str != "#")
   {
      poly1.clear();
      poly2.clear();
      poly3.clear();

      input(poly1, str);

      getline(cin, str);
      input(poly2, str);

      // print_poly(poly1);
      // cout << endl;
      // print_poly(poly2);
      // cout << endl;

      for (int i = 0; i < poly1.size(); ++i)
      {
         for (int j = 0; j < poly2.size(); ++j)
         {
            Poly p;
            p.coef = poly1[i].coef * poly2[j].coef;
            p.x = poly1[i].x + poly2[j].x;
            p.y = poly1[i].y + poly2[j].y;
            poly3.push_back(p);
         }
      }

      sort(poly3.begin(), poly3.end(), poly_cmp);
      // print_poly(poly3);
      // cout << endl;

      char ans1[100], ans2[100];
      memset(ans1, ' ', sizeof(ans1));
      memset(ans2, ' ', sizeof(ans2));
      int nPos = 0;
      for (int i = 0; i < poly3.size();)
      {
         Poly p = poly3[i];
         ++i;
         while (p.x == poly3[i].x && p.y == poly3[i].y)
         {
            p.coef += poly3[i].coef;
            ++i;
         }

         if (p.coef != 0)
         {
            if (nPos > 0)
            {
               ++nPos;
               ans2[nPos++] = p.coef > 0 ? '+' : '-';
               ans2[nPos++] = ' ';
            }
            else
            {
               ans2[0] = '-';
               nPos += (p.coef < 0);
            }

            p.coef = abs(p.coef);
            if (p.coef != 1 || (p.x == 0 && p.y == 0))
            {
               nPos += sprintf(&ans2[nPos], "%d", p.coef);

               ans2[nPos] = ' ';
            }

            if (p.x > 0)
            {
               ans2[nPos++] = 'x';
               if (p.x > 1)
               {
                  nPos += sprintf(&ans1[nPos], "%d", p.x);
                  ans1[nPos] = ' ';
               }
            }
            if (p.y > 0)
            {
               ans2[nPos++] = 'y';
               if (p.y > 1)
               {
                  nPos += sprintf(&ans1[nPos], "%d", p.y);
                  ans1[nPos] = ' ';
               }
            }
         }
      }

      if (nPos == 0)
      {
         ans2[nPos++] = '0';
      }

      ans1[nPos] = ans2[nPos] = '\0';
      cout << ans1 << '\n'
           << ans2 << endl;
   }
   return 0;
}
