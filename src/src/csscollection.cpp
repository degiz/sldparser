#include "csscollection.h"

namespace SldParser {

CssCollection::CssCollection()
{

}
    
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
    while (_iterator.moveToNextNode()) {
        
        if (_iterator.name() == "CssParameter") {
            CssElement element(_iterator);
            _csselements.push_back(element);
        }
    }
}

std::vector<CssElement> CssCollection::cssElements()
{
    return _csselements;
}

}