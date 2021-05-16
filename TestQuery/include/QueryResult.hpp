#pragma once
#include <set>
#include <iostream>

class QueryResult{
private:
    using Container = std::set<size_t>;
    using iterator = Container::iterator;
    Container mResult;
public:
    QueryResult() = default;
    void add(size_t lineNo) {
        mResult.insert(lineNo);
    }
    void remove(size_t lineNo) {
        mResult.erase(lineNo);
    }
    iterator begin() const{
        return mResult.begin();
    }
    iterator end() const{
        return mResult.end();
    }
    Container& getContainer() {
        return mResult;
    }
};