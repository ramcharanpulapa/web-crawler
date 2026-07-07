#include "indexer.h"
#include "tokenizer.h"
#include "stopwords.h"
#include<bits/stdc++.h>

using namespace std;


void addPageToIndex(InvertedIndex& index, const string& url, const string& text) {
    vector<string> words = tokenize(text);

    for (auto& word : words) {
        if (STOP_WORDS.count(word)) continue;  
        if (word.size() < 2) continue;           
        index[word].insert(url);
    }
}

void saveIndex(const InvertedIndex& index, const string& filename) {
    ofstream out(filename);
    for (auto& [word, urls] : index) {
        out << word << "|";
        for (auto& url : urls) {
            out << url << ",";
        }
        out << "\n";
    }
}

InvertedIndex loadIndex(const string& filename) {
    InvertedIndex index;
    ifstream in(filename);
    string line;

    while (getline(in, line)) {
        size_t sep = line.find('|');
        if (sep == string::npos) continue;

        string word = line.substr(0, sep);
        string urlList = line.substr(sep + 1);

        stringstream ss(urlList);
        string url;
        while (getline(ss, url, ',')) {
            if (!url.empty()) index[word].insert(url);
        }
    }
    return index;
}