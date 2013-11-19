#include "logicoperation.h"

namespace automap {

void LogicOperation::add(std::shared_ptr<FilterOperation> operation)
{
    _operations.push_back(operation);
}

}