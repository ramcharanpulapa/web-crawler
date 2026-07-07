#include "tokenizer.h"
#include <bits/stdc++.h>

using namespace std;


vector<string> tokenize(const string& text) {
    vector<string> tokens;
    string current;

    for (char c : text) {
        if (isalnum((unsigned char)c)) {
            current += tolower((unsigned char)c);
        } else {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }
    }
    if (!current.empty()) {
        tokens.push_back(current);
    }

    return tokens;
}