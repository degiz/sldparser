#include "featuretypestyle.h"

#include "featuretypestyle_p.h"

namespace SldParser {

FeatureStyleType::FeatureStyleType(FeatureStyleTypePrivate& p) :
    _p(new FeatureStyleTypePrivate(p))
{
    
}

FeatureStyleType::~FeatureStyleType()
{

}

std::string FeatureStyleType::nodeName() const
{
    return _p->nodeName();
}

FeatureStyleType::FeatureStyleType(const FeatureStyleType& other) :
    _p(new FeatureStyleTypePrivate(*other._p))
{

}

std::string FeatureStyleType::name() const
{
    return _p->name();
}

std::string FeatureStyleType::title() const
{
    return _p->title();
}

std::string FeatureStyleType::abstract() const
{
    return _p->abstract();
}

std::string FeatureStyleType::featureTypeName() const
{

}

std::vector<std::string> FeatureStyleType::semanticTypeIdentifiers() const
{
    return _p->semanticTypeIdentifiers();
}

const std::vector<Rule>& FeatureStyleType::rules() const
{
    return _p->rules();
}

}

