#include "logicoperation.h"

namespace automap {

void LogicOperation::add(FilterOperation* operation)
{
    _operations.push_back(operation);
}

}