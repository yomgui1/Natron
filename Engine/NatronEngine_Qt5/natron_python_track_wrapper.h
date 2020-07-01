#ifndef SBK_TRACKWRAPPER_H
#define SBK_TRACKWRAPPER_H

#include <PyTracker.h>

class TrackWrapper : public Natron::Python::Track
{
public:
    ~TrackWrapper();
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

#endif // SBK_TRACKWRAPPER_H

