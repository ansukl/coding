/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class Student {
    private String student_name;
    private String student_number;
    
    public Student (String name, String studentNumber) {
        student_name = name;
        student_number = studentNumber;
    }
    
    public String getName() {
        return student_name;
    }
    
    public String getStudentNumber() {
        return student_number;
    }
    
}
