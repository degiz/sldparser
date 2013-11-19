#ifndef EQUALOPERATION_H
#define EQUALOPERATION_H

#include "compareoperation.h"

namespace automap {

class EqualOperation : public CompareOperation {
public:
    EqualOperation(std::string, Variant);
    bool check(IFeature&);
};

}

#endif // EQUALOPERATION_H