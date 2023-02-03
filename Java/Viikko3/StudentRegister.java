/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
import java.util.ArrayList;

public class StudentRegister {
    private ArrayList<Student> students = new ArrayList<>();
    private ArrayList<Course> courses = new ArrayList<>();
    private ArrayList<Attainment> attainments = new ArrayList<>();

    public StudentRegister(){
        
    }
    
    public ArrayList<Student> getStudents() {
        students.sort((s1, s2) -> s1.getName().compareTo(s2.getName()));
        return students;
    }
    
    public ArrayList<Course> getCourses() {
        courses.sort((c1, c2) -> c1.getName().compareTo(c2.getName()));
        return courses;
    }
    
    public void addStudent(Student student) {
        students.add(student);
    }
    
    public void addCourse(Course course) {
        courses.add(course);
    }
    
    public void addAttainment(Attainment att) {
        attainments.add(att);
    }
    
    public void printStudentAttainments(String studentNumber, String order) {
        boolean found = false;
        for (Student s : students) {
            if (s.getStudentNumber() == studentNumber) {
                System.out.println(s.getName() + " (" + studentNumber + "):");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Unknown student number: " + studentNumber);
            return;
        }
        
        ArrayList<Course> temp = new ArrayList<>();
        for (Attainment att : attainments) {
            if (att.getStudentNumber().equals(studentNumber)) {
                for (Course course : courses) {
                    if (course.getCode().equals(att.getCourseCode())) {
                        temp.add(course);
                        break;
                    }
                }
            }
        }
        
        if (order.equals("by name")) {
            temp.sort((c1, c2) -> c1.getName().compareTo(c2.getName()));
            for (Course course : temp) {
                for (Attainment att : attainments) {
                    if (att.getStudentNumber().equals(studentNumber) && att.getCourseCode().equals(course.getCode())) {
                        System.out.println("  " + course.getCode() + " " + course.getName() + ": " + att.getGrade());
                        break;
                    }
                } 
            }
        }
        
        else if (order.equals("by code")) {
            temp.sort((c1, c2) -> c1.getCode().compareTo(c2.getCode()));
            for (Course course : temp) {
                for (Attainment att : attainments) {
                    if (att.getStudentNumber().equals(studentNumber) && att.getCourseCode().equals(course.getCode())) {
                        System.out.println("  " + course.getCode() + " " + course.getName() + ": " + att.getGrade());
                        break;
                    }
                } 
            }
        }
        
        else {
            for (Attainment att : attainments) {
                if (att.getStudentNumber().equals(studentNumber)) {
                    for (Course course : courses) {
                        if (course.getCode().equals(att.getCourseCode())) {
                            System.out.println("  " + att.getCourseCode() + " " + course.getName() + ": " + att.getGrade());
                            break;
                        }
                    }
                }
            }   
        }
    }
    
    public void printStudentAttainments(String studentNumber) {
        boolean found = false;
        for (Student s : students) {
            if (s.getStudentNumber() == studentNumber) {
                System.out.println(s.getName() + " (" + studentNumber + "):");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Unknown student number: " + studentNumber);
            return;
        }
        
        for (Attainment att : attainments) {
            if (att.getStudentNumber().equals(studentNumber)) {
                for (Course course : courses) {
                    if (course.getCode().equals(att.getCourseCode())) {
                        System.out.println("  " + att.getCourseCode() + " " + course.getName() + ": " + att.getGrade());
                        break;
                    }
                }
            }
        }
    }
}
