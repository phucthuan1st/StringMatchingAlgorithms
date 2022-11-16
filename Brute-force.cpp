#include "stringMatching.h"

void search_time(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index " << i << endl;
    }
}

void search_count(string pat, string txt, int &count_Ass, int &count_Comp)
{
    int M = pat.length();
    int N = txt.length();
    count_Ass += 2;

    /* A loop to slide pat[] one by one */
    count_Ass++;
    for (int i = 0; ++count_Comp && i <= N - M; count_Ass++ && i++)
    {
        int j;
        count_Ass++;
        /* For current index i, check for pattern match */
        for (j = 0; ++count_Comp && j < M; count_Ass++ && j++)
            if (++count_Comp && txt[i + j] != pat[j])
                break;

        if (++count_Comp && j == M)
        {
        } // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
    }
}

// int main()
// {
//     int count_Ass = 0, count_Comp = 0;

//     string pat;
//     vector<string> pats;
//     string text;
//     vector<string> texts;

//     ifstream input_text("text.txt");
//     if (!input_text.is_open())
//     {
//         cerr << "Could not open the file - text.txt" << endl;
//         return EXIT_FAILURE;
//     }
//     while (getline(input_text, text))
//     {
//         texts.push_back(text);
//     }
//     input_text.close();

//     ifstream input_pat("pat.txt");
//     if (!input_pat.is_open())
//     {
//         cerr << "Could not open the file - pat.txt" << endl;
//         return EXIT_FAILURE;
//     }
//     getline(input_pat, pat);
//     input_pat.close();

//     clock_t begin = clock();
//     for (int i = 0; i < texts.size(); i++)
//     {
//         cout << "Line " << i + 1 << endl;
//         search_time(pat, texts[i]);
//         cout << endl;
//     }
//     clock_t end = clock();
//     cout << "Time run: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;

//     cout << endl;

//     for (int i = 0; i < texts.size(); i++)
//     {
//         search_count(pat, texts[i], count_Ass, count_Comp);
//     }
//     cout << "Assign: " << count_Ass << endl;
//     cout << "Compare: " << count_Comp << endl;
//     return 0;
// }