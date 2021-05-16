#pragma once
#include "..\QueryBase.h"
#include "..\TextQuery.h"
#include "..\QueryResult.h"
#include "..\Query.h"
#include <memory>

class NotQuery: public QueryBase{
private:
    Query mQuery;
public:
    explicit NotQuery(const Query& query) : mQuery(query){}
    QueryResult eval(const TextQuery& textQuery) const override ;

    friend Query operator~(const Query& query);
};

inline Query operator~(const Query& query){
    return Query(std::make_shared<NotQuery>(NotQuery(query)));
}

inline QueryResult NotQuery::eval(const TextQuery& textQuery) const {
    auto res = mQuery.eval(textQuery);
    QueryResult notRes;
    size_t lineNow = 1;
    for (auto line: res) {
        for (;lineNow < line; ++lineNow) {
            notRes.add(lineNow);
        }
        lineNow = line+1;
    }
    for (;lineNow <= textQuery.mLine.size(); ++lineNow) {
        notRes.add(lineNow);
    }
    return notRes;
}