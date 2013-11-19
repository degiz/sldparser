#ifndef COMPAREOPERATION_H
#define COMPAREOPERATION_H

#include "filteroperation.h"

#include <vector>

namespace automap {
    
class CompareOperation : public FilterOperation {
public:
    CompareOperation(std::string, Variant);
protected:
    std::string _name;
    Variant _value;
};

}

#endif // COMPAREOPERATION_H