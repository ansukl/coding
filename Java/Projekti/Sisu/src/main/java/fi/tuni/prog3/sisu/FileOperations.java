/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fi.tuni.prog3.sisu;

import com.google.gson.Gson;
import java.io.Reader;
import java.nio.file.Files;
import java.util.Map;
import java.nio.file.Paths;
import java.util.TreeMap;

/**
 * Luokka json-tiedostojen lukemiselle gson-jäsentelijällä.
 */
public class FileOperations implements iReadAndWriteToFile {
    
    /**
    * Lukee ja jäsentelee json-tiedoston ja tallentaa tiedot map-tietorakenteeseen.
    * @param fileName - luettava json-tiedosto.
    * @return jäsentelijällä luotu map-tietorakenne.
    * @throws Exception - jos tiedoston luku ja jäsentely ei onnistu.
    */
    @Override
    public Map<String, ?> readFromFile(String fileName) throws Exception {
        Map<String, ?> map =  new TreeMap();
        try {

            // Luodaan jsonin jäsentelijä
            Gson gson = new Gson();
            Reader reader = Files.newBufferedReader(Paths.get(fileName));

            // Muutetaan json map-tietorakenteeksi
            map = gson.fromJson(reader, Map.class);

            reader.close();
        }
        
        catch (Exception ex) {System.out.println(ex);}

        return map;
    }
    
    /**
    * Kirjoittaa json-tiedostoon. Ei toteutettu.
    */
    @Override
    public boolean writeToFile(String fileName) throws Exception {
        return true;
    }
}
