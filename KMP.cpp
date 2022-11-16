// tham khảo: https://www.codespeedy.com/knuth-morris-pratt-kmp-algorithm-in-c/

#include "stringMatching.h"

void lps_func(string txt, vector<int> &lps, int &count_Ass, int &count_Cmp)
{
    lps[0] = 0;
    count_Ass++;
    int k = 0;
    count_Ass++;
    int i = 1;
    count_Ass++;

    while (++count_Cmp && i < txt.length())
    {
        if (++count_Cmp && txt[i] == txt[k])
        {
            k++;
            count_Ass++;
            lps[i] = k;
            count_Ass++;
            i++;
            count_Ass++;
        }
        else
        {
            if (++count_Cmp && k == 0)
            {
                lps[i] = 0;
                count_Ass++;
                i++;
                count_Ass++;
            }
            else
            {
                k = lps[k - 1];
                count_Ass++;
            }
        }
    }
}

vector<int> KMP(string pattern, string text, int &count_Ass, int &count_Cmp)
{
    int n = text.length();
    count_Ass++;
    int m = pattern.length();
    count_Ass++;

    vector<int> lps(m);
    vector<int> result;

    lps_func(pattern, lps, count_Ass, count_Cmp);

    int i = 0, j = 0;
    count_Ass += 2;

    while (++count_Cmp && i < n)
    {
        if (++count_Cmp && pattern[j] == text[i])
        {
            i++;
            j++;
            count_Ass += 2;
        }

        // P xuất hiện trong T
        if (++count_Cmp && j == m)
        {
            result.push_back(i - m);
            j = lps[j - 1];
            count_Ass++;
        }
        else if (++count_Cmp && i < n && pattern[j] != text[i])
        {
            if (++count_Cmp && j == 0)
            {
                i++;
                count_Ass++;
            }
            else
            {
                j = lps[j - 1];
                count_Ass++;
            }
        }
    }
    return result;
}

// int main()
// {
//     string text = "heheheheeheheheh";
//     string pattern = "h";

//     vector<int> res = KMP(pattern, text);
//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << res[i] << " ";
//     }

//     return 0;
// }