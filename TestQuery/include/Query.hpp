#pragma once
#include <memory>
#include "QueryBase.hpp"
#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include "QueryType/WordQuery.hpp"
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