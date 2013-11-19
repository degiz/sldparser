#include "andoperation.h"

namespace automap {

bool AndOperation::check(IFeature& feature)
{
    for (auto it = _operations.begin(); it != _operations.end(); it++) {
        if (!(*it)->check(feature)) {
            return false;
        }
    }
    return true;
}
    
}