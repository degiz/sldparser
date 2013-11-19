#ifndef FILTEROPERATION
#define FILTEROPERATION

#include <string>

#include "feature.h"
#include "variant.h"

namespace automap {

class FilterOperation {
public:
    FilterOperation();
    ~FilterOperation();
    
    virtual bool check(Feature*);
    
    virtual bool check(std::string&, Variant&) = 0;
};

}

#endif // FILTEROPERATION