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
    
    virtual bool check(IFeature&) const;
};

}

#endif // FILTEROPERATION