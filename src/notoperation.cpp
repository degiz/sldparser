#include "notoperation.h"

namespace automap {
    
template<class T>
bool NotOperation::check(Feature<T> feature)
{
    return !_operations[0].check(feature);
}
    
}