#ifndef SBK_LAYERWRAPPER_H
#define SBK_LAYERWRAPPER_H

#include <shiboken.h>

#include <PyRoto.h>

namespace Natron { namespace Python {
class LayerWrapper : public Layer
{
public:
    virtual ~LayerWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_LAYERWRAPPER_H

