#include "operation.h"

#include "andoperation.h"
#include "oroperation.h"
#include "notoperation.h"
#include "equaloperation.h"
#include "greateroperation.h"
#include "lessoperation.h"

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

Operation::Operation(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

Operation::~Operation()
{

}

template<class T>
bool Operation::check(Feature<T> feature)
{
    
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
        
        Operation* operation = NULL;

        if (_nodeName == "And") {
         
            operation = new AndOperation(_iterator);
            
        } else if (_nodeName == "Or") {
            
            operation = new OrOperation(_iterator);
            
        } else if (_nodeName == "Not") {
            
            operation = new NotOperation(_iterator);
            
        } else if (_nodeName == "PropertyIsEqualTo") {
            
            operation = new EqualOperation(_iterator);
            
        } else if (_nodeName == "PropertyIsLessThan") {
            
            operation = new LessOperation(_iterator);
            
        } else if (_nodeName == "PropertyIsGreaterThan") {
            
            operation = new GreaterOperation(_iterator);
            
        }
        
        if (operation) {
            _operations.push_back(operation);
        }
    }
}



}

