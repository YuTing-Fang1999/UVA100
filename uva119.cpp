#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

int main()
{
   bool hasPrinted = false;
   int n;
   while (cin >> n)
   {
      //The output for each group should be separated from other groups by a blank line
      //要在這裡換行，真的是有夠怪der~
      if (hasPrinted)
         printf("\n");

      string name;
      vector<string> nameList;
      map<string, int> people;

      //init
      for (int i = 0; i < n; ++i)
      {
         cin >> name;
         people[name] = 0;
         nameList.push_back(name);
      }

      //start compute
      for (int i = 0; i < n; ++i)
      {

         string giver;
         cin >> giver;

         int price, giveNum;
         cin >> price >> giveNum;

         if (giveNum)
         {
            int givePrice = price / giveNum;
            people[giver] -= givePrice * giveNum;

            while (giveNum--)
            {
               string receiver;
               cin >> receiver;
               people[receiver] += givePrice;
            }
         }
      }

      //print ans
      for (int i = 0; i < n; ++i)
      {
         cout << nameList[i] << " " << people[nameList[i]] << endl;
      }
      hasPrinted = true;
   }

   return 0;
}
