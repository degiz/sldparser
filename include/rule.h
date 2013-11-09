#ifndef RULE_H
#define RULE_H

#include "sldnode.h"
#include "filter.h"
#include "symbolizer.h"
#include "variant.h"

#include <vector>
#include <map>
#include <string>

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

namespace automap {
  
class Rule : public SLDNode {
public:
    Rule(XmlIterator);
    ~Rule();
    
    std::string name();
    std::string title();
    std::string abstract();
    double minScaleDenominator();
    double maxScaleDenominator();
    std::vector<Symbolizer>& Symbolizers();
    bool hasElseFilter();
    
    bool check(Feature&);
    bool check(std::vector<Feature>&);
    
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

};

#endif // RULE_H