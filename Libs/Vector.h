//
// Created by administrator on 14-11-17.
//

#ifndef CPP_VECTOR_H
#define CPP_VECTOR_H

template <typename ItemT, class FriendT>
class Vector {
    friend FriendT;

protected:
    typedef Vector<ItemT, FriendT> facet;
    typedef const Vector<ItemT, FriendT> const_facet;
    typedef ItemT value_type;

protected:
    Vector(value_type beg) : m_val (beg) { /* NOP */ }

public:
    value_type operator * () const { return m_val; }

    const_facet & operator ++ () { ++m_val; return *this; }
    facet operator ++ (int) { facet cpy(*this); ++m_val; return cpy; }

    const_facet & operator -- () { --m_val; return *this; }
    facet operator -- (int) { facet cpy(*this); --m_val; return cpy; }

    facet operator + (value_type n) const { return facet(m_val + n); }
    const_facet & operator += (value_type n) { m_val += n; return *this; }

    facet op    erator - (value_type n) const { return facet(m_val -n); }
    const   _facet & operator -= (value_type n) { m_val -= n; return *this; }

    bool operator == (const_facet & other_it) const { return m_val == other_it.m_val; }
    bool operator != (const_facet & other_it) const { return m_val != other_it.m_val; }
    void push_back(const_reference value) {
        if(capacity() == size()) // if the vector is full allocate new memory
        {
            // get new-needed space (geometric growth factor 2)
            if(capacity() != 0)
                capacity_ *= 2;
            else
                capacity_ = 1;

            // allocate space
            pointer temp = allocator().allocate(capacity());

            // then move the elements over and create the new element
            memcpy(temp, start_, size() * sizeof(value_type));

            allocator().deallocate(start_, size());
            start_ = temp;
        }
        new (data() + size()) value_type(value);

        ++size_;
    }
private:
    value_type m_val;};


#endif //CPP_VECTOR_H
