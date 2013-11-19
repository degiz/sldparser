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

bool Filter::check(IFeature& feature) const
{
    return _operation.check(feature);
}

bool Filter::check(FeatureProperty& feature) const
{
    return _operation.check(feature);
}

void Filter::_parseNode()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
        std::string nodeName = _iterator.name();
        
        if (Operation::isCompareOperation(nodeName) || Operation::isLogicOperation(nodeName)) {
        
            Operation operation(_iterator);
            _operation = operation;
            
        } else if (_iterator.name() =="FeatureId") {
        
            _featureId = _iterator.attributeValue();
            
        }
    }
}

}