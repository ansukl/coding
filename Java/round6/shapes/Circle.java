/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class Circle implements IShapeMetrics{
    
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }
    
    @Override
    public String toString() {
        String output = String.format("Circle with radius: %,.2f", radius);
        return output;
    }
    
    public String name() {
        String name = "circle";
        return name;
    }
    
    public double area() {
        double area = radius * radius * PI;
        return area;
    }
    
    public double circumference() {
        double circumference = 2 * radius * PI;
        return circumference;
    }
}
