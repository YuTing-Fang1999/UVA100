#include <iostream>
#include <string>
#define INF 1e8
using namespace std;

int degree[26];
int path[26][26];
int allPathLen = 0;
bool isOddDegree = false;
int startV;
int endV; //�_�Ǩ��W��end uva�|CE�A�o�O����ųN 

int indexOf(char c)
{
   return (int)c - 'a'; //�qa�}�l��index�Aa��index��0
}

void init() //��l�ƩҦ��ܼ�
{
   for (int i = 0; i < 26; ++i)
   {
      degree[i] = 0;
      for (int j = 0; j < 26; ++j)
      {
         path[i][j] = INF;
      }
   }

   allPathLen = 0;
   isOddDegree = false;
   startV = -1;
   endV = -1;
}

int shortestPath(int start, int end)
{
   //Floyd-Warshall
   for (int k = 0; k < 26; ++k)
   {
      for (int i = 0; i < 26; ++i)
      {
         for (int j = 0; j < 26; ++j)
         {
            if (path[i][j] > path[i][k] + path[k][j])
               path[i][j] = path[i][k] + path[k][j];
         }
      }
   }
   return path[start][end];
}
int main()
{
   init();
   string input_str;
   while (cin >> input_str)
   {
      if (input_str == "deadend")
      {
         //�T�{�O�_���_�ƭ�degree
         for (int i = 0; i < 26; ++i)
            if (degree[i] % 2)
            {
               if (!isOddDegree)
               {
                  startV = i; //�O��_�I
                  isOddDegree = true;
               }
               else
               {
                  endV = i; //�O����I
                  break;
               }
            }

         if (isOddDegree) //�[�W�q���I�^�_�I���̵u���|
            allPathLen += shortestPath(startV, endV);

         //output answer
         cout << allPathLen << endl;

         //init for next input set
         init();
         continue; //���n�~�����U���A���M�|��deadend��i�h!
      }

      int len = input_str.length();
      int v1 = indexOf(input_str[0]);
      int v2 = indexOf(input_str[len - 1]);

      //compute degree
      degree[v1]++;
      degree[v2]++;

      //set path
      if (len < path[v1][v2])
      {
         path[v1][v2] = len;
         path[v2][v1] = len;
      }

      //compute allPathLen
      allPathLen += len;
   }
   return 0;
}
