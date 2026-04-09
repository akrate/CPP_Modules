
template <typename T>Array<T>::Array()
{
    data = NULL;
    _size = 0;
}
template <typename T>Array<T>::Array(unsigned int n)
{
    data = new T[n]();
    _size = n;
}
template <typename T>Array<T>::Array(Array& other) : data(NULL) , _size(0)
{
    *this =  other;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        if (data)
            delete[] data;
        _size = other._size;
        if (_size > 0)
        {
            data = new T[_size];
            for(unsigned int i = 0;i < _size;i++)
            {
                data[i] = other.data[i];
            }
        }else
            data = NULL;
    }
    return *this;
}
template <typename T>T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("out of bound!!");
    }
    return data[index];
}

template <typename T> Array<T>::~Array()
{
    delete [] data;
}
template <typename T> unsigned int Array<T>::size() const
{
    return _size;
}