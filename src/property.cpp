#include "property.h"

namespace automap {
    
Property::Property(XmlIterator iterator) :
    SLDNode(iterator)
{
    _binaryCamparations.assign(&BinaryComparisonOpType[0], &BinaryComparisonOpType[0]+9);
    _logicOperations.assign(&LogicOpsType[0], &LogicOpsType[0]+3);
    
    if (std::find(_binaryCamparations.begin(), _binaryCamparations.end(), _nodeName) != _binaryCamparations.end()) {
        _type = Comparison;
    } else {
        _type = Logic;
    }
    
    _parseNode();
}

Property::~Property()
{
    
}

std::string Property::propertyName()
{
    return _propertyName;
}

std::string Property::literal()
{
    return _literal;
}

std::vector<Property> Property::properties()
{
    return _properties;
}

void Property::_parseNode()
{
    if (_type == Comparison) {
        _parseComaparison();
    } else {
        _parseLogic();
    }
}

void Property::_parseComaparison()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "PropertyName") {
        
            _propertyName = _iterator.value();
            
        } else if (_iterator.name() == "Literal") {
        
            _literal = _iterator.value();
            
        }
    }
}

void Property::_parseLogic()
{
    Property property(_iterator);
    _properties.push_back(property);
}
    
}