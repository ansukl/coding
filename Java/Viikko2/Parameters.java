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

public class Parameters {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        
        ArrayList<String> countries = new ArrayList<>();
       
        int c_length = 0;
        for (String s : args) {
            countries.add(s);
            int l = s.length(); 
            if (l > c_length) {
                c_length = l;
            }
        }
        
         Collections.sort(countries);
        
        int index = countries.size();
        String i = Integer.toString(index);
        int n_length = i.length();
        
        int total = c_length + n_length + 7;
        String border = "#".repeat(total);
        
        System.out.println(border);
        int first = 1;
        for (var country : countries) {
            System.out.format("# %"+n_length+"d | %-"+c_length+"s #%n", first, country);
            if (!country.equals(countries.get(countries.size() -1))) {
                System.out.println("#" + "-".repeat(n_length+2) + "+" + "-".repeat(c_length+2) + "#");
            } 
            first++;
        }
        System.out.println(border);
    }
}

       
