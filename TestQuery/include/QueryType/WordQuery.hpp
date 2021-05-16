#pragma once
#include "..\QueryBase.hpp"
#include "..\TextQuery.hpp"
#include "..\QueryResult.hpp"
#include "..\Query.hpp"
#include <memory>

class WordQuery: public QueryBase{
private:
    std::string mWord;
public:
    explicit WordQuery(const std::string word) : mWord(word){}
    QueryResult eval(const TextQuery& textQuery) const override {
        return textQuery.query(mWord);
    }
};