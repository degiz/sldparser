#include "symbolizer.h"

#include "symbolizer_p.h"

namespace SldParser {
    
Symbolizer::Symbolizer(SymbolizerPrivate& p) :
    _p(new SymbolizerPrivate(p))
{

}

Symbolizer::~Symbolizer()
{

}

Symbolizer::Symbolizer(const Symbolizer& other) :
    _p(new SymbolizerPrivate(*other._p))
{

}

std::string Symbolizer::nodeName() const
{
    return _p->nodeName();
}

SymbolizerTypes Symbolizer::type() const
{
    return _p->type();
}
    
std::string Symbolizer::color() const
{
    return _p->color();
}

std::string Symbolizer::wellKnownName() const
{
    return _p->wellKnownName();
}

double Symbolizer::opacity() const
{
    return _p->opacity();
}

double Symbolizer::width() const
{
    return _p->width();
}

std::string Symbolizer::linecap() const
{
    return _p->linecap();
}

std::string Symbolizer::linejoin() const
{
    return _p->linejoin();
}

double Symbolizer::dashoffset() const
{
    return _p->dashoffset();
}

unsigned int Symbolizer::size() const
{
    return _p->size();
}

unsigned int Symbolizer::rotation() const
{
    return _p->rotation();
}

bool Symbolizer::isSymbolizer(std::string name)
{
    return SymbolizerPrivate::isSymbolizer(name);
}
  
}