#include "filter.h"

namespace automap {

Filter::Filter(xmlNode* node) :
    SLDNode(node)
{
    _binaryCamparations.assign(&BinaryComparisonOpType[0], &BinaryComparisonOpType[0]+9);
    _logicOperations.assign(&LogicOpsType[0], &LogicOpsType[0]+3);
    
    _parseNode();
}

Filter::~Filter()
{
    
}

void Filter::_parseNode()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        std::string nodeName = (char*)currentElement->name;
        
        if ((std::find(_binaryCamparations.begin(), _binaryCamparations.end(), nodeName) != _binaryCamparations.end()) ||
            (std::find(_logicOperations.begin(), _logicOperations.end(), nodeName) != _logicOperations.end())) {
 
             Property property(currentElement);
            _properties.push_back(property);
            
        } else if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"FeatureId"))) {
            xmlAttr* attribute = currentElement->children->properties;
            xmlChar* value = xmlNodeListGetString(currentElement->doc, attribute->children, 1);
            _featureId = (char*)value;
            xmlFree(value);
        }
        currentElement = currentElement->next;
    }
}

std::vector<Property> Filter::properties()
{
    return _properties;
}

}