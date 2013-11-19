#ifndef GREATER_OR_EQUAL_OPERATION_H
#define GREATER_OR_EQUAL_OPERATION_H

#include "compareoperation.h"

namespace automap {

class GreaterOrEqualOperation : public CompareOperation {
public:
    GreaterOrEqualOperation(std::string, Variant);
    bool check(IFeature&) const;
};

}

#endif // GREATER_OR_EQUAL_OPERATION_H