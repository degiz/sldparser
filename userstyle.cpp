#include "userstyle.h"

namespace automap {

UserStyle::UserStyle(xmlNode* node) :
    SLDNode(node)
{
    _parseNode();
}

UserStyle::~UserStyle()
{
    
}

std::string UserStyle::name()
{
    return _name;
}

std::string UserStyle::title()
{
    return _title;
}

std::string UserStyle::abstract()
{
    return _abstract;
}

bool UserStyle::isDefault()
{
    return _isDefault;
}

std::vector<FeatureStyleType> UserStyle::featureStyleTypes()
{
    return _features;
}

void UserStyle::_parseNode()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Name"))) {
            _name = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Title"))) {
            _title = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Abstract"))) {
            _abstract = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"IsDefault"))) {
            if (*(char*)currentElement->children->content == '1') {
                _isDefault = true;
            } else {
                _isDefault = false;
            }
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"FeatureTypeStyle"))) {
            FeatureStyleType feature(currentElement);
            _features.push_back(feature);
        }
        currentElement = currentElement->next;
    }
}

}

