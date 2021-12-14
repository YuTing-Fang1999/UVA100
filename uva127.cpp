#include <iostream>
#include <stack>
using namespace std;

struct Card
{
   char face;
   char suit;
};

void print_pile(stack<Card> pile[52])
{
   for (int i = 0; i < 52; ++i)
   {
      printf("%d ", pile[i].size());
   }
   printf("\n");
}

bool match(Card c1, Card c2)
{
   return (c1.face == c2.face || c1.suit == c2.suit);
}

//略過空堆找左邊間隔leftNum的index
int find_left_idx(stack<Card> pile[52], int i, int leftNum)
{
   int count = 0;
   int now = i;
   while (--now >= 0)
   {
      if (!pile[now].empty())
      {
         count++;
         if (count == leftNum)
         {
            if (match(pile[now].top(), pile[i].top()))
               return now;
            else
               return -1;
         }
      }
   }
   return -1;
}

int main()
{

   stack<Card> pile[52];
   Card card;

   while (cin >> card.face && card.face != '#')
   {
      //clear stack
      for (int i = 0; i < 52; i++)
         while (!pile[i].empty())
            pile[i].pop();

      //input
      cin >> card.suit;
      pile[0].push(card);
      for (int i = 1; i < 52; ++i)
      {
         cin >> card.face >> card.suit;
         pile[i].push(card);
      }

      //start move
      for (int i = 0; i < 52; i++)
      {
         if (!pile[i].empty())
         {
            //先找左三
            int leftIdx = find_left_idx(pile, i, 3);
            //如果不行再找左一
            if (leftIdx == -1)
               leftIdx = find_left_idx(pile, i, 1);

            //如果可以移
            if (leftIdx != -1)
            {
               //move
               pile[leftIdx].push(pile[i].top());
               pile[i].pop();

               //挪完後要從此位置再繼續往左挪!
               i = leftIdx - 1;

               // print_pile(pile);
            }
         }
      }

      //print ans
      int pileNum = 0;
      for (int i = 0; i < 52; i++)
         if (!pile[i].empty())
            pileNum++;

      printf("%d pile", pileNum);
      if (pileNum > 1)
         printf("s");
      printf(" remaining:");
      for (int i = 0; i < 52; i++)
         if (!pile[i].empty())
            printf(" %d", pile[i].size());
      printf("\n");
   }
   return 0;
}
