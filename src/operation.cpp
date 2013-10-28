    #include "operation.h"

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
    SLDNode(iterator),
    _isLogicalOperation(false)
{
    /*if (isCompareOperation(_nodeName)) {
        _iterator.moveToParentNode();
        _iterator.moveToPreviousNode();
    }*/
    
    _parseNode();
}

Operation::~Operation()
{

}

bool Operation::isLogicalOperation()
{
    return _isLogicalOperation;
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

std::vector<Operation>& Operation::operations()
{
    return _operations;
}

std::vector<Property>& Operation::properties()
{
    return _properties;
}

void Operation::_parseNode()
{
    XmlIterator it(_iterator);
    
    if (isCompareOperation(_nodeName)) {
        it.moveToParentNode();
        it.moveToPreviousNode();
    }
    
    while (it.moveToNextNode()) {
    
        //std::cout << it.name() << std::endl;
        //std::cout << _nodeName << std::endl;
        
        if (isCompareOperation(_nodeName)) {
        
            Property property(it);
            _properties.push_back(property);
            break;
            
        } else if (isLogicOperation(_nodeName)) {
        
            _isLogicalOperation = true;
            Operation operation(it);
            _operations.push_back(operation);
            
        }
    }
}



}

