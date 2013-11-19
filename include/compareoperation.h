#ifndef LOGIC_OPERATION_H
#define LOGIC_OPERATION_H

#include "filteroperation.h"
#include "feature.h"
#include "property.h"

#include <vector>

namespace automap {
    
class CompareOperation : public FilterOperation {

    CompareOperation(std::string, Variant);
    
protected:
    std::string _name;
    Variant _value;
};
    
}

#endif // LOGIC_OPERATION_H