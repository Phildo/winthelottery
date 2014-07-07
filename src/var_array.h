#ifndef _VAR_ARRAY_
#define _VAR_ARRAY_

#define DEFAULT_SIZE 5

template <typename T>
class vArray
{
  private:
    T* content;
    T* shadow; //always double size of content
    int c_size; //size allocated for content
    int len; //length used

    void RA();
  public:
    vArray()               : len(0), c_size(DEFAULT_SIZE), content(new T[c_size]), shadow(new T[c_size*2]) {}
    vArray(int start_size) : len(0), c_size(start_size),   content(new T[c_size]), shadow(new T[c_size*2]) {}
    ~vArray() { delete[] content; delete[] shadow; }

    T& operator[](int index)             { return content[index]; }
    const T& operator[](int index) const { return content[index]; }
    int length() { return len; }
    void add(T content);
};

template <typename T>
void vArray<T>::add(T t)
{
  content[len] = t;
  if(len >= c_size/2) //unfortunate that this check is only relevant during for first start_size/2 adds...
  {
    int s_i = c_size-(2*(c_size-len));
    shadow[s_i] = content[s_i];
    shadow[s_i+1] = content[s_i+1];
  }

  len++;

  if(len == c_size)
  {
    delete[] content;
    content = shadow;
    c_size *= 2;
    shadow = new T[c_size*2];
  }
}

#endif

