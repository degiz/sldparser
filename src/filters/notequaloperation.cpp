#include "notequaloperation.h"

namespace automap {

NotEqualOperation::NotEqualOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}

bool NotEqualOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value != _value;
    }
}

}
