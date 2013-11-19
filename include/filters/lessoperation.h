#ifndef LESSOPERATION_H
#define LESSOPERATION_H

#include "compareoperation.h"
#include "feature.h"

namespace automap {
    
class LessOperation : public CompareOperation {
public:
    LessOperation(std::string, Variant);
    bool check(IFeature&);
    
};
    
}

#endif // LESSOPERATION_H