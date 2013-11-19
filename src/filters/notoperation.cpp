#include "notoperation.h"

namespace automap {
    
bool NotOperation::check(IFeature& feature)
{
    return !_operations[0]->check(feature);
}
    
}