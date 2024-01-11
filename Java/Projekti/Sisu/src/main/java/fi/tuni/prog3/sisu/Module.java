/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fi.tuni.prog3.sisu;

import java.util.ArrayList;
import java.util.Map;

/**
 * Luokka moduulitietojen esittämiseen. Periytyy abstraktista luokasta
 * DegreeModule.
 */
public class Module extends DegreeModule{
    private final String code;
    private final Map<String, Object> self;
    private final ArrayList<CourseUnit> subCourses;
    private final ArrayList<Module> subModules;
    
    /**
    * Rakentaa moduulitietorakenteen, johon tallennetaan moduulin nimi, id, groupId,
    * koodi, tieto itsestään ja tiedot alamoduuleista ja -kursseista.
    * @param name - moduulin nimi (peritty superilta).
    * @param id - moduulin id (peritty superilta).
    * @param groupId - moduulin groupId (peritty superilta).
    * @param code - moduulin koodi.
    * @param self - moduulin omat tiedot map-tietorakenteessa.
    */
    public Module(String name, String id, String groupId, String code, Map<String, Object> self) {
        super(name, id, groupId, 0);
        this.code = code;
        this.self = self;
        this.subCourses = new ArrayList();
        this.subModules = new ArrayList();
    }
    
    /**
    * Täydentää moduuliin sen alamoduulit ja alakurssit.
    * @param courses - lista kaikista kursseista.
    * @param modules - lista kaikista moduuleista.
    */
    public void populateModule(ArrayList<CourseUnit> courses, ArrayList<Module> modules) {
        ArrayList<ArrayList<String>> subModuleIds = Utils.getAllSubUnitIds(this.self);
                
        ArrayList<String> courseIds = subModuleIds.get(0);
        ArrayList<String> moduleIds = subModuleIds.get(1);
        
        for (String id : courseIds) {
            for (CourseUnit course : courses) {
                if (id.equals(course.getGroupId())) {
                    this.subCourses.add(course);
                }
            }
        }
        
        for (String id : moduleIds) {
            for (Module module : modules) {
                if (id.equals(module.getGroupId())) {
                    this.subModules.add(module);
                }
            }
        }
    }
    
    /**
    * Palauttaa luokkamuuttujan code.
    * @return moduulin koodin. 
    */
    public String getCode() {
        return code;
    }
    
    /**
    * Palauttaa luokkamuuttujan subModules.
    * @return moduulin alamoduulit listassa. 
    */
    public ArrayList<Module> getSubModules() {
        return this.subModules;
    }
    
    /**
    * Palauttaa luokkamuuttujan subCourses.
    * @return moduulin alakurssit listassa. 
    */
    public ArrayList<CourseUnit> getSubCourses() {
        return this.subCourses;
    }
}
