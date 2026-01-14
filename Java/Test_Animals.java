
public class Test_Animals 
{
    public static void main(String[] args) {
        Animals a = new Animals(); 
        Animals.Dog pluto = a.new Dog(); 
        pluto.bark(); 
        Animals.Cat tom = a.new Cat(); 
        tom.meow(); 
    }
}
