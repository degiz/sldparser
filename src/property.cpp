#include "property.h"

namespace automap {

Property::Property() :
    _literal("")
{

}
    
Property::Property(XmlIterator iterator) :
    SLDNode(iterator),
    _literal("")
{
    //_iterator.moveToParentNode();
    //_iterator.moveToPreviousNode();
    _parseNode();
}

Property::~Property()
{
    
}

std::string Property::name()
{
    return _propertyName;
}

Variant Property::literal()
{
    return _literal;
}

std::vector<Property> Property::properties()
{
    return _properties;
}

void Property::_parseNode()
{
    while (_iterator.moveToNextNode()) {
    
        //std::cout << "found node: << " << _iterator.name() << std::endl;
        
        if (_iterator.name() == "PropertyName") {
        
            _propertyName = _iterator.value();
            
        } else if (_iterator.name() == "Literal") {
        
            _literal = Variant(_iterator.value());
            
        }
    }
}
    
}