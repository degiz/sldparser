#ifndef OPERATION_H
#define OPERATION_H

#include "feature.h"
#include "sldnode.h"
#include "property.h"
#include "variant.h"
#include "filteroperation.h"

#include <vector>
#include <map>
#include <string>
#include <memory>

namespace automap {
    
class Operation : public SLDNode {
public:

    #define NUM_OF_COMPARE_OPERATIONS 9
    #define NUM_OF_LOGIC_OPERATIONS 3
    
    Operation();
    Operation(XmlIterator);
    Operation(XmlIterator, std::shared_ptr<FilterOperation>);
    ~Operation();
    
    static bool isLogicOperation(std::string);
    static bool isCompareOperation(std::string);
    
    bool check(FeatureProperty&) const;
    
    bool check(IFeature&) const;
   
private:
    static std::vector<std::string> _binaryComparisonOpType;
    static std::vector<std::string> _logicOpsType;
    
    std::vector<Operation> _operations;
    std::shared_ptr<FilterOperation> _filter;
    Property _property;
    bool _hasParentFilter;

    void _parseNode();
};
    
};

#endif // OPERATION_H