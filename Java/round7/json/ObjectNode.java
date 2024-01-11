/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */

import java.util.TreeMap;
import java.util.Collections;
import java.util.Iterator;

public class ObjectNode extends Node implements Iterable<String> {

    private TreeMap<String, Node> container;
    
    public ObjectNode () {
        this.container = new TreeMap<String, Node>();
    }
    
    public Node get(String key) {
        return this.container.get(key);
    }
    
    public void set(String key, Node node) {
        this.container.put(key, node);
    }
    
    public int size () {
        return this.container.size();
    }
    
    @Override
    public Iterator<String> iterator () {
        return this.container.keySet().iterator();
    }
    
}
