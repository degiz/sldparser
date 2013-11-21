#include "notoperation.h"

namespace SldParser {
    
bool NotOperation::check(IFeature& feature) const
{
    return !_operations[0]->check(feature);
}
    
}