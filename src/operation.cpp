 #include "operation.h"

#include "andoperation.h"
#include "oroperation.h"
#include "notoperation.h"
#include "equaloperation.h"
#include "greateroperation.h"
#include "lessoperation.h"
#include "greaterorequaloperation.h"
#include "lessorequaloperation.h"

namespace automap {

const char* Operation::_binaryComparisonOpType[] = {
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

const char* Operation::_logicOpsType[] = {
    "And",
    "Or",
    "Not"
};

Operation::Operation()
{

}

Operation::Operation(XmlIterator iterator) :
    SLDNode(iterator),
    _filter(NULL)
{
    _parseNode();
}

Operation::Operation(XmlIterator iterator, FilterOperation* filter) :
    SLDNode(iterator),
    _filter(filter)
{
    _parseNode();
}

Operation::~Operation()
{
    if (_filter) {
        delete _filter;
    }
}

bool Operation::check(IFeature& feature)
{
    return _filter->check(feature);
}

bool Operation::check(FeatureProperty& feature)
{
    
}

bool Operation::isLogicOperation(std::string name)
{
    static std::vector<std::string> logicOperations;
    logicOperations.assign(&_logicOpsType[0], &_logicOpsType[0] + NUM_OF_LOGIC_OPERATIONS);
    return std::find(logicOperations.begin(), logicOperations.end(), name) != logicOperations.end();
}

bool Operation::isCompareOperation(std::string name)
{
    static std::vector<std::string> compareOperations;
    compareOperations.assign(&_binaryComparisonOpType[0], &_binaryComparisonOpType[0] + NUM_OF_COMPARE_OPERATIONS);
    return std::find(compareOperations.begin(), compareOperations.end(), name) != compareOperations.end();
}

void Operation::_parseNode()
{
    XmlIterator it(_iterator);
    
    if (isCompareOperation(_nodeName)) {
        it.moveToParentNode();
        it.moveToPreviousNode();
    }
    
    while (it.moveToNextNode()) {
    
        FilterOperation* filter = NULL;
    
        if (isCompareOperation(_nodeName)) {
            
            Property property(it);
            _property = property;
            
            if (_nodeName == "PropertyIsEqualTo") {
            
                filter = new EqualOperation(_property.name(), _property.literal());
            
            } else if (_nodeName == "PropertyIsLessThan") {
                
                filter = new LessOperation(_property.name(), _property.literal());
                
            } else if (_nodeName == "PropertyIsGreaterThan") {
                
                filter = new GreaterOperation(_property.name(), _property.literal());
                
            } else if (_nodeName == "PropertyIsGreaterThanOrEqualTo") {
                
                filter = new GreaterOrEqualOperation(_property.name(), _property.literal());
                
            } else if (_nodeName == "PropertyIsLessThanOrEqualTo") {
                
                filter = new LessOrEqualOperation(_property.name(), _property.literal());
                
            }
            
            if (_filter) {
                reinterpret_cast<LogicOperation*>(_filter)->add(filter);
            } else {
                _filter = filter;
            }
            
            break;
            
        } else if (isLogicOperation(_nodeName)) {
        
            if (_nodeName == "And") {
             
                filter = new AndOperation();
                
            } else if (_nodeName == "Or") {
                
                filter = new OrOperation();
                
            } else if (_nodeName == "Not") {
                
                filter = new NotOperation();
                
            }
            
             Operation operation(it, filter);
            _operations.push_back(operation);
            
            _filter = filter;
        
        }

        
    }
}



}

