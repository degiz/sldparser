#include "namedlayer_p.h"

namespace automap {
    
NamedLayerPrivate::NamedLayerPrivate(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

NamedLayerPrivate::~NamedLayerPrivate()
{
    
}

std::string NamedLayerPrivate::name()
{
    return _layerName;
}

std::vector<UserStyle> NamedLayerPrivate::userStyles()
{
    return _userStyles;
}

void NamedLayerPrivate::_parseNode()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Name") {
            _layerName = _iterator.value();
        } else if (_iterator.name() == "UserStyle") {
            UserStyle userStyle(_iterator);
            _userStyles.push_back(userStyle);
        }
    }
}
    
}