/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class ValueNode extends Node {

    private double arvo;
    private boolean totuus;
    private String teksti;
    private int marker = -1;
    
    public ValueNode () {
        this.marker = 0;
    }
    
    public ValueNode (double value) {
        this.arvo = value;
        this.marker = 1;
    }
    
    public ValueNode (boolean value) {
        this.totuus = value;
        this.marker = 2;
    }
    
    public ValueNode (String value) {
        this.teksti = value;
        this.marker = 3;
    }
    
    public boolean isNumber() {
        return marker == 1;
    }
    
    public boolean isBoolean() {
        return marker == 2;
    }
    
    public boolean isString() {
        return marker == 3;
    }
    
    public boolean isNull () {
        return marker == 0;
    }
    
    public double getNumber() {
        return arvo;
    }
    
    public boolean getBoolean() {
        return totuus;
    }
    
    public String getString() {
        return teksti;
    }
    
    public Object getNull () {
        return null;
    }
}
