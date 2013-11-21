#ifndef FILTER_H
#define FILTER_H

#include "feature.h"
#include "sldnode.h"
#include "operation.h"
#include "variant.h"

#include <vector>
#include <map>
#include <string>

namespace SldParser {
    
class Filter : public SLDNode {
public:
    Filter();
    Filter(XmlIterator);
    ~Filter();
    
    bool check(FeatureProperty&) const;
    
    bool check(IFeature&) const;
    
private:
    void _parseNode();
    Operation _operation;
    std::string _featureId;
};
    
};

#endif // FILTER_H