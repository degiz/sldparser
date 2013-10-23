#include "featuretypestyle.h"

namespace automap {

FeatureStyleType::FeatureStyleType(xmlNode* node) :
    SLDNode(node)
{
    _parseNode();
}

FeatureStyleType::~FeatureStyleType()
{
    
}

std::string FeatureStyleType::name()
{
    return _name;
}

std::string FeatureStyleType::title()
{
    return _title;
}

std::string FeatureStyleType::abstract()
{
    return _abstract;
}

std::string FeatureStyleType::featureTypeName()
{
    return _featureTypeName;
}

std::vector<std::string> FeatureStyleType::semanticTypeIdentifiers()
{
    return _semanticTypeIdentifiers;
}

std::vector<Rule> FeatureStyleType::rules()
{
    return _rules;
}

void FeatureStyleType::_parseNode()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Name"))) {
            _name = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Title"))) {
            _title = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Abstract"))) {
            _abstract = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"FeatureTypeName"))) {
           _featureTypeName = (char*)currentElement->children->content;
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"SemanticTypeIdentifier"))) {
            std::string semanticTypeIdentifier = (char*)currentElement->children->content;
            _semanticTypeIdentifiers.push_back(semanticTypeIdentifier);
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Rule"))) {
            Rule rule(currentElement);
            _rules.push_back(rule);
        }
        currentElement = currentElement->next;
    }
}
    
}