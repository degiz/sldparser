#ifndef ANDOPERATION_H
#define ANDOPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace automap {

class AndOperation : public LogicOperation {
public:
    template<class T>
    bool check(Feature<T>);
};

}

#endif // ANDOPERATION_H

