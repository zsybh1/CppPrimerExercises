#pragma once
#include "..\QueryBase.h"
#include "..\TextQuery.h"
#include "..\QueryResult.h"
#include "..\Query.h"
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