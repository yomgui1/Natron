#ifndef SBK_ROTOWRAPPER_H
#define SBK_ROTOWRAPPER_H

#include <PyRoto.h>

class RotoWrapper : public Natron::Python::Roto
{
public:
    ~RotoWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_ITEMSTABLEWRAPPER_H
#  define SBK_ITEMSTABLEWRAPPER_H

// Inherited base class:
class ItemsTableWrapper : public Natron::Python::ItemsTable
{
public:
    ~ItemsTableWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_ITEMSTABLEWRAPPER_H

#endif // SBK_ROTOWRAPPER_H

