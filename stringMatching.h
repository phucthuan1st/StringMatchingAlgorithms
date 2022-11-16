#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

typedef unsigned long long ull;

void search_time(string pat, string txt);
void search_count(string pat, string txt, int &count_Ass, int &count_Comp);
vector<int> KMP(string pattern, string text, int &count_Ass, int &count_Cmp);
void rabin_Karp(string P, string T, ull &count_Assign, ull &count_Compare);