[Removes from the vector](https://www.cplusplus.com/reference/vector/vector/erase/)

- either a single   element  : ```position```
- or     a range of elements : [```first```, ```last```)

```cpp
iterator erase (const_iterator position);
iterator erase (const_iterator first, const_iterator last);
```

```last``` - это стоп-элемент.
