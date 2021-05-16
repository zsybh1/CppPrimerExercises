#pragma once
#include <memory>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "QueryType/WordQuery.h"
#include <string>

class Query{
public:
    explicit Query(const std::string& word) : mQuery(std::make_shared<WordQuery>(word)){};
    Query(std::shared_ptr<QueryBase> query) : mQuery(query){};
    QueryResult eval(const TextQuery& textQuery) const{
        return mQuery->eval(textQuery);
    }
private:
    std::shared_ptr<QueryBase> mQuery;
};