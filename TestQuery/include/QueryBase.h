#pragma once
#include "TextQuery.h"
#include "QueryResult.h"

class QueryBase{
public:
    virtual QueryResult eval(const TextQuery & TextQuery) const= 0;
    virtual ~QueryBase() = default;
};