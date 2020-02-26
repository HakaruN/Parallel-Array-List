#ifndef PARALLELARRAYLIST_H
#define PARALLELARRAYLIST_H


class parallelArrayList
{
    public:
        parallelArrayList();
        virtual ~parallelArrayList();
        parallelArrayList(const parallelArrayList& other);


        unsigned long getEndIndex()
        {//use this when we need to add a new item into the structure, we get the current end index and add our item to the next index
            return mArrayEndIndex;
        }



    protected:
        unsigned long mLength = 0;//length of the structure (init'd in cstr)
        unsigned long mArrayEndIndex = 0;//points to the end of the items in the array imagine like a stack ptr so we know where the next free space is
    private:
};

#endif // PARALLELARRAYLIST_H
