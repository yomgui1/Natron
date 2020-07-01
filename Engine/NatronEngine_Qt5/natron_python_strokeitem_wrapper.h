#ifndef SBK_STROKEITEMWRAPPER_H
#define SBK_STROKEITEMWRAPPER_H

#include <PyRoto.h>

class StrokeItemWrapper : public Natron::Python::StrokeItem
{
public:
    ~StrokeItemWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_ITEMBASEWRAPPER_H
#  define SBK_ITEMBASEWRAPPER_H

// Inherited base class:
class ItemBaseWrapper : public Natron::Python::ItemBase
{
public:
    ~ItemBaseWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_ITEMBASEWRAPPER_H

#endif // SBK_STROKEITEMWRAPPER_H

