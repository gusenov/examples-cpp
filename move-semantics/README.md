# L-value и R-value

L-value - идентифицируемое место в памяти (т.е. имеет адрес).
R-value - определяет исключительным путем, т.е. это не L-value.
Каждое выражение либо L-value, либо R-value.
Так что R-value это выражение которое не представляет объект занимающий 
некоторое идентифицируемое место в памяти.

```cpp
// Оператор присваивания (assignment) предполагает L-value в качестве левого операнда.

int i = 10;  // i имеет адрес в памяти и поэтому это L-value.

int i;
10 = i;  // 10 не имеет идентифицируемого местонахождения в памяти и поэтому это R-value, нет смысла присваивать i десяти.
```

# ```std::move```

[```std::move``` просто cast'ит объект к ```T&&```, с объектом ничего не случается.](https://stackoverflow.com/questions/42795683/using-an-object-after-stdmove-doesnt-result-in-a-compilation-error#comment72706090_42795683)

[По старой доброй традиции C++ ```remove``` не изымает, ```delete``` не стирает, а ```move``` не перемещает :)](https://stackoverflow.com/questions/42795683/using-an-object-after-stdmove-doesnt-result-in-a-compilation-error#comment72706352_42795683)
