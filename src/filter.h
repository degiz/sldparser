#ifndef FILTER_H
#define FILTER_H

#include "sldnode.h"
#include "property.h"

#include <vector>
#include <map>
#include <string>

namespace automap {
    
class Filter : public SLDNode {
public:
    Filter(xmlNode*);
    ~Filter();
    
    std::vector<Property> properties();
    
private:
    void _parseNode();
    std::vector<Property> _properties;
    std::string _featureId;
    
    std::vector<std::string> _binaryCamparations;
    std::vector<std::string> _logicOperations;
};
    
};

#endif // FILTER_H