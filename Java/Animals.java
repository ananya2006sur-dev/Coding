public class Animals 
{
    class Dog
    {
        Dog()
        {
            System.out.println("Dog constructor called");
        }
        public void bark()
        {
            System.out.println("Woof Woof");
        }
    }
    class Cat
    {
        Cat()
        {
            System.out.println("Cat constructor called");
        }
        public void meow()
        {
            System.out.println("Meow Meow"); 
        }
    }
    public static void main(String[] args) 
    {
        Animals a = new Animals(); 
        Animals.Dog pluto = a.new Dog(); 
        pluto.bark(); 
        Animals.Cat tom = a.new Cat();
        tom.meow();  
    }
}
