/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */

import java.util.ArrayList;
import java.util.Iterator;
public class ArrayNode extends Node implements Iterable<Node> {
    
    private ArrayList<Node> taulukko;

    public ArrayNode () {
        this.taulukko = new ArrayList<Node>();
    }
    
    public void add(Node node) {
        this.taulukko.add(node);
    }
    
    public int size() {
        return this.taulukko.size();
    }
    
    @Override
    public Iterator<Node> iterator () {
        return taulukko.iterator();
    }
    
}
