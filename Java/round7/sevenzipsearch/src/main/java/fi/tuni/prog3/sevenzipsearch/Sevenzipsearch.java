/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package fi.tuni.prog3.sevenzipsearch;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import org.apache.commons.compress.archivers.sevenz.SevenZFile;
import org.apache.commons.compress.archivers.sevenz.SevenZArchiveEntry;
/**
 *
 * @author annak
 */
public class Sevenzipsearch {

    public static void main(String[] args) {
        String filename = args[0];
        String keyword = args[1].toLowerCase();
        ArrayList<String> filenames = new ArrayList<> ();
        
        try {
            SevenZFile sevenZFile = new SevenZFile(new File(filename));
            SevenZArchiveEntry entry = sevenZFile.getNextEntry();
            while(entry!=null){
                if (entry.getName().contains(".txt")) {
                    filenames.add(entry.getName());
                }

                FileOutputStream out = new FileOutputStream(entry.getName());
                byte[] content = new byte[(int) entry.getSize()];
                sevenZFile.read(content, 0, content.length);
                out.write(content);
                out.close();
                entry = sevenZFile.getNextEntry();
            }
            sevenZFile.close();
        }
        
        catch (FileNotFoundException e) {
                System.out.println (e);
        }
        catch (IOException e) {
            System.out.println (e);
        }
        
        
        for (String name : filenames) {
            System.out.println(name);
            try {
                FileInputStream fstream = new FileInputStream(name);
                BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

                String origLine;
                String lowerLine;
                
                int linenumber = 1;
                while ((origLine = br.readLine()) != null) {
                  lowerLine = origLine.toLowerCase();
                  if (lowerLine.contains(keyword)) {
                      int index = lowerLine.indexOf(keyword);
                      StringBuilder modified = new StringBuilder(origLine);
                      while (index >= 0) {
                      
                        modified.replace(index, index + keyword.length(), keyword.toUpperCase());
                        index = lowerLine.indexOf(keyword, index + keyword.length());
                      }
                      
                      System.out.println(linenumber + ": " + modified.toString());

                  }
                  linenumber ++;
                }

                fstream.close();
                System.out.println();
            }

            catch (FileNotFoundException e) {
                System.out.println (e);
            }
            catch (IOException e) {
                System.out.println (e);
            }
        }
    }
        
}
