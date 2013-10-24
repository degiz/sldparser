#include "namedlayer.h"

namespace automap {
    
NamedLayer::NamedLayer(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

NamedLayer::~NamedLayer()
{
    
}

std::string NamedLayer::name()
{
    return _layerName;
}

std::vector<UserStyle> NamedLayer::userStyles()
{
    return _userStyles;
}

void NamedLayer::_parseNode()
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