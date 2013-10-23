#include "rule.h"

#include <sstream>

namespace automap {
    
Rule::Rule(xmlNode* node) :
    SLDNode(node)
{
    
}

Rule::~Rule()
{
    
}

std::string Rule::name()
{
    return _name;
}

std::string Rule::title()
{
    return _title;
}

std::string Rule::abstract()
{
    return _abstract;
}

double Rule::minScaleDenominator()
{
    return _minScaleDenominator;
}

double Rule::maxScaleDenominator()
{
    return _maxScaleDenominator;
}

void Rule::_parseNode()
{
    xmlNode* currentElement = _node->children;
   
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Name"))) {
            _name = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Title"))) {
            _title = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Abstract"))) {
            _abstract = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"MinScaleDenominator"))) {
            std::istringstream scale((char*)currentElement->children->content);
            scale >> _minScaleDenominator;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"MaxScaleDenominator"))) {
            std::istringstream scale((char*)currentElement->children->content);
            scale >> _maxScaleDenominator;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Filter"))) {
            
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Symbolizer"))) {
            
        }
        currentElement = currentElement->next;
    }

}

}