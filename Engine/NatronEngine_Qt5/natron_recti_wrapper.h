#ifndef SBK_RECTIWRAPPER_H
#define SBK_RECTIWRAPPER_H

#include <RectI.h>

class RectIWrapper : public Natron::RectI
{
public:
    RectIWrapper();
    RectIWrapper(const Natron::RectI& self) : Natron::RectI(self)
    {
    }

    RectIWrapper(int x1_, int y1_, int x2_, int y2_);
    ~RectIWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_RECTIWRAPPER_H

