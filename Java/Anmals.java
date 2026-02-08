class Dog
{
    public void bark()
    {
        System.out.println("Woof Woof"); 
    }
    public static void main(String[] args) {
        System.out.println("Dog class running"); 
        Dog jerry = new Dog(); 
        jerry.bark(); 
    }
}
class Cat
{
    public void meow()
    {
        System.out.println("Meow Meow"); 
    }
    public static void main(String[] args) {
        System.out.println("Cat class running"); 
        Cat tom = new Cat();
        tom.meow(); 
    }
}
