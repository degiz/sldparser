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

Property Operation::property()
{
    return _property;
}

bool Operation::check(Feature& feature)
{
    if (_isLogicalOperation) {
        if (_nodeName == "And") {
            for (auto i = _operations.begin(); i != _operations.end(); i++) {
                if (!(*i).check(feature)) {
                    return false;
                }
            }
        } else if (_nodeName == "Or") {
            for (auto i = _operations.begin(); i != _operations.end(); i++) {
                if ((*i).check(feature)) {
                    return true;
                }
            }
        } else if (_nodeName == "Not") {
            return !check(feature);
        }
    } else {
        bool found, matches = false;
        for (auto i = _operations.begin(); i != _operations.end(); i++) {
            if ((*i).property().name() == feature.name) {
                found = true;
                if (_nodeName == "PropertyIsEqualTo") {
                    matches = feature.value == (*i).property().literal();
                } else if (_nodeName == "PropertyIsNotEqualTo") {
                    matches = feature.value != (*i).property().literal();
                } else if (_nodeName == "PropertyIsLessThan") {
                    matches = feature.value < (*i).property().literal();
                } else if (_nodeName == "PropertyIsGreaterThan") {
                    matches = feature.value > (*i).property().literal();
                } else if (_nodeName == "PropertyIsLessThanOrEqualTo") {
                    matches = feature.value <= (*i).property().literal();
                } else if (_nodeName == "PropertyIsGreaterThanOrEqualTo") {
                    matches = feature.value >= (*i).property().literal();
                } else {
                    matches = true; // all other Properties not implemented
                }
            }
        }
        if (!found) {
            return true;
        } else {
            return matches;
        }
    }
    return false;
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

void Operation::_parseNode()
{
    XmlIterator it(_iterator);
    
    if (isCompareOperation(_nodeName)) {
        it.moveToParentNode();
        it.moveToPreviousNode();
    }
    
    while (it.moveToNextNode()) {
        
        if (isCompareOperation(_nodeName)) {
        
            Property property(it);
            _property = property;
            break;
            
        } else if (isLogicOperation(_nodeName)) {
        
            _isLogicalOperation = true;
            Operation operation(it);
            _operations.push_back(operation);
            
        }
    }
}



}

