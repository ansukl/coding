/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fi.tuni.prog3.sisu;

import java.util.ArrayList;
import java.util.Map;

/**
 * Luokka työkaluille, joita tarvitaan tutkinnon hierarkisen rakenteen
 * määrittelyssä.
 */
public final class Utils {
    
    /**
    * Palauttaa tietorakenteen sisällä olevien rule/rules-elementtien id:t.
    * @param m - moduulia edustava map-tietorakenne, josta tietoa haetaan.
    * @return listan alamoduulien ja alakurssien id:tä.
    */
    public static ArrayList<ArrayList<String>> getAllSubUnitIds(Map<String, ?> m) {
        ArrayList<ArrayList<String>> ids = new ArrayList();
        ArrayList<String> courseIds = new ArrayList();
        ArrayList<String> moduleIds = new ArrayList();
        
        if (m.get("type").equals("GroupingModule") || m.get("type").equals("StudyModule")) {
            Map<String, Object> firstLevel = (Map<String, Object>)m.get("rule");
            
            ruleRecursion(moduleIds, courseIds, firstLevel);
        }
        
        ids.add(courseIds);
        ids.add(moduleIds);
        
        return ids;
    }
    
    /**
    * Kulkee rule/rules-rakenteen rekursiivisesti läpi ja etsii sieltä alakurssien 
    * ja alamoduulien id:t.
    * @param moduleIdList - lista moduulien id:stä.
    * @param courseIdList - lista kurssien id:stä.
    * @param o - map-tietorakenne, josta tietoa haetaan.
    */
    private static void ruleRecursion(ArrayList<String> moduleIdList, ArrayList<String> courseIdList, Map<String, ?> o) {
        if (o.containsKey("rules")) {
            for (Map<String, Object> child : (ArrayList<Map<String, Object>>)o.get("rules")) {
                ruleRecursion(moduleIdList, courseIdList, child);
            }
        } 
        
        else if (o.containsKey("rule")) {
            Map<String, ?> child = (Map<String, ?>)o.get("rule");
            ruleRecursion(moduleIdList, courseIdList, child);
        }
        
        else {
            String type = (String)o.get("type");
            if (type.equals("CourseUnitRule")) {
                courseIdList.add((String)o.get("courseUnitGroupId"));
            }
            
            else if (type.equals("ModuleRule")) {
                moduleIdList.add((String)o.get("moduleGroupId"));
            }
        }
    }
}
