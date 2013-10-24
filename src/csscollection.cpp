#include "csscollection.h"

namespace automap {
    
CssCollection::CssCollection(xmlNode* node) :
    SLDNode(node)
{
    _parseNode();
}

CssCollection::~CssCollection()
{
    
}

void CssCollection::_parseNode()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"CssParameter"))) {
            xmlAttr* attribute = currentElement->children->properties;
            xmlChar* value = xmlNodeListGetString(currentElement->doc, attribute->children, 1);
            std::string valueString = (char*)value;
            xmlFree(value);
            _css[valueString] = (char*)currentElement->children->content;
        }
        currentElement = currentElement->next;
    }
}

std::map<std::string, std::string> CssCollection::cssParametrs()
{
    return _css;
}

}