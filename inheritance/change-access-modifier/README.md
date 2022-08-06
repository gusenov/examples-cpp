Если метод отмечен как ```virtual``` то его можно переопределить в наследниках с любым модификатором доступа.

Если у метода есть реализация, то вызвать напрямую ее можно только если она доступна.
Т.е. метод должен быть ```protected``` чтобы вызвать его из наследника.
Или метод должен быть ```public``` чтобы вызвать его снаружи.

Модификаторы доступа задают видимость методов именно для того типа в котором они указаны.