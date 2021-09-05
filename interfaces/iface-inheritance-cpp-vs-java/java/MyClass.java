public class MyClass extends Base implements Interface
{
    public static void main(String argv[])
    {
        MyClass c = new MyClass();
        
        c.f();
        // Base.f()
        
        c.g();
        // MyClass.g()
    }
    
    public void g()
    {
        System.out.println("MyClass.g()");
    }
}
