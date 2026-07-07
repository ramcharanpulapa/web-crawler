#include<bits/stdc++.h>
using namespace std;

#include "textExtractor.h"



string extractText(const string& html) {
    string text = html;

    
    text = regex_replace(text, regex("<script[^>]*>([\\s\\S]*?)</script>"), " ");
    text = regex_replace(text, regex("<style[^>]*>([\\s\\S]*?)</style>"), " ");

   
    text = regex_replace(text, regex("<[^>]*>"), " ");

   
    text = regex_replace(text, regex("&amp;"), "&");
    text = regex_replace(text, regex("&lt;"), "<");
    text = regex_replace(text, regex("&gt;"), ">");
    text = regex_replace(text, regex("&nbsp;"), " ");

  
    text = regex_replace(text, regex("\\s+"), " ");

    return text;
}