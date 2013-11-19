#include "andoperation.h"

namespace automap {

template<class T>
bool AndOperation::check(Feature<T> feature)
{
    for (auto i = _operations.begin(); i != _operations.end(); i++) {
        if (!(*i).check(feature)) {
            return false;
        }
    }
    return true;
}
    
}