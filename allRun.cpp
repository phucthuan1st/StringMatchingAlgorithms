#include "stringMatching.h"

void runTestBruteForce(string pattern, string data)
{
    int count_assign = 0;
    int count_compare = 0;

    auto start = clock();
    search_count(pattern, data, count_assign, count_compare);
    auto end = clock();
    auto time = double(end - start) / CLOCKS_PER_SEC;

    fstream fout("Bruteforce.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << "," << time * 1000 << "ms" << endl;
    fout.close();
}

void runTestKMP(string pattern, string data)
{
    int count_assign = 0;
    int count_compare = 0;

    auto start = clock();
    KMP(pattern, data, count_assign, count_compare);
    auto end = clock();
    auto time = double(end - start) / CLOCKS_PER_SEC;

    fstream fout("KMP.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << "," << time * 1000 << "ms" << endl;
    fout.close();
}

void runTestRabinKarp(string pattern, string data)
{
    ull count_assign = 0;
    ull count_compare = 0;

    auto start = clock();
    rabin_Karp(pattern, data, count_assign, count_compare);
    auto end = clock();
    auto time = double(end - start) / CLOCKS_PER_SEC;

    fstream fout("RabinKarp.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << "," << time * 1000 << "ms" << endl;
    fout.close();
}

int main()
{
    vector<string> patterns;
    fstream file("patterns.txt", ios::in);

    //----------------- READ PATTERN --------------------------------
    string temp;

    while (getline(file, temp))
    {
        patterns.push_back(temp);
    }

    file.close();

    stringstream buffer;

    //----------------- handle small data --------------------------------
    file.open("small-data.txt", ios::in);
    buffer << file.rdbuf();

    for (auto pattern : patterns)
    {
        runTestBruteForce(pattern, buffer.str());
        runTestKMP(pattern, buffer.str());
        runTestRabinKarp(pattern, buffer.str());
    }
    file.close();

    //----------------- handle medium data --------------------------------
    file.open("medium-data.txt", ios::in);
    buffer << file.rdbuf();

    for (auto pattern : patterns)
    {
        runTestBruteForce(pattern, buffer.str());
        runTestKMP(pattern, buffer.str());
        runTestRabinKarp(pattern, buffer.str());
    }
    file.close();

    //----------------- handle large data --------------------------------
    file.open("large-data.txt", ios::in);
    buffer << file.rdbuf();

    for (auto pattern : patterns)
    {
        runTestBruteForce(pattern, buffer.str());
        runTestKMP(pattern, buffer.str());
        runTestRabinKarp(pattern, buffer.str());
    }
    file.close();

    return 0;
}