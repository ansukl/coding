/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */

import java.util.ArrayList;
import java.util.Collections;

public class Median {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        
        ArrayList<Double> median = new ArrayList<>();
        
        for (String s : args) {
            double d = Double.parseDouble(s);
            median.add(d);
        }

        Collections.sort(median);
        
        int index  = median.size() / 2;
        double middle = (index > 0 && index % 2 == 0) ? ((median.get(index - 1) + median.get(index)) / 2): median.get(index);
            
        System.out.println("Median: " + middle);
    }
}
