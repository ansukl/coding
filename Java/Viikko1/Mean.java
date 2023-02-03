/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class Mean {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        double mean = 0;
        
        for (String s : args) {
            double d = Double.parseDouble(s);
            mean += d;
        }
        int x = args.length;
        mean = mean/x;
        System.out.println("Mean: " + mean);
    }
}
