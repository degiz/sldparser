#include "greateroperation.h"

namespace automap {
    
template<class T>
bool GreaterOperation::check(Feature<T> feature)
{
    std::string name = _property.name();
    Variant value = feature.getFieldValue(name);
    if (value.asString() != "") {
        return value > _property.literal();
    }   
}
    
}
