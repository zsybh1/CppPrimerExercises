#pragma once
#include "..\QueryBase.hpp"
#include "..\TextQuery.hpp"
#include "..\QueryResult.hpp"
#include "..\Query.hpp"
#include <memory>
#include <algorithm>

class AndQuery: public QueryBase{
private:
    Query mFirst;
    Query mSecond;
public:
    AndQuery(const Query& firstQuery, const Query& secondQuery) : mFirst(firstQuery), mSecond(secondQuery){}
    QueryResult eval(const TextQuery& textQuery) const override ;

    friend Query operator&(const Query& firstQuery, const Query& secondQuery);
};

inline Query operator&(const Query& firstQuery, const Query& secondQuery){
    return Query(std::make_shared<AndQuery>(firstQuery, secondQuery));
}

inline QueryResult AndQuery::eval(const TextQuery& textQuery) const {
    auto firstRes = mFirst.eval(textQuery);
    auto secondRes = mSecond.eval(textQuery);
    QueryResult queryResult;
    std::set_intersection(firstRes.begin(), firstRes.end(),
                secondRes.begin(), secondRes.end(),
                std::inserter(queryResult.getContainer(), queryResult.begin()));
    return queryResult;
}