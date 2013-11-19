#ifndef NOT_EQUAL_OPERATION_H
#define NOT_EQUAL_OPERATION_H

#include "compareoperation.h"

namespace automap {

class NotEqualOperation : public CompareOperation {
public:
    NotEqualOperation(std::string, Variant);
    bool check(IFeature&) const;
};

}

#endif // NOT_EQUAL_OPERATION_H