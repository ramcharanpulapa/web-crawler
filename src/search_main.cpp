#include <bits/stdc++.h>
#include "indexer.h"

using namespace std;

int main() {
    cout << "Loading index..." << endl;
    InvertedIndex idx = loadIndex("index.txt");

    if (idx.empty()) {
        cout << "No index found. Run ./crawler first." << endl;
        return 1;
    }

    cout << "Loaded " << idx.size() << " unique words." << endl;
    cout << "─────────────────────────────────────\n";
    cout << "C++ Documentation Search Engine" << endl;
    cout << "Type a keyword to search. Type 'exit' to quit." << endl;
    cout << "─────────────────────────────────────\n";

    string query;
    while (true) {
        cout << "\nSearch: ";
        getline(cin, query);

        if (query == "exit") break;
        if (query.empty()) continue;


        for (auto& c : query) c = tolower(c);

        if (idx.count(query)) {
            auto& urls = idx[query];
            cout << "Found in " << urls.size() << " page(s):\n";
            for (auto& url : urls) {
                cout << "  → " << url << endl;
            }
        } else {
            cout << "No results found for \"" << query << "\"" << endl;
            cout << "Tip: try a related word " << endl;
        }
    }

   
    return 0;
}