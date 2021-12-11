#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
using namespace std;

void to_lower_case(string &str)
{
    for (int i = 0; i < str.size(); ++i)
        str[i] = tolower(str[i]);
}

void to_upper_case(string &str)
{
    for (int i = 0; i < str.size(); ++i)
        str[i] = toupper(str[i]);
}

int main()
{
    set<string> ignore;
    //�@�ӯ��ޥi�H�����h�Ӹ�ƭȡA�O�H���ު��j�p�Ӱ��ƦC�A�w�]�O�̯��ު�ASCII�X�Ѥp�ƨ�j
    multimap<string, string> titleMap;
    stringstream ss;

    string ignoreWord;
    while (cin >> ignoreWord && ignoreWord != "::")
    {
        ignore.insert(ignoreWord);
    }

    string line;
    while (getline(cin, line))
    {
        to_lower_case(line);

        ss.clear();
        ss << line;
        string word;
        int startIdx = 0;
        while (ss >> word)
        {
            //if word is not in ignore
            if (ignore.find(word) == ignore.end())
            {
                //�Nkeyword��j�g
                string title = line;
                to_upper_case(word);
                title.replace(startIdx, word.size(), word);
                titleMap.insert({word, title});
            }
            startIdx = startIdx + word.size() + 1;
        }
    }
    
    multimap<string, string>::iterator itr;
    for (itr = titleMap.begin(); itr != titleMap.end(); ++itr)
    {
        cout << itr->second << '\n';
    }
    return 0;
}
