#include "greateroperation.h"

namespace SldParser {

GreaterOperation::GreaterOperation(std::string name, Variant value) :
    CompareOperation(name, value)
{

}
    
bool GreaterOperation::check(IFeature& feature) const
{
    Variant value = feature.getFieldValue(_name);
    if (value.asString() != "") {
        return value > _value;
    }   
}
    
}
