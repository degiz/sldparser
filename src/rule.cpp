#include "rule.h"

#include <sstream>

namespace automap {
    
Rule::Rule(xmlNode* node) :
    SLDNode(node)
{
    _symbolizerTypes.assign(&SymbolizerType[0], &SymbolizerType[0]+4);
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

std::vector<Filter> Rule::filters()
{
    return _filters;
}

std::vector<Symbolizer> Rule::symbolizers()
{
    return  _symbolizers;
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
            Filter filter(currentElement);
            _filters.push_back(filter);
        } else {
            std::string name = (char*)currentElement->name;
            if (std::find(_symbolizerTypes.begin(), _symbolizerTypes.end(), name) != _symbolizerTypes.end()) {
                Symbolizer symbolizer(currentElement);
                _symbolizers.push_back(symbolizer);
            }
        }
        currentElement = currentElement->next;
    }
}

}