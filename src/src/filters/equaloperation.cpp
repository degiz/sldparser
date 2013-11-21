#include "equaloperation.h"

namespace SldParser {

EqualOperation::EqualOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}

bool EqualOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value == _value;
    }
}

}
