#ifndef EQUALOPERATION_H
#define EQUALOPERATION_H

#include "compareoperation.h"
#include "feature.h"

namespace automap {
    
class GreaterOperation : public CompareOperation {
public:
    template<class T>
    bool check(Feature<T>);
    
};
    
}

#endif // EQUALOPERATION_H