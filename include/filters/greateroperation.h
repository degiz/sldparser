#ifndef GREATEROPERATION_H
#define GREATEROPERATION_H

#include "compareoperation.h"
#include "feature.h"

namespace automap {
    
class GreaterOperation : public CompareOperation {
public:
    GreaterOperation(std::string, Variant);
    bool check(IFeature&);
};
    
}

#endif // GREATEROPERATION_H