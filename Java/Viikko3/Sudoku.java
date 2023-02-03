/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */

import java.util.ArrayList;
import java.util.TreeMap;
import java.util.Set;

public class Sudoku {

    private ArrayList<ArrayList<Character>> table = new ArrayList<>();
    
    public Sudoku() {
        for (int x = 0; x < 9; x++) {
            table.add(new ArrayList());
            for (int y = 0; y < 9; y++) {
                table.get(x).add(' ');
            }
        }
    }
    
    private static final Set<Character> list = Set.of(' ', '1', '2', '3', '4', '5', '6', '7', '8', '9');
    
    public void set(int i, int j, char c) {
        if (i < 0 || i > 8 || j < 0 || j > 8) {
            System.out.println("Trying to access illegal cell (" + i + ", " + j + ")!");
        }
        else if (!list.contains(c)) {
            System.out.println("Trying to set illegal character " + c + " to (" + i + ", " + j + ")!");
        }
        else {
            table.get(i).set(j, c);
        }
    }
    
    public boolean check() {
        TreeMap<Integer, Character> problems = new TreeMap<>();
        
        for (int x = 0; x < 9; x++) {
            ArrayList<Character> temp = new ArrayList<>();
            for (int y = 0; y < 9; y++) {
                var current_char = table.get(x).get(y);
                if (current_char == ' ') {
                    continue;
                }
                if (!temp.contains(current_char)) {
                    temp.add(current_char);
                }
                else {
                   if (problems.containsKey(x)) {
                       int value = Character.getNumericValue(current_char);
                       int problem_value = Character.getNumericValue(problems.get(x));
                       if (value < problem_value) {
                           problems.put(x, current_char);
                       }
                   }
                   else {
                        problems.put(x, current_char);   
                   }
                }
            }
            if (!problems.isEmpty()) {
                var key = problems.keySet().toArray()[0];
                var value = problems.get(key);
                
                System.out.println("Row " + key + " has multiple " + value + "'s!");
                return false;
            }
        }
       
        for (int x = 0; x < 9; x++) {
            ArrayList<Character> temp = new ArrayList<>();
            for (int y = 0; y < 9; y++) {
                var current_char = table.get(y).get(x);
                if (current_char == ' ') {
                    continue;
                }
                if (!temp.contains(current_char)) {
                    temp.add(current_char);
                }
                else {
                    if (problems.containsKey(y)) {
                        int value = Character.getNumericValue(current_char);
                        int problem_value = Character.getNumericValue(problems.get(x));
                        if (value < problem_value) {
                            problems.put(x, current_char);
                        }
                    } 
                    else {
                        problems.put(x, current_char);   
                   }
                }
            }
            if (!problems.isEmpty()) {
                var key = problems.keySet().toArray()[0];
                var value = problems.get(key);
                
                System.out.println("Column " + key + " has multiple " + value + "'s!");
                return false;
            }
        }
        
        
        
        
        for (int i = 0; i < 9; i+=3) {
            int y_box = i;
            for (int j = 0; j < 9; j+=3) {
                int x_box = j;
                
                ArrayList<Character> temp = new ArrayList<>();
                for (int x = x_box; x < x_box +3; x++) {
                    for (int y = y_box; y < y_box +3; y++) {
                        var current_char = table.get(x).get(y);
                        if (current_char == ' ') {
                            continue;
                        }
                        if (!temp.contains(current_char)) {
                            temp.add(current_char);
                        }
                        else {
                           if (problems.containsKey(x_box)) {
                               int value = Character.getNumericValue(current_char);
                               int problem_value = Character.getNumericValue(problems.get(x_box));
                               if (value < problem_value) {
                                   problems.put(x_box, current_char);
                               }
                            } else {
                                problems.put(x_box, current_char);
                           }
                        }
                    }
                }

                if (!problems.isEmpty()) {
                    var key = problems.keySet().toArray()[0];
                    var value = problems.get(key);

                    System.out.println("Block at (" + x_box + ", " + y_box + ") has multiple " + value + "'s!");
                    return false;
                }
            }
        }
        
        
        return true;
    }
    
    public void print() {
        String border = "#".repeat(37);
        String border2 = "#---+---+---#---+---+---#---+---+---#" ;
        
        System.out.println(border);
        for (int x = 0; x < 9; x++) {
            System.out.print("#");
            for (int y = 0; y < 9; y++) {
                if (y == 2 || y == 5 || y == 8) {
                    System.out.print(" " + table.get(x).get(y) + " #");
                }
                else {
                    System.out.print(" " + table.get(x).get(y) + " |");
                }
            }
            System.out.println();
            
            if (x == 2 || x == 5 || x == 8) {
                System.out.println(border);
            }
            
            else {
                System.out.println(border2);
            }
        }
    }
}