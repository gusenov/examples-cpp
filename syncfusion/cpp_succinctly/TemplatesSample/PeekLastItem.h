#pragma once

template<class T, class U>
U PeekLastItem(T& collection) {
  return *collection.rbegin();
}
