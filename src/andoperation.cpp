#include "andoperation.h"

namespace automap {

bool AndOperation::check(std::string& name, Variant& value)
{
    for (auto it = _operations.begin(); it != _operations.end(); it++) {
        if (!(*it)->check(name, value)) {
            return false;
        }
    }
    return true;
}
    
}