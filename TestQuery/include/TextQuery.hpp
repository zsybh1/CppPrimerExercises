#pragma once
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "QueryResult.hpp"

class TextQuery{
public:
    void load(std::istream& input);
    void show(std::ostream& output, const QueryResult& query);
    const QueryResult& query(const std::string& word) const;
    std::vector<std::string> mLine;    // texts of lines
private:
    std::map<std::string, QueryResult> mWord;  // word, QueryResult
};
inline void TextQuery::load(std::istream& input) {
    std::string line;
    while (std::getline(input, line)) {
        mLine.push_back(line);
        std::istringstream ss(line);
        std::string word;
        while(ss >> word) {
            mWord[word].add(mLine.size());
        }
    }
}

inline void TextQuery::show(std::ostream& output, const QueryResult& query){
    for (auto line: query) {
        output << "line " << line << ": " << mLine[line - 1] << std::endl;
    }
}
 
inline const QueryResult& TextQuery::query(const std::string& word) const{
    static QueryResult NoResult;
    auto result = mWord.find(word);
    if (result != mWord.end()){
        return result->second;
    }
    else {
        return NoResult;
    }
}