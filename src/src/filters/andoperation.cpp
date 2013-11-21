#include "andoperation.h"

namespace SldParser {

bool AndOperation::check(IFeature& feature) const
{
    for (auto it = _operations.begin(); it != _operations.end(); it++) {
        if (!(*it)->check(feature)) {
            return false;
        }
    }
    return true;
}
    
}