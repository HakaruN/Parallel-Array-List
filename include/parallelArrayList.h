#ifndef PARALLELARRAYLIST_H
#define PARALLELARRAYLIST_H


class parallelArrayList
{
    public:
        parallelArrayList();
        virtual ~parallelArrayList();
        parallelArrayList(const parallelArrayList& other);


        unsigned long getEndIndex()
        {
            return mArrayEndIndex;
        }



    protected:
        enum mMembers {};
        unsigned long mLength = 0;//length of the arrays
        unsigned long mArrayEndIndex = 0;//will be the index for the next element to be added onto the array, imagine a stack ptr
    private:
};

#endif // PARALLELARRAYLIST_H
