#ifndef SYMBOLIZER_H
#define SYMBOLIZER_H

#include <memory>

namespace SldParser {

enum class SymbolizerTypes: unsigned int {
        PolygonSymbolizer = 0,
        PointSymbolizer,
        TextSymbolizer,
        RasterSymbolizer,
        LineSymbolizer
};

class SymbolizerPrivate;
    
class Symbolizer {
public:
    explicit Symbolizer(SymbolizerPrivate&);
    ~Symbolizer();
    
    Symbolizer(const Symbolizer&) ;
    
    std::string nodeName() const;
    
    SymbolizerTypes type() const;
    std::string color() const;
    std::string wellKnownName() const;
    double opacity() const;
    double width() const;
    std::string linecap() const;
    std::string linejoin() const;
    double dashoffset() const;
    unsigned int size() const;
    unsigned int rotation() const;
    
    static bool isSymbolizer(std::string);
private:
    std::unique_ptr<SymbolizerPrivate> _p;
};
    
};

#endif // SYMBOLIZER_H