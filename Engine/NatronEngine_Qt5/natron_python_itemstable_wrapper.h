#ifndef SBK_ITEMSTABLEWRAPPER_H
#define SBK_ITEMSTABLEWRAPPER_H

#include <PyItemsTable.h>

class ItemsTableWrapper : public Natron::Python::ItemsTable
{
public:
    ~ItemsTableWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_ITEMSTABLEWRAPPER_H

