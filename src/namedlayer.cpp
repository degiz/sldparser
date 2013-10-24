#include "namedlayer.h"

namespace automap {
    
NamedLayer::NamedLayer(xmlNode* node) :
    SLDNode(node)
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
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Name"))) {
            _layerName = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"UserStyle"))) {
            UserStyle userStyle(currentElement);
            _userStyles.push_back(userStyle);
        } 
        currentElement = currentElement->next;
    }
}
    
}