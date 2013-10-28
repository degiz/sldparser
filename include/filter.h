#ifndef FILTER_H
#define FILTER_H

#include "sldnode.h"
#include "operation.h"
#include "variant.h"

#include <vector>
#include <map>
#include <string>

namespace automap {
    
class Filter : public SLDNode {
public:
    Filter();
    Filter(XmlIterator);
    ~Filter();
    
    bool check(Feature&);
    
private:
    void _parseNode();
    std::vector<Operation> _operations;
    std::string _featureId;
    
    std::vector<std::string> _binaryCamparations;
    std::vector<std::string> _logicOperations;
};
    
};

#endif // FILTER_H