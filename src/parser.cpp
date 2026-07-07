#include "parser.h"
#include <regex>
#include<bits/stdc++.h>


vector<string> extractLinks(const string&html){
    vector<string>links;
    regex linkPattern("href=\"(/cpp/[^\"#?]*)\"");

    auto begin=sregex_iterator(html.begin(),html.end(),linkPattern);
    auto end=sregex_iterator();

    for(auto it=begin;it!=end;it++){
        smatch match=*it;
        links.push_back(match[1].str());
    }
     return links;
     
}