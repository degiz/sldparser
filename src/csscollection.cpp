#include "csscollection.h"

namespace automap {
    
CssCollection::CssCollection(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

CssCollection::~CssCollection()
{
    
}

void CssCollection::_parseNode()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "CssParameter") {
            
        }
    }
}

std::map<std::string, std::string> CssCollection::cssParametrs()
{
    return _css;
}

}