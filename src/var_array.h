/*
vArray - variable length array written by Phil Dougherty
ultra-naive implementation. use at own idiocy.
*/

#ifndef _VAR_ARRAY_
#define _VAR_ARRAY_

#define DEFAULT_SIZE 5

template <typename T>
class vArray
{
  private:
    T* content;
    int a_size; //size allocated for content
    int len; //length used

    void RA();
  public:
    vArray()               : len(0), a_size(DEFAULT_SIZE), content(new T[a_size]) {}
    vArray(int start_size) : len(0), a_size(start_size),   content(new T[a_size]) {}
    ~vArray() { delete[] content; }

    T& operator[](int index)             { return content[index]; }
    const T& operator[](int index) const { return content[index]; }
    int length() { return len; }
    void add(T content);
    void remove(int index);
};

template <typename T>
void vArray<T>::add(T t)
{
  content[len] = t;
  if(len >= a_size)
  {
    T* tmp = new T[a_size*2];
    for(int i = 0; i < a_size; i++)
      tmp[i] = content[i];
    delete[] content;
    content = tmp;
    a_size *= 2;
  }
  len++;
}

template <typename T>
void vArray<T>::remove(int index) //maybe should implement with memcopy or something?
{
  for(int i = index+1; i < len; i++)
    content[i] = content[i+1];
  len--;
}

#endif

