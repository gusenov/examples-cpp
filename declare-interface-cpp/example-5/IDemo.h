class IDemo
{
  public:
    virtual void OverrideMe() = 0;

  // Альтернатива для виртуального деструктора - защищенный деструктор.
  // Это отключит полиморфную деструкцию.
  // См. "Guideline #4" в http://www.gotw.ca/publications/mill18.htm

  // Защищенный невиртуальный конструктор позволяет избежать UB, если кто-то
  // попытается удалить объект типа IDemo.

  protected:
    ~IDemo() {}

};
