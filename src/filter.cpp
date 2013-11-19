#include "filter.h"

namespace automap {

Filter::Filter()
{

}

Filter::Filter(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

Filter::~Filter()
{
    
}

template<class T>
bool Filter::check(Feature<T> feature)
{
    return _operation.check(feature);
}

bool Filter::check(FeatureProperty& feature)
{
    for (auto i = _operations.begin(); i != _operations.end(); i++) {
        if (!(*i).check(feature)) {
            return false;
        }
    }
    return true;
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

}