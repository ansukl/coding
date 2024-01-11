package fi.tuni.prog3.json;

/**
 * A class for representing a JSON value. The value can be either a double, 
 * a boolean, a String or null.
 */

public class ValueNode extends Node {

    private double arvo;
    private boolean totuus;
    private String teksti;
    private int marker = -1;
    
    /**
     * Constructs a JSON value node that stores the null value.
     */
    public ValueNode () {
        this.marker = 0;
    }
    
    /**
     * Constructs a JSON value node that stores the given double value.
     * @param value - The double value to store in the new JSON value node.
     */
    public ValueNode (double value) {
        this.arvo = value;
        this.marker = 1;
    }
    
    /**
     * Constructs a JSON value node that stores the given boolean value.
     * @param value - The boolean value to store in the new JSON value node.
     */
    public ValueNode (boolean value) {
        this.totuus = value;
        this.marker = 2;
    }
    
    /**
     * Constructs a JSON value node that stores the given string.
     * @param value - The string to store in the new JSON value node.
     * @throws IllegalStateException - if the parameter value is null.
     */
    public ValueNode (String value) {
        this.teksti = value;
        this.marker = 3;
        
        if (value == null) {
            throw new IllegalStateException("Parameter value is null");
        }
    }
    
    /**
     * Checks whether this value node stores a number (double).
     * @return true if this node stores a double value, otherwise false.
     */
    public boolean isNumber() {
        return marker == 1;
    }
    
    /**
     * Checks whether this value node stores a boolean value.
     * @return true if this node stores a boolean value, otherwise false.
     */
    public boolean isBoolean() {
        return marker == 2;
    }
    
    /**
     * Checks whether this value node stores a string.
     * @return true if this node stores a string, otherwise false.
     */
    public boolean isString() {
        return marker == 3;
    }
    
    /**
     * Checks whether this value node stores null.
     * @return true if this node stores null, otherwise false.
     */
    public boolean isNull () {
        return marker == 0;
    }
    
    /**
     * Returns the stored value as a number (double).
     * @return the stored number as a double value.
     * @throws IllegalStateException - if the stored value is not a number.
     */
    public double getNumber() {
        if (!isNumber()) {
            throw new IllegalStateException("Not a number");
        }
        return arvo;
    }
    
    /**
     * Returns the stored value as a boolean value.
     * @return the stored boolean value.
     * @throws IllegalStateException - if the stored value is not a boolean 
     * value.
     */
    public boolean getBoolean() {
        if (!isBoolean()) {
            throw new IllegalStateException("Not a boolean");
        }
        return totuus;
    }
    
    /**
     * Returns the stored value as a string.
     * @return the stored string.
     * @throws IllegalStateException - if the stored value is not a string.
     */
    public String getString() {
        if (!isString()) {
            throw new IllegalStateException("Not a string");
        }
        return teksti;
    }
    
    /**
     * Returns the stored value as null.
     * @return null.
     * @throws IllegalStateException - if the stored value is not null.
     */
    public Object getNull() {
        if (!isNull()) {
            throw new IllegalStateException("Not null");
        }
        
        return null;
    }
}
