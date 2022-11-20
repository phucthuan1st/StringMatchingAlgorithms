#include "stringMatching.h"

void rabin_Karp(string P, string T, ull &count_Assign, ull &count_Compare)
{
    ull m = P.length();
    ++count_Assign; // length of pattern
    ull n = T.length();
    ++count_Assign; // length of text
    ull q = 128;
    ++count_Assign;
    ull x = 11;
    ++count_Assign; // typically prime - multiplier
    ull x_m = 1;
    ++count_Assign; // x^(m-1) used for next hash computation
    ull hash_P = 0;
    ++count_Assign;
    ull hash_T = 0;
    ++count_Assign;

    ++count_Assign;
    for (ull i = 0; ++count_Compare && i < m - 1; ++count_Assign && i++)
    {
        x_m = (x_m * x) % q;
        ++count_Assign;
    }

    // hash of pattern and first window of text
    ++count_Assign;
    for (ull i = 0; ++count_Compare && i < m; ++count_Assign && i++)
    {
        hash_P = (hash_P * x + P[i]) % q;
        ++count_Assign;
        hash_T = (hash_T * x + T[i]) % q;
        ++count_Assign;
    }

    ++count_Assign;
    for (ull i = 0; ++count_Compare && i < n - m + 1; ++count_Assign && i++)
    {
        if (++count_Compare && hash_P == hash_T)
        { // possible match
            bool found = true;
            ++count_Assign;
            // character by character match
            ++count_Assign;
            for (ull j = 0; ++count_Compare && j < m; ++count_Assign && j++)
            {
                if (++count_Compare && P[j] != T[i + j])
                {
                    found = false;
                    ++count_Assign;
                    break;
                }
            }
            if (++count_Compare && found)
                cout << "Match at index " << i << endl;
        }
        // if it was not last window, then continue hash computation
        if (++count_Compare && i < n - m)
        {
            hash_T = (x * (hash_T - T[i] * x_m) + T[i + m]) % q;
            ++count_Assign;
            if (++count_Compare && hash_T < 0)
                hash_T += q;
            ++count_Assign;
        }
    }
}