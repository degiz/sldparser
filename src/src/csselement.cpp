#include "csselement.h"

namespace SldParser {

CssElement::CssElement(XmlIterator iterator) :
    SLDNode(iterator),
    _value("")
{
    _iterator.moveToParentNode();
    _iterator.moveToPreviousNode();
    _parseNode();
}

CssElement::~CssElement()
{
    
}

std::string CssElement::name()
{
    return _name;
}

Variant CssElement::value()
{
    return _value;
}

void CssElement::_parseNode()
{
    
    if (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "CssParameter") {
            
            _name = _iterator.attributeName();
            _value = Variant(_iterator.value()).asString();
            
        }
    }
}

}