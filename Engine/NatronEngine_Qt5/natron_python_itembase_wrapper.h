#ifndef SBK_ITEMBASEWRAPPER_H
#define SBK_ITEMBASEWRAPPER_H

#include <PyItemsTable.h>

class ItemBaseWrapper : public Natron::Python::ItemBase
{
public:
    ~ItemBaseWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_ITEMBASEWRAPPER_H

