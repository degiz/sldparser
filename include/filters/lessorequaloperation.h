#ifndef LESS_OR_EQUAL_OPERATION_H
#define LESS_OR_EQUAL_OPERATION_H

#include "compareoperation.h"

namespace automap {

class LessOrEqualOperation : public CompareOperation {
public:
    LessOrEqualOperation(std::string, Variant);
    bool check(IFeature&) const;
};

}

#endif // LESS_OR_EQUAL_OPERATION_H