#ifndef OPERATION_H
#define OPERATION_H

#include "sldnode.h"
#include "property.h"

#include <vector>
#include <map>
#include <string>

namespace automap {
    
class Operation : public SLDNode {
public:

    #define NUM_OF_COMPARE_OPERATIONS 9
    #define NUM_OF_LOGIC_OPERATIONS 3
    
    Operation(XmlIterator);
    ~Operation();
    
    static bool isLogicOperation(std::string);
    static bool isCompareOperation(std::string);
    
    bool isLogicalOperation();
    
    std::vector<Operation>& operations();
    std::vector<Property>& properties();
    
private:
    static const char* _binaryComparisonOpType[];
    static const char* _logicOpsType[];
    bool _isLogicalOperation;
    std::vector<Operation> _operations;
    std::vector<Property> _properties;

    void _parseNode();
    
};
    
};

#endif // OPERATION_H