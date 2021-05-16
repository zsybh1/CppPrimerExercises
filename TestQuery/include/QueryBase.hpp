#pragma once
#include "TextQuery.hpp"
#include "QueryResult.hpp"

class QueryBase{
public:
    virtual QueryResult eval(const TextQuery & TextQuery) const= 0;
    virtual ~QueryBase() = default;
};