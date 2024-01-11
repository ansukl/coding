/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package fi.tuni.prog3.sisu;

/**
 * Luokka kurssitietojen esittämiseen. Periytyy abstraktista luokasta
 * DegreeModule.
 */
public class CourseUnit extends DegreeModule {
    
    private final int maxCredits;
    private final String code;
    
    /**
    * Rakentaa kurssitietorakenteen, johon tallennetaan kurssin nimi, id, groupId,
    * minimi- ja maksimiopintopisteet ja koodi.
    * @param name - kurssin nimi (peritty superilta).
    * @param id - kurssin id (peritty superilta).
    * @param groupId - kurssin groupId (peritty superilta).
    * @param minCredits - kurssin vähimmäismäärä opintopisteitä (peritty superilta).
    * @param code - kurssin koodi.
    * @param maxCredits - kurssin enimmäismäärä opintopisteitä (peritty superilta).
    */
    public CourseUnit (String name, String id, String groupId, int minCredits, String code, int maxCredits) {
        
        super(name, id, groupId, minCredits);
        this.maxCredits = maxCredits;
        this.code = code;
    }
    
    /**
    * Palauttaa luokkamuuttujan maxCredits.
    * @return kurssin maksimiopintopistemäärän. 
    */
    public int getMaxCredits() {
        return this.maxCredits;
    }
    
    /**
    * Palauttaa luokkamuuttujan code.
    * @return kurssin koodin. 
    */
    public String getCode() {
        return this.code;
    }
}
