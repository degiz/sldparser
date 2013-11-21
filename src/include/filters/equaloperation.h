#ifndef EQUALOPERATION_H
#define EQUALOPERATION_H

#include "compareoperation.h"

namespace SldParser {

class EqualOperation : public CompareOperation {
public:
    EqualOperation(std::string, Variant);
    bool check(IFeature&) const;
};

}

#endif // EQUALOPERATION_H