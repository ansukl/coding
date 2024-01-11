/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

import java.util.Comparator;
/**
 *
 * @author annak
 */
public class Attainment implements Comparable<Attainment>{

    private String course_code;
    private String student_number;
    private int course_grade;
    
    public static final Comparator<Attainment> CODE_STUDENT_CMP = new Comparator<>() {
        @Override
        public int compare(Attainment a, Attainment b) {
        int cmp = a.getCourseCode().compareTo(b.getCourseCode());
        if(cmp == 0) {
            cmp = a.getStudentNumber().compareTo(b.getStudentNumber());
        }
        return cmp;
      }
    };
            
    public static final Comparator<Attainment> CODE_GRADE_CMP = new Comparator<>() {
        @Override
        public int compare(Attainment a, Attainment b) {
        int cmp = a.getCourseCode().compareTo(b.getCourseCode());
        if(cmp == 0) {
            cmp = -(Integer.compare(a.getGrade(), b.getGrade()));
        }
        return cmp;
      }
    };

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
    
    @Override
    public String toString() {
        String output = String.format("%s %s %s", course_code, student_number, course_grade);
        return output;
    }
    
    @Override
    public int compareTo(Attainment other) {
        int cmp = student_number.compareTo(other.student_number);
        if (cmp == 0) {
            cmp = course_code.compareTo(other.course_code);
        }
        return cmp;
    }
    
}
