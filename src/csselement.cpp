#include "csselement.h"

namespace automap {

CssElement::CssElement(XmlIterator iterator) :
    SLDNode(iterator)
{
    _iterator.moveToParentNode();
    _iterator.moveToPreviousNode();
    _parseNode();
}

CssElement::~CssElement()
{
    
}

void CssElement::_parseNode()
{
    
    if (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "CssParameter") {
            
            _name = _iterator.attributeName();
            _value = _iterator.attributeValue();
            
        }
    }
}

}