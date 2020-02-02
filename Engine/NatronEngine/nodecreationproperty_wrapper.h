#ifndef SBK_NODECREATIONPROPERTYWRAPPER_H
#define SBK_NODECREATIONPROPERTYWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

namespace Natron { namespace Python {
class NodeCreationPropertyWrapper : public NodeCreationProperty
{
public:
    NodeCreationPropertyWrapper();
    virtual ~NodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_NODECREATIONPROPERTYWRAPPER_H

