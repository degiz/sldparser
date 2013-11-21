#ifndef GREATEROPERATION_H
#define GREATEROPERATION_H

#include "compareoperation.h"
#include "feature.h"

namespace SldParser {
    
class GreaterOperation : public CompareOperation {
public:
    GreaterOperation(std::string, Variant);
    bool check(IFeature&) const;
};
    
}

#endif // GREATEROPERATION_H