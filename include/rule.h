#ifndef RULE_H
#define RULE_H

#include "feature.h"
#include "symbolizer.h"

#include <memory>
#include <vector>

namespace SldParser {

class RulePrivate;
  
class Rule {
public:
    explicit Rule(RulePrivate&);
    ~Rule();
    
    Rule(const Rule& other);
    
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
    std::unique_ptr<RulePrivate> _p;
   
};

}

#endif // RULE_H