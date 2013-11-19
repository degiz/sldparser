#include "equaloperation.h"

namespace automap {

EqualOperation::EqualOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}

bool EqualOperation::check(IFeature& feature)
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value == _value;
    }
}

}
