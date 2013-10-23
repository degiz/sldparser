#include "property.h"

namespace automap {
    
Property::Property(xmlNode* node) :
    SLDNode(node)
{
    _binaryCamparations.assign(&BinaryComparisonOpType[0], &BinaryComparisonOpType[0]+9);
    _logicOperations.assign(&LogicOpsType[0], &LogicOpsType[0]+3);
    
    if (std::find(_binaryCamparations.begin(), _binaryCamparations.end(), _nodeName) != _binaryCamparations.end()) {
        _type = Comparison;
    } else {
        _type = Logic;
    }
    
    _parseNode();
}

Property::~Property()
{
    
}

std::string Property::propertyName()
{
    return _propertyName;
}

std::string Property::literal()
{
    return _literal;
}

std::vector<Property> Property::properties()
{
    return _properties;
}

void Property::_parseNode()
{
    if (_type == Comparison) {
        _parseComaparison();
    } else {
        _parseLogic();
    }
}

void Property::_parseComaparison()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"PropertyName"))) {
            _propertyName = (char*)currentElement->children->content;
        } else if((!xmlStrcmp(currentElement->name, (const xmlChar *)"Literal"))) {
            _literal = (char*)currentElement->children->content;
        }
        currentElement = currentElement->next;
    }
}

void Property::_parseLogic()
{
    Property property(_node);
    _properties.push_back(property);
}
    
}