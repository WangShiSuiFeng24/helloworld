#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

void show(map<int, vector<string>> g);

int main()
{
    int n, count = 0;
    vector<string> vec;
    map<int, vector<string>> group;
    string temp;

    // 装入数据
    while (cin >> n && n > 0 && count < 5)
    {
        while (cin.get() != '\n')
            continue;

        vec.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            vec.push_back(temp);
        }
        group[count] = vec;
        count++;
    }
    // 查看数据
    // for (int i = 0; i < count; ++i)
    // {
    //     cout << group[i].size() << endl;
    //     for (int j = 0; j < group[i].size(); ++j)
    //         cout << group[i][j] << endl;
    // }

    // 处理数据 count组数据
    for (int i = 0; i < count; ++i)
    {
        vec = group[i];
        int min_str_lenth = vec[0].size();
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[j].size() < min_str_lenth)
                min_str_lenth = vec[j].size();
        }

        // cout << "The " << i + 1 << " group strings's min lenth is " << min_str_lenth << endl;

        int index;
        string same;
        // 处理数据 第i组 vector
        // cout << "Start processing the " << i + 1 << "st group strings!" << endl;
        for (index = 0; index < min_str_lenth; ++index)
        {
            temp = vec[0];
            char ch = *(temp.end() - index - 1);
            // cout << "The current compare character is " << ch << endl;
            int k;
            for (k = 1; k < vec.size(); ++k)
            {
                temp = vec[k];
                if (ch != *(temp.end() - index - 1))
                    break;
            }
            if (k < vec.size())
            {
                if (index == 0)
                    printf("\n");
                else
                {
                    reverse(same.begin(), same.end());//输出相同的字符
                    cout << same << endl;
                }
                break;
            }
            // 保存当前相同后缀字符
            // cout << ch << " is added." << endl;
            same.push_back(ch);

            if (min_str_lenth == 1)
            {
                reverse(same.begin(), same.end());//输出相同的字符
                cout << same << endl;
            }
        }
    }
    return 0;
}

// const int N = 200;
// int n;
// string str[N];

// int main()
// {
//     while (cin >> n, n)
//     {
//         int len = 200;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> str[i];
//             if (len < str[i].size())
//                 len = str[i].size();
//         }
//         bool success = true;
//         while (len)
//         {

//             for (int i = 1; i < n; i++)
//             {
//                 bool is_same = true;
//                 for (int j = 1; j <= len; j++)
//                 {
//                     if (str[0][str[0].size() - j] != str[i][str[i].size() - j])
//                     {
//                         is_same = false;
//                         break;
//                     }
//                 }

//                 if (!is_same)
//                 {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success)
//                 break;

//             len--;
//         }

//         cout << str[0].substr(str[0].size() - len) << endl;
//     }

//     return 0;
// }