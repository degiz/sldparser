#include "equaloperation.h"

namespace automap {

template<class T>
bool EqualOperation::check(Feature<T> feature)
{
    std::string name = _property.name();
    Variant value = feature.getFieldValue(name);
    if (value.asString() != "") {
        return value == _property.literal();
    }
}

}
