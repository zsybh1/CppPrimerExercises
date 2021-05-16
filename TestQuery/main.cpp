#include <iostream>
#include "TextQuery.hpp"
#include "Query.hpp"
#include <fstream>
#include "QueryType/AndQuery.hpp"
#include "QueryType/OrQuery.hpp"
#include "QueryType/NotQuery.hpp"

using namespace std;

int main() {
    TextQuery tq;
    ifstream fin(R"(D:\Coding\Cpp\CG\lib\easyxobject.h)");
    if (!fin.is_open()) {
        cout << "File Not Exists" << endl;
        return 0;
    }
    tq.load(fin);

    Query query = Query("float") & ~Query("=") | Query("colored_sphere");
    tq.show(cout, query.eval(tq));

    cout << "========================================================" << endl;

    Query qBool("bool");
    query = query & qBool;
    tq.show(cout, query.eval(tq));
}
