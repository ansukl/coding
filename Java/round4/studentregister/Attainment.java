/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
public class Attainment {
    private String course_code;
    private String student_number;
    private int course_grade;

    public Attainment(String courseCode, String studentNumber, int grade) {
        course_code = courseCode;
        student_number = studentNumber;
        course_grade = grade;
    }
    
    public String getCourseCode() {
        return course_code;
    }
    
    public String getStudentNumber() {
        return student_number;
    }
    public int getGrade() {
        return course_grade;
    }
}
