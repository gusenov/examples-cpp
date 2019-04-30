class IDemo
{
  public:
    virtual ~IDemo() {}
    // Этот деструктор должен бездействовать.
    // Чтобы можно было делать:
    // IDemo *p = new Child;
    // delete p;

    virtual void OverrideMe() = 0;
};
