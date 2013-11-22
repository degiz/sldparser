#include "lessoperation.h"

namespace SldParser {
    
LessOperation::LessOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}

bool LessOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value < _value;
    }
    return false;
}
    
}
