#include "stringMatching.h"

void runTestBruteForce(string pattern, string data)
{
    int count_assign = 0;
    int count_compare = 0;

    search_count(pattern, data, count_assign, count_compare);

    fstream fout("Bruteforce.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << endl;
    fout.close();
}

void runTestKMP(string pattern, string data)
{
    int count_assign = 0;
    int count_compare = 0;

    KMP(pattern, data, count_assign, count_compare);

    fstream fout("KMP.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << endl;
    fout.close();
}

void runTestRabinKarp(string pattern, string data)
{
    ull count_assign = 0;
    ull count_compare = 0;

    rabin_Karp(pattern, data, count_assign, count_compare);

    fstream fout("RabinKarp.csv", ios::app);
    fout << pattern.length() << "," << data.length() << "," << count_assign << ","
         << count_compare << endl;
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

    fstream fout("Bruteforce.csv", ios::out);
    fout << "Pattern length"
         << ","
         << "Data length"
         << ","
         << "Number of assign"
         << ","
         << "Number of compare"
         << endl;
    fout.close();
    fout.open("KMP.csv", ios::out);
    fout << "Pattern length"
         << ","
         << "Data length"
         << ","
         << "Number of assign"
         << ","
         << "Number of compare"
         << endl;
    fout.close();
    fout.open("RabinKarp.csv", ios::out);
    fout << "Pattern length"
         << ","
         << "Data length"
         << ","
         << "Number of assign"
         << ","
         << "Number of compare"
         << endl;
    fout.close();

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