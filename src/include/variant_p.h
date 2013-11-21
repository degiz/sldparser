#ifndef VARIANT_PRIVATE_H
#define VARIANT_PRIVATE_H

#include <iostream>
#include <string>
#include <sstream>

#include "variant.h"

class VariantPrivate {
public:
    VariantPrivate(unsigned int);
    VariantPrivate(double);
    VariantPrivate(std::string);
    ~VariantPrivate();
    
    VariantPrivate(const VariantPrivate& other);
    VariantPrivate& operator=(const VariantPrivate& other);
    
    bool operator==(const VariantPrivate& other);
    bool operator!=(const VariantPrivate& other);
    bool operator<(const VariantPrivate& other);
    bool operator<=(const VariantPrivate& other);
    bool operator>(const VariantPrivate& other);
    bool operator>=(const VariantPrivate& other);
    
    VariantType type();
    
    unsigned int asUInt();
    double asDouble();
    std::string asString();
    
    static VariantPrivate fromUInt(unsigned int);
    static VariantPrivate fromString(std::string);
    static VariantPrivate fromDouble(double);
    
private:
    VariantType _type;
    template<class T> T* _castTypeByPointer(void*);
    template<class T> T* _castTypeByPointer();
    template<class T> T _castTypeByValue();
    template<class T> void _createValue(T);
    template<class T> void _deleteValue();
    template<class T> T _convertToIntegralType(VariantType);
    std::string _convertToString();
    void _swap(const VariantPrivate&);
    void _clear();
   
    void* _value;
};

#endif // VARIANT_PRIVATE_H