Для разворачивания выражения свёртки стандарт языка предусматривает унарные и
бинарные конфигурации расположения аргументов пакета параметров; наличие скобок
в них обязательно:

- Унарная  правая свёртка: ```(pack op ...)```
- Унарная  левая  свёртка: ```(... op pack)```
- Бинарная правая свёртка: ```(pack op ... op value)```
- Бинарная левая  свёртка: ```(value op ... op pack)```

Свёртка разворачивается в выражение:

- Унарная  правая свёртка ```(E op ...)```      разворачивается в выражение ```(E₁ op (... op (Eₙ₋₁ op Eₙ)))```
- Унарная  левая  свёртка ```(... op E)```      разворачивается в выражение ```(((E₁ op E₂) op ...) op Eₙ)```
- Бинарная правая свёртка ```(E op ... op I)``` разворачивается в выражение ```(E₁ op (... op (Eₙ₋₁ op (Eₙ op I))))```
- Бинарная левая  свёртка ```(I op ... op E)``` разворачивается в выражение ```((((I op E₁) op E₂) op ...) op Eₙ)```

(где ```n``` это количество элементов в pack expansion)

Проблема определения типа и значения при раскрытии пустой унарной свёртки в
общем случае считается ошибкой, за исключением трёх ситуаций:

- пустое раскрытие унарной свёртки ```&&``` даёт ```true```,
- пустое раскрытие унарной свёртки ```||``` даёт ```false```,
- пустое раскрытие унарной свёртки ```,``` даёт тип ```void```.