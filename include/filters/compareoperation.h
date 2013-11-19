#ifndef LOGIC_OPERATION_H
#define LOGIC_OPERATION_H

#include "operation.h"
#include "feature.h"

#include <vector>

namespace automap {
    
class CompareOperation : Operation {
    
protected:
    Property _property;
};
    
}

#endif // LOGIC_OPERATION_H