 #include "operation.h"

#include "andoperation.h"
#include "oroperation.h"
#include "notoperation.h"
#include "equaloperation.h"
#include "notequaloperation.h"
#include "greateroperation.h"
#include "lessoperation.h"
#include "greaterorequaloperation.h"
#include "lessorequaloperation.h"

namespace SldParser {

std::vector<std::string> Operation::_logicOpsType = {
    "And",
    "Or",
    "Not"
};

std::vector<std::string> Operation::_binaryComparisonOpType = {
    "PropertyIsEqualTo",
    "PropertyIsNotEqualTo",
    "PropertyIsLessThan",
    "PropertyIsGreaterThan",
    "PropertyIsLessThanOrEqualTo",
    "PropertyIsGreaterThanOrEqualTo",
    "PropertyIsLike",
    "PropertyIsNull",
    "PropertyIsBetween"
};

Operation::Operation()
{

}

Operation::Operation(XmlIterator iterator) :
    SLDNode(iterator),
    _filter(NULL),
    _hasParentFilter(false)
{
    _parseNode();
}

Operation::Operation(XmlIterator iterator, std::shared_ptr<FilterOperation> filter) :
    SLDNode(iterator),
    _filter(filter),
    _hasParentFilter(true)
{
    _parseNode();
}

Operation::~Operation()
{

}

bool Operation::check(IFeature& feature) const
{
    if (_filter) {
        return _filter->check(feature);
    } else {
        return true;
    }
}

bool Operation::check(FeatureProperty& feature) const
{
    
}

bool Operation::isLogicOperation(std::string name)
{
    return std::find(_logicOpsType.begin(), _logicOpsType.end(), name) != _logicOpsType.end();
}

bool Operation::isCompareOperation(std::string name)
{
    return std::find(_binaryComparisonOpType.begin(), _binaryComparisonOpType.end(), name) != _binaryComparisonOpType.end();
}

void Operation::_parseNode()
{
    XmlIterator it(_iterator);
    
    if (isCompareOperation(_nodeName)) {
        it.moveToParentNode();
        it.moveToPreviousNode();
    }
    
    while (it.moveToNextNode()) {
    
        std::shared_ptr<FilterOperation> filter;
    
        if (isCompareOperation(_nodeName)) {
            
            Property property(it);
            _property = property;
            
            if (_nodeName == "PropertyIsEqualTo") {
            
                filter.reset(new EqualOperation(_property.name(), _property.literal()));
            
            } else if (_nodeName == "PropertyIsNotEqualTo") {
                
                filter.reset(new NotEqualOperation(_property.name(), _property.literal()));
                
            } else if (_nodeName == "PropertyIsLessThan") {
                
                filter.reset(new LessOperation(_property.name(), _property.literal()));
                
            } else if (_nodeName == "PropertyIsGreaterThan") {
                
                filter.reset(new GreaterOperation(_property.name(), _property.literal()));
                
            } else if (_nodeName == "PropertyIsGreaterThanOrEqualTo") {
                
                filter.reset(new GreaterOrEqualOperation(_property.name(), _property.literal()));
                
            } else if (_nodeName == "PropertyIsLessThanOrEqualTo") {
                
                filter.reset(new LessOrEqualOperation(_property.name(), _property.literal()));
                
            }
            
            if (_filter) {
                reinterpret_cast<LogicOperation*>(_filter.get())->add(filter);
            } else {
                _filter = filter;
            }
            
            break;
            
        } else if (isLogicOperation(_nodeName)) {
        
            if (!_filter || _hasParentFilter) {
            
                if (_nodeName == "And") {
             
                    filter.reset(new AndOperation());
                
                } else if (_nodeName == "Or") {
                    
                    filter.reset(new OrOperation());
                    
                } else if (_nodeName == "Not") {
                    
                    filter.reset(new NotOperation());
                    
                }
                
                if (_hasParentFilter) {
                    reinterpret_cast<LogicOperation*>(_filter.get())->add(filter);
                }
                
                _filter = filter;
            }
            
             Operation operation(it, _filter);
            _operations.push_back(operation);
        
        }

        
    }
}



}

