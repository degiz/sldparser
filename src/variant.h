#ifndef VARIANT_H
#define VARIANT_H

#include <iostream>
#include <string>
#include <sstream>

enum VariantType {
    UINT = 0,
    DOUBLE,
    STRING
};

class Variant {
public:
    Variant(unsigned int);
    Variant(double);
    Variant(std::string);
    ~Variant();

    VariantType type();
    
    unsigned int asUInt();
    double asDouble();
    std::string asString();
    
private:
    VariantType _type;
    template<class T> T* _castTypeByPointer();
    template<class T> T _castTypeByValue();
    template<class T> void _createValue(T);
    template<class T> void _deleteValue();
    template<class T> T _convertToIntegralType(VariantType);
    std::string _convertToString();
   
    void* _value;
};

#endif