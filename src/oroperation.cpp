#include "oroperation.h"

namespace automap {
    
template<class T>
bool OrOperation::check(Feature<T> feature)
{
    for (auto i = _operations.begin(); i != _operations.end(); i++) {
        if ((*i).check(feature)) {
            return true;
        }
    }
    return false;
}
    
}