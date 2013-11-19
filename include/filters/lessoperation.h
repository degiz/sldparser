#ifndef LESSOPERATION_H
#define LESSOPERATION_H

#include "compareoperation.h"
#include "feature.h"

namespace automap {
    
class LessOperation : public CompareOperation {
public:
    template<class T>
    bool check(Feature<T>);
    
};
    
}

#endif // LESSOPERATION_H