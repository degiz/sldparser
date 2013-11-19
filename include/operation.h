#ifndef OPERATION_H
#define OPERATION_H

#include "feature.h"
#include "sldnode.h"
#include "property.h"
#include "variant.h"

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
    
    bool check(FeatureProperty&);
    
    template<class T>
    bool check(Feature<T> feature);
   
private:
    static const char* _binaryComparisonOpType[];
    static const char* _logicOpsType[];
    std::vector<Operation*> _operations;

    void _parseNode();
};
    
};

#endif // OPERATION_H