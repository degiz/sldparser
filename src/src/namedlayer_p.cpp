#include "namedlayer_p.h"

#include "userstyle_p.h"

namespace SldParser {
    
NamedLayerPrivate::NamedLayerPrivate(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

NamedLayerPrivate::~NamedLayerPrivate()
{
    
}

const std::string NamedLayerPrivate::name() const
{
    return _layerName;
}

const std::vector<UserStyle>& NamedLayerPrivate::userStyles() const
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
            UserStylePrivate userStyle(_iterator);
            UserStyle pub(userStyle);
            _userStyles.push_back(pub);
        }
    }
}
    
}