#ifndef RULE_H
#define RULE_H

#include "sldnode.h"
#include "filter.h"
#include "symbolizer.h"

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
    Rule(xmlNode*);
    ~Rule();
    
    std::string name();
    std::string title();
    std::string abstract();
    double minScaleDenominator();
    double maxScaleDenominator();
    std::vector<Filter> filters();
    std::vector<Symbolizer> symbolizers();
    
private:
    std::string _name;
    std::string _title;
    std::string _abstract;
    double _minScaleDenominator;
    double _maxScaleDenominator;
    std::vector<Filter> _filters;
    std::vector<Symbolizer> _symbolizers;
    std::vector<std::string> _symbolizerTypes;
   
    void _parseNode();
};

};

#endif // RULE_H