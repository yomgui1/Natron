#ifndef SBK_EFFECTWRAPPER_H
#define SBK_EFFECTWRAPPER_H

#include <shiboken.h>

#include <PyNode.h>

namespace Natron { namespace Python {
class EffectWrapper : public Effect
{
public:
    ~EffectWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_EFFECTWRAPPER_H

