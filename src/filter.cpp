#include "filter.h"

namespace automap {

Filter::Filter(XmlIterator iterator) :
    SLDNode(iterator)
{
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
        
        if (Operation::isCompareOperation(nodeName) || Operation::isLogicOperation(nodeName)) {
        
            Operation operation(_iterator);
            _operations.push_back(operation);
            
        } else if (_iterator.name() =="FeatureId") {
        
            _featureId = _iterator.attributeValue();
            
        }
    }
}

std::vector<Operation> Filter::operations()
{
    return _operations;
}

}