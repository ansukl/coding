/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.stream.*;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;

public class MovieAnalytics {
    
    private ArrayList<Movie> movies = new ArrayList<>();
    
    public MovieAnalytics () {
        
    }
    
    public static Consumer<Movie> showInfo() {
        Consumer<Movie> consumer = (movie) -> System.out.println(movie.getTitle() + " (By " + movie.getDirector() + ", " + movie.getReleaseYear() + ")");
        
        //String formatted = 
        //consumer.accept(object.getTitle() + "(By " + object.getDirector() + ", " + object.getReleaseYear() + ")");
           
                
        return consumer;
    }
    
    
    public void populateWithData(String fileName) {
        try {
            FileInputStream fstream = new FileInputStream(fileName);
            BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

            String strLine;

            while ((strLine = br.readLine()) != null)   {
              String[] splitted = strLine.split(";");
              
              int year = Integer.parseInt(splitted[1]);
              int duration = Integer.parseInt(splitted[2]);
              double score = Double.parseDouble(splitted[4]);
              String title = splitted[0];
              String genre = splitted[3];
              String director = splitted[5];
              
              movies.add(new Movie(title, year, duration, genre, score, director));
            }
            
            fstream.close();   
        }
        
        catch (FileNotFoundException e) {
            System.out.println (e);
        }
        catch (IOException e) {
            System.out.println (e);
        }
    }
    
    public Stream<Movie> moviesAfter(int year) {
        return movies.stream().filter(m -> m.getReleaseYear() >= year).sorted((m1, m2) -> {
            if (Integer.compare(m1.getReleaseYear(), m2.getReleaseYear()) == 0) {
                return m1.getTitle().compareTo(m2.getTitle());
            }
            
            else {
                return Integer.compare(m1.getReleaseYear(), m2.getReleaseYear());
            }
        }); 
    }
    
    public Stream<Movie> moviesBefore(int year) {
        return movies.stream().filter(m -> m.getReleaseYear() <= year).sorted((m1, m2) -> {
            if (Integer.compare(m1.getReleaseYear(), m2.getReleaseYear()) == 0) {
                return m1.getTitle().compareTo(m2.getTitle());
            }
            
            else {
                return Integer.compare(m1.getReleaseYear(), m2.getReleaseYear());
            }
        }); 
    }
    
    public Stream<Movie> moviesBetween(int yearA, int yearB) {
        return movies.stream().filter(m -> (m.getReleaseYear() >= yearA && m.getReleaseYear() <= yearB)).sorted((m1, m2) -> {
            if (Integer.compare(m1.getReleaseYear(), m2.getReleaseYear()) == 0) {
                return m1.getTitle().compareTo(m2.getTitle());
            }
            
            else {
                return Integer.compare(m1.getReleaseYear(), m2.getReleaseYear());
            }
        }); 
    }
    
    public Stream<Movie> moviesByDirector(String director) {
        return movies.stream().filter(m -> m.getDirector().equals(director)).sorted((m1, m2) -> {
            if (Integer.compare(m1.getReleaseYear(), m2.getReleaseYear()) == 0) {
                return m1.getTitle().compareTo(m2.getTitle());
            }
            
            else {
                return Integer.compare(m1.getReleaseYear(), m2.getReleaseYear());
            }
        }); 
    }
}
