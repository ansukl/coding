package fi.tuni.prog3.json;


import java.util.TreeMap;
import java.util.Iterator;

/**
 * A class for representing a JSON object.
 */

public class ObjectNode extends Node implements Iterable<String> {

    private TreeMap<String, Node> container;
    
    /**
     * Constructs an initially empty JSON object node.
     */
    public ObjectNode () {
        this.container = new TreeMap<String, Node>();
    }
        
    /**
     * Returns the number of JSON nodes stored under this JSON object.
     * @return the number of JSON nodes under this JSON object.
     */
    public int size () {
        return this.container.size();
    }
    
    /**
     * Returns the JSON node stored under the given name.
     * @param name the name of the name-node pair whose node should be 
     * returned.
     * @return the JSON node corresponding to name, or null if such node does 
     * not exist.
     */
    public Node get(String name) {
        return this.container.get(name);
    }
    
    /**
     * Stores a name - JSON node pair into this JSON object. If a name-node pair
     * with the same name already exists, the previously existing node will be
     * replaced.
     * @param name the name of the name-node pair.
     * @param node the JSON node of the name-node pair.
     */
    public void set(String name, Node node) {
        this.container.put(name, node);
    }
    
    /**
     * Returns a String iterator that iterates the names of the name-node pairs 
     * stored in this JSON object in natural String order.
     * @return a String iterator that iterates the names of the stored 
     * name-node pairs in natural String order.
     */
    @Override
    public Iterator<String> iterator () {
        return this.container.keySet().iterator();
    }
    
}
