# [```std::hash(std::shared_ptr)```](https://en.cppreference.com/w/cpp/memory/shared_ptr/hash)

The template specialization of ```std::hash``` for ```std::shared_ptr<T>``` allows users to obtain hashes of objects of type ```std::shared_ptr<T>```.
For a given ```std::shared_ptr<T> p```, this specialization ensures that

```cpp
std::hash<std::shared_ptr<T>>()(p) == std::hash<typename std::shared_ptr<T>::element_type*>()(p.get()).
```
