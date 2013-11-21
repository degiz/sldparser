#include "variant.h"

#include "variant_p.h"

Variant::Variant(unsigned int value) :
    _p(new VariantPrivate(value))
{
    
}

Variant::Variant(double value) :
    _p(new VariantPrivate(value))
{

}

Variant::Variant(std::string value) :
    _p(new VariantPrivate(value))
{

}

Variant::~Variant()
{

}

Variant::Variant(const Variant& other) :
    _p(new VariantPrivate(*other._p))
{

}

Variant& Variant::operator=(const Variant& other)
{
    if (*_p == *other._p) {
        return *this;
    } else {
        _p.reset(new VariantPrivate(*other._p));
    }
}

bool Variant::operator==(const Variant& other)
{
    return *this->_p == *other._p;
}

bool Variant::operator!=(const Variant& other)
{
    return *this->_p != *other._p;
}

bool Variant::operator<(const Variant& other)
{
    return *this->_p < *other._p;
}

bool Variant::operator<=(const Variant& other)
{
    return *this->_p <= *other._p;
}

bool Variant::operator>(const Variant& other)
{
    return *this->_p > *other._p;
}

bool Variant::operator>=(const Variant& other)
{
    return *this->_p >= *other._p;
}

VariantType Variant::type()
{
    return _p->type();
}

unsigned int Variant::asUInt()
{
    return _p->asUInt();
}

double Variant::asDouble()
{
    return _p->asDouble();
}

std::string Variant::asString()
{
    return _p->asString();
}

Variant Variant::fromUInt(unsigned int value)
{
    return Variant(value);
}

Variant Variant::fromString(std::string value)
{
    return Variant(value);
}

Variant Variant::fromDouble(double value)
{
    return Variant(value);
}

