#include "oroperation.h"

namespace automap {
    
bool OrOperation::check(IFeature& feature)
{
    for (auto i = _operations.begin(); i != _operations.end(); i++) {
        if ((*i)->check(feature)) {
            return true;
        }
    }
    return false;
}
    
}