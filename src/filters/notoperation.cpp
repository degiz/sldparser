#include "notoperation.h"

namespace automap {
    
bool NotOperation::check(IFeature& feature) const
{
    return !_operations[0]->check(feature);
}
    
}