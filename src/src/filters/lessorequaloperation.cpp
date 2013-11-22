#include "lessorequaloperation.h"

namespace SldParser {

LessOrEqualOperation::LessOrEqualOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}
    
bool LessOrEqualOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value <= _value;
    }
    return false;
}
    
}
