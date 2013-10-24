#include "filter.h"

namespace automap {

Filter::Filter(XmlIterator iterator) :
    SLDNode(iterator)
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
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
        std::string nodeName = _iterator.name();
        
        if ((std::find(_binaryCamparations.begin(), _binaryCamparations.end(), nodeName) != _binaryCamparations.end()) ||
            (std::find(_logicOperations.begin(), _logicOperations.end(), nodeName) != _logicOperations.end())) {
 
             Property property(_iterator);
            _properties.push_back(property);
            
        } else if (_iterator.name() =="FeatureId") {
            _featureId = _iterator.attributeValue();
        }
    }
}

std::vector<Property> Filter::properties()
{
    return _properties;
}

}