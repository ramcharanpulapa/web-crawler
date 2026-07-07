#pragma once
#include<bits/stdc++.h>
using namespace std;


using InvertedIndex = unordered_map<string, unordered_set<string>>;

void addPageToIndex(InvertedIndex& index, const string& url, const string& text);
void saveIndex(const InvertedIndex& index, const string& filename);
InvertedIndex loadIndex(const string& filename);

