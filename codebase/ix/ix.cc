#include <iostream>
#include <cstring>
#include <string>

#include "ix.h"

IndexManager* IndexManager::_index_manager = 0;

IndexManager* IndexManager::instance()
{
    if(!_index_manager)
        _index_manager = new IndexManager();

    return _index_manager;
}

IndexManager::IndexManager()
{
}

IndexManager::~IndexManager()
{
}

RC IndexManager::createFile(const string &fileName)
{
    PagedFileManager *pfm = PagedFileManager::instance();

    //create file
    if (pfm->createFile(fileName.c_str()))
        //Returns a pointer to an array that contains a null-terminated sequence of characters ret 1 if pfm failed
        return 1;

    IXFileHandle ixfh;
    if (openFile(fileName, handle))
        return 1;

    void *pageSpace =calloc(4096, 1);
    if (pageSpace = NULL)
        return 1;

    MetaHeader mh;
    mh.root = 1;
    memcpy(pageSpace, &mh, sizeof(MetaHeader));

    NodeHeader nh;
    nh.left = 0;
    nh.right = 0;


}

RC IndexManager::destroyFile(const string &fileName)
{
    PagedFileManager *pfm = PagedFileManager::instance();
    if(pfm->destroyFile(Filename))
        return 1;

    return 0;
}

RC IndexManager::openFile(const string &fileName, IXFileHandle &ixfileHandle)
{
    PagedFileManager *pfm = PagedFileManager::instance();
    if (pfm->openFile(filename, ixfileHandle.fh))
        return 1;

    return 0;
}

RC IndexManager::closeFile(IXFileHandle &ixfileHandle)
{
    PagedFileManager *pfm = PagedFileManager::instance();
    if (pfm->closeFile(ixfileHandle.fh))
        return 1;

    return 0;
}

RC IndexManager::insertEntry(IXFileHandle &ixfileHandle, const Attribute &attribute, const void *key, const RID &rid)
{
    return -1;
}

RC IndexManager::deleteEntry(IXFileHandle &ixfileHandle, const Attribute &attribute, const void *key, const RID &rid)
{
    return -1;
}


RC IndexManager::scan(IXFileHandle &ixfileHandle,
        const Attribute &attribute,
        const void      *lowKey,
        const void      *highKey,
        bool			lowKeyInclusive,
        bool        	highKeyInclusive,
        IX_ScanIterator &ix_ScanIterator)
{
    return -1;
}

void IndexManager::printBtree(IXFileHandle &ixfileHandle, const Attribute &attribute) const {
}

IX_ScanIterator::IX_ScanIterator()
{
}

IX_ScanIterator::~IX_ScanIterator()
{
}

RC IX_ScanIterator::getNextEntry(RID &rid, void *key)
{
    return -1;
}

RC IX_ScanIterator::close()
{
    return -1;
}


IXFileHandle::IXFileHandle()
{
    ixReadPageCounter = 0;
    ixWritePageCounter = 0;
    ixAppendPageCounter = 0;
}

IXFileHandle::~IXFileHandle()
{
}

RC IXFileHandle::collectCounterValues(unsigned &readPageCount, unsigned &writePageCount, unsigned &appendPageCount)
{
    readPageCount = ixReadPageCounter;
    writePageCount = ixReadPageCounter;
    appendPageCount = ixAppendPageCounter;

    return 0;
}



NodeHeader IndexManager::createNewLeaf()
{

}