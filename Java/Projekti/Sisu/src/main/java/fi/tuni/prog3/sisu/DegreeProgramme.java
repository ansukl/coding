/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fi.tuni.prog3.sisu;

import java.io.File;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Ns. pääluokka, jossa haetaan tutkinto-, moduuli- ja kurssitiedot json-tiedostoista,
 * tallennetaan ne tietorakenteisiin ja luodaan tutkintorakenne.
 */
public class DegreeProgramme {
    public String name;
    public String code;
    public int credits;
    
    // Tutkinnon ensimmäisen tason alamoduulit.
    private final ArrayList<Module> subModules;
    
    // Tietorakenteet json-tiedostojen sisällölle.
    private final ArrayList<CourseUnit> allCourses;
    private ArrayList<Map<String, ?>> rawData;
    private final ArrayList<Module> allModules;
    
    /**
    * Rakentaja tutkinnolle, jossa määritellään luokkamuuttujat ja kutsutaan 
    * tutkinnon täyttävää funktiota.
    */
    public DegreeProgramme() {
        this.subModules = new ArrayList();
        this.allCourses = new ArrayList();
        this.rawData = new ArrayList();
        this.allModules = new ArrayList();
        
        populateProgramme();
    }
    
    /**
    * Hakee tutkintorakennetta varten json-tiedostoista tiedot tutkinnosta,
    *  moduuleista ja kurseista.
    */
    private void populateProgramme() {
        // Luetaan kaikki moduulit json-tiedostoista listaan
        FileOperations fileOps = new FileOperations();
        this.rawData = readModuleJsonFilesToList(fileOps);
        
        // Alustaa tutkinnon
        Map<String, ?> degreeFile = getDegreeFile();
        this.name = ((Map<String, String>)degreeFile.get("name")).get("fi");
        this.code = (String)degreeFile.get("code");
        double temp = ((Map<String, Double>)degreeFile.get("targetCredits")).get("min");
        this.credits = (int)temp;
        
        // Alustaa kaikki kurssioliot
        ArrayList<Map<String, ?>> courseFiles = readCourseJsonFilesToList(fileOps);
        initCourses(courseFiles);
        
        // Alustaa kaikki moduulioliot
        initModules();
        
        // Alustaa tutkinnon alamoduulit
        ArrayList<String> groupIds = getModuleGroupIds(degreeFile);
        initSubModules(groupIds);
    }
    
    /**
    * Etsii hierarkian ylimmän tason eli tutkinnon.
    * @return tutkinnon tiedot sisältävän map-tietorakenteen.
    */
    private Map<String, ?> getDegreeFile() {
        for (Map<String, ?> file : this.rawData) {
            if (((String)file.get("type")).equals("DegreeProgramme")) {
                return file;
            }
        }
        return null;
    }

    /**
    * Etsii suoraan tutkinnon alla olevien moduulien id:t.
    * @param m - tutkinnon tiedot sisältävä map-tietorakenne.
    * @return listan id:tä suoraan tutkinnon alla olevista moduuleista.
    */
    private ArrayList<String> getModuleGroupIds(Map<String, ?> m) {
        Map<String, ?> firstLevel = (Map<String, ?>)m.get("rule");
        Map<String, ?> secondLevel = (Map<String, ?>)firstLevel.get("rule");
        ArrayList<Object> thirdLevel = (ArrayList<Object>)secondLevel.get("rules");
        Map<String, ?> fourthLevel = (Map<String, ?>)thirdLevel.get(0);
        ArrayList<Map<String, ?>> subModuleIds = (ArrayList<Map<String, ?>>)fourthLevel.get("rules");
        
        ArrayList<String> ids = new ArrayList();
        for (Map<String, ?> subModule : subModuleIds) {
            String s = (String)subModule.get("moduleGroupId");
            ids.add(s);
        }
        
        return ids;
    }
    
    /**
    * Lukee modules-kansiossa olevat json-tiedostot auki tietorakenteeseen.
    * @param f - FileOperations-tyyppinen olio, jota käytetään json-tiedostojen
    * lukemiseen.
    * @return listan map-tietorakenteita, joihin on tallennettu json-tiedostojen
    * tiedot.
    */
    private ArrayList<Map<String, ?>> readModuleJsonFilesToList(FileOperations f) {
        Set<String> fileNames = Stream.of(new File("../json/modules").listFiles())
            .filter(file -> !file.isDirectory())
            .map(File::getName)
            .collect(Collectors.toSet());
        
        ArrayList<Map<String, ?>> files = new ArrayList();
        for (String file : fileNames) {
            try {
                Map<String, ?> m = f.readFromFile("../json/modules/" + file);
                files.add(m);
            }
            catch (Exception ex) {System.out.println(ex);}
        }
        
        return files;
    }
    
    /**
    * Alustaa suoraan tutkinnon alla olevat alamoduulit.
    * @param ids - id-lista alamoduuleista, jonka perusteella alustus tehdään.
    */
    private void initSubModules(ArrayList<String> ids) {
        for (String Id : ids) {
            Module correctSubModule = findSubModule(Id);
            this.subModules.add(correctSubModule);
        }
    }
    
    /**
    * Etsii id:tä vastaavan alamoduulin.
    * @param moduleGroupId - id, jonka perusteella moduulia etsitään.
    */
    private Module findSubModule(String moduleGroupId) {
        for (Module module : this.allModules) {
            if (module.getGroupId().equals(moduleGroupId)) {
                return module;
            }
        } return null;
    }
    
    /**
    * Lukee courseunits-kansiossa olevat json-tiedostot auki tietorakenteeseen.
    * @param f - FileOperations-tyyppinen olio, jota käytetään json-tiedostojen
    * lukemiseen.
    * @return listan map-tietorakenteita, joihin on tallennettu json-tiedostojen
    * tiedot.
    */
    private ArrayList<Map<String, ?>> readCourseJsonFilesToList(FileOperations f) {
        Set<String> fileNames = Stream.of(new File("../json/courseunits").listFiles())
            .filter(file -> !file.isDirectory())
            .map(File::getName)
            .collect(Collectors.toSet());
        
        ArrayList<Map<String, ?>> files = new ArrayList();
        for (String file : fileNames) {
            try {
                Map<String, ?> m = f.readFromFile("../json/courseunits/" + file);
                files.add(m);
            }
            catch (Exception ex) {System.out.println(ex);}
        }
        
        return files;
    }
    
    /**
    * Luo uuden Module-tyyppisen olion jokaisesta tietorakenteessa olevasta 
    * moduulista, lisää moduuliolion kaikkien moduulien listaan ja kutsuu
    * moduulien hierarkkisen rakenteen luovaa funktiota.
    */
    private void initModules () {
        for (Map<String, ?> file : this.rawData) {           
            Module module = new Module(
                   ((Map<String, String>)file.get("name")).get("fi"),
                   (String)file.get("id"),
                   (String)file.get("groupId"),
                   (String)file.get("code"),
                   (Map<String, Object>)file
            );
            
            this.allModules.add(module);
        }
        
        for (Module mod : this.allModules) {
            mod.populateModule(this.allCourses, this.allModules);
        }
    }
    
    /**
    * Luo uuden CourseUnit-tyyppisen olion jokaisesta tietorakenteessa olevasta
    * kurssista ja lisää kurssiolion kaikkien kurssien listaan.
    * @param files - lista map-tietorakenteita, joihin on tallennettu json-
    * tiedostoista kurssien tiedot.
    */
    private void initCourses (ArrayList<Map<String, ?>> files) {
        for (Map<String, ?> file : files) {
            double tempMin = ((Map<String, Double>)file.get("credits")).get("min");
            double tempMax = ((Map<String, Double>)file.get("credits")).get("max");
             
            CourseUnit course = new CourseUnit(
                   ((Map<String, String>)file.get("name")).get("fi"),
                   (String)file.get("id"),
                   (String)file.get("groupId"),
                   (int)tempMin,
                   (String)file.get("code"),
                   (int)tempMax
            );
            
            this.allCourses.add(course);
        }
    }
    
    /**
    * Palauttaa luokkamuuttujan name.
    * @return tutkinnon nimen.
    */
    public String getName() {
        return this.name;
    }
    
    /**
    * Palauttaa luokkamuuttujan subModules.
    * @return tutkinnon ensimmäisen tason alamoduulit listassa.
    */
    public ArrayList<Module> getSubModules() {
        return this.subModules;
    }
    
    /**
    * Palauttaa luokkamuuttujan allCourses.
    * @return kaikki kurssit listassa.
    */
    public ArrayList<CourseUnit> getAllCourses() {
        return this.allCourses;
    }
    
    /**
    * Palauttaa luokkamuuttujan allModules.
    * @return kaikki moduulit listassa.
    */
    public ArrayList<Module> getAllModules() {
        return this.allModules;
    }
}


