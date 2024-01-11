/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class Rectangle implements IShapeMetrics{

    private double height;
    private double width;
    
    public Rectangle(double height, double width) {
        this.height = height;
        this.width = width;
    }
    
    @Override
    public String toString() {
        String output = String.format("Rectangle with height %,.2f and width %,.2f", height, width);
        return output;
    }
    
    public String name() {
        String name = "rectangle";
        return name;
    }
    
    public double area() {
        double area = height * width;
        return area;
    }
    
    public double circumference() {
        double circumference = 2 * height + 2 * width;
        return circumference;
    }
}
