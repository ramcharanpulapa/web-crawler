#include<bits/stdc++.h>
#include "fetcher.h"
#include "parser.h"
#include "textExtractor.h"
#include "indexer.h"

using namespace std;

int main() {
    InvertedIndex index;

    string startUrl = "/cpp/container/vector";  
    string baseUrl = "https://en.cppreference.com/w";

    queue<string> toVisit;
    set<string> visited;

    toVisit.push(startUrl);

    int maxPages = 50;     
    int pagesVisited = 0;
    int maxDepth = 2;     

   
    queue<pair<string,int>> bfsQueue;
    bfsQueue.push({startUrl, 0});

    while (!bfsQueue.empty() && pagesVisited<maxPages) {
        
        auto [path, depth] = bfsQueue.front();
        bfsQueue.pop();

        if (visited.count(path)) continue;   
        if (depth > maxDepth) continue;       

        visited.insert(path);

        string fullUrl = baseUrl + path;
        cout << "[Depth " << depth << "] Crawling: " << fullUrl << endl;
        
        string html = fetchPage(fullUrl);     
        string text = extractText(html);
        string filename = "pages/"+to_string(pagesVisited)+".txt";
        ofstream out(filename);
        out<< "URL:"<<fullUrl<<"\n";
        out<<text;
        out.close();    
        addPageToIndex(index, fullUrl, text);
        pagesVisited++;       
        
        vector<string> links = extractLinks(html);
        for (auto& link : links) {
            if (!visited.count(link)) {
                bfsQueue.push({link, depth + 1});
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1500));
    }

    saveIndex(index, "index.txt");
    cout << "Index saved with " << index.size() << " unique words" << endl;


    return 0;
}