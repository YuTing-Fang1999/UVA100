#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

bool can[26], constrain[26][26], used[26];
char str[26];
void DFS(int index, int n)
{
    if (index == n)
    {
        str[index] = '\0';
        puts(str);
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (can[i] && !used[i])
        {
            //confirm contrain
            for (int j = 0; j < 26; ++j)
            {
                if (constrain[i][j] == 1 && used[j] == 1)
                    return;
            }
            str[index] = i + 'a';
            used[i] = 1;
            DFS(index + 1, n);
            used[i] = 0;
        }
    }
}
int main()
{
    stringstream ss;
    string line;
    char c1, c2;
    bool hasPrint = false;
    while (getline(cin, line))
    {
        //don't print if it is first line
        if (hasPrint)
            puts("");
        hasPrint = true;

        //init
        memset(can, 0, sizeof(can));
        memset(constrain, 0, sizeof(constrain));
        memset(used, 0, sizeof(used));
        //input variable
        ss.clear();
        ss << line;
        int n = 0;
        while (ss >> c1)
        {
            can[c1 - 'a'] = 1;
            n++;
        }
        //input constrain
        getline(cin, line);
        ss.clear();
        ss << line;
        while (ss >> c1 >> c2)
        {
            constrain[c1 - 'a'][c2 - 'a'] = 1;
        }
        //dfs
        DFS(0, n);
    }
    return 0;
}
