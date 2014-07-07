#ifndef _VAR_ARRAY_
#define _VAR_ARRAY_

#define DEFAULT_SIZE 5

template <typename T>
class vArray<T>
{
  private:
    T* content;
    T* shadow; //always double size of content
    size_t c_size; //size allocated for content
    size_t length; //length used

    void RA();
  public:
    vArray<T>();
    vArray<T>(size_t start_size);
    ~vArray<T>();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void add(T content);
    size_t length();
};

vArray<T>::vArray<T>() : length(0), c_size(DEFAULT_START_SIZE), content(new T[c_size]), shadow(new T[c_size*2])
{ }

vArray<T>::vArray<T>(size_t start_size) : length(0), c_size(start_size), content(new T[c_size]), shadow(new T[c_size*2])
{ }

T& operator[](size_t index)
{
  return content[index];
}

const T& operator[](size_t index) const
{
  return content[index];
}

void vArray<T>::add(T t)
{
  content[length] = t;
  if(length >= c_size/2) //unfortunate that this check is only relevant during for first start_size/2 adds...
  {
    int s_i = c_size-(2*(c_size-length));
    shadow[s_i] = content[s_i];
    shadow[s_i+1] = content[s_i+1];
  }

  length++;

  if(length == c_size)
  {
    delete[] content;
    content = shadow;
    c_size *= 2;
    shadow = new T[c_size*2];
  }
}

size_t vArray<T>::length()
{
  return length;
}

vArray<T>::~vArray<T>()
{
  delete[] content;
  delete[] shadow;
}

#endif

