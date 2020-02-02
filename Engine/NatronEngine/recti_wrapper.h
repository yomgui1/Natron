#ifndef SBK_RECTIWRAPPER_H
#define SBK_RECTIWRAPPER_H

#include <shiboken.h>

#include <RectI.h>

namespace Natron { namespace Python {
class RectIWrapper : public RectI
{
public:
    RectIWrapper();
    RectIWrapper(const RectI& self) : RectI(self)
    {
    }

    RectIWrapper(int x1_, int y1_, int x2_, int y2_);
    virtual ~RectIWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_RECTIWRAPPER_H

