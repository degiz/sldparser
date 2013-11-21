#include "rule.h"

#include "rule_p.h"

namespace SldParser {
  
Rule::Rule(XmlIterator iterator) :
    _p(new RulePrivate(iterator))
{

}

Rule::~Rule()
{

}

Rule::Rule(const Rule& other) :
    _p(new RulePrivate(*other._p))
{

}

std::string Rule::name() const
{
    return _p->name();
}

std::string Rule::title() const
{
    return _p->title();
}

std::string Rule::abstract() const
{
    return _p->abstract();
}

double Rule::minScaleDenominator() const
{
    return _p->minScaleDenominator();
}

double Rule::maxScaleDenominator() const
{
    return _p->maxScaleDenominator();
}

const std::vector<Symbolizer>& Rule::symbolizers() const
{
    return _p->symbolizers();
}

bool Rule::hasElseFilter() const
{
    return _p->hasElseFilter();
}

bool Rule::check(FeatureProperty& feature) const
{
    return _p->check(feature);
}

bool Rule::check(std::vector<FeatureProperty>& features) const
{
    return _p->check(features);
}

bool Rule::check(IFeature& feature) const
{
    return _p->check(feature);
}
  
}