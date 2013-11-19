#include "greaterorequaloperation.h"

namespace automap {
  
GreaterOrEqualOperation::GreaterOrEqualOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}

bool GreaterOrEqualOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value >= _value;
    }
}
  
}
