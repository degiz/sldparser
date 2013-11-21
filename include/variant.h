#ifndef VARIANT_H
#define VARIANT_H

#include <memory>

enum VariantType {
    UINT = 0,
    DOUBLE,
    STRING,
    NONE
};

class VariantPrivate;

class Variant {
public:
    Variant(unsigned int);
    Variant(double);
    Variant(std::string);
    ~Variant();
    
    Variant(const Variant& other);
    Variant& operator=(const Variant& other);
    
    bool operator==(const Variant& other);
    bool operator!=(const Variant& other);
    bool operator<(const Variant& other);
    bool operator<=(const Variant& other);
    bool operator>(const Variant& other);
    bool operator>=(const Variant& other);
    
    VariantType type();
    
    unsigned int asUInt();
    double asDouble();
    std::string asString();
    
    static Variant fromUInt(unsigned int);
    static Variant fromString(std::string);
    static Variant fromDouble(double);
    
private:
    std::unique_ptr<VariantPrivate> _p;
    
};

#endif // VARIANT_H