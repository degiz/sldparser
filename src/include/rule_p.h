#ifndef RULE_PRIVATE_H
#define RULE_PRIVATE_H

#include "sldnode.h"
#include "filter.h"
#include "feature.h"
#include "symbolizer.h"
#include "variant.h"

#include <vector>
#include <map>
#include <string>

namespace SldParser {
  
class RulePrivate : public SLDNode {
public:
    RulePrivate(XmlIterator);
    ~RulePrivate();
    
    std::string name() const;
    std::string title() const;
    std::string abstract() const;
    double minScaleDenominator() const;
    double maxScaleDenominator() const;
    const std::vector<Symbolizer>& symbolizers() const;
    bool hasElseFilter() const;
    
    bool check(FeatureProperty&) const;
    bool check(std::vector<FeatureProperty>&) const;
    bool check(IFeature&) const;
    
private:
    std::string _name;
    std::string _title;
    std::string _abstract;
    double _minScaleDenominator;
    double _maxScaleDenominator;
    Filter _filter;
    bool _hasElseFilter;
    
    std::vector<Symbolizer> _symbolizers;
    std::vector<std::string> _symbolizerTypes;
   
    void _parseNode();
};

}

#endif // RULE_PRIVATE_H