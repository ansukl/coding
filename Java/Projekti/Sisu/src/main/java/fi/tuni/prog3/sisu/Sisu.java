package fi.tuni.prog3.sisu;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.beans.value.ObservableValue;
import javafx.scene.control.TreeItem;
import javafx.scene.control.TreeView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;



/**
 * JavaFX-luokka Sisun käyttöliittymälle.
 */
public class Sisu extends Application {

    private String name;
    private String id;
    private DegreeProgramme degree;
    private HBox mainBox;
    private VBox leftBox;
    private VBox rightBox;
    private Label selectionLabel;
    
    /**
    * Ohjelman alkupisteenä toimiva start-metodi.
    * @param stage - olio, joka määrittelee ohjelman pääikkunan.
    * @throws FileNotFoundException - jos annettua tiedostoa ei löydy.
    */
    @Override
    public void start(Stage stage) throws FileNotFoundException {
        
        
        //Creating a new BorderPane.
        BorderPane root = new BorderPane();
        root.setStyle("-fx-background-color: #4f018e;"); // Debug
        root.setPadding(new Insets(10, 10, 10, 10));
        
        //Adding HBox to the center of the BorderPane.
        root.setCenter(getCenterHbox());
        
        //Adding button to the BorderPane and aligning it to the right.
        var quitButton = getQuitButton();
        BorderPane.setMargin(quitButton, new Insets(10, 10, 0, 10));
        root.setBottom(quitButton);
        BorderPane.setAlignment(quitButton, Pos.TOP_RIGHT);
        
        //Luodaan uusi GridPane aloitusnäkymää varten.
        GridPane setup = new GridPane();
        setup.setPadding(new Insets(10, 10, 10, 10));
        setup.setStyle("-fx-background-color: #ffffff;");
        setup.setVgap(5);
        setup.setHgap(5);
        
        // Ensimmäinen skene ohjelman aloitusikkunalle.
        Scene setupScene = new Scene(setup, 300, 300);
        
        Label studentNameLabel = new Label("Nimi:");
        setup.add(studentNameLabel, 0, 1);
        
        Label studentNumLabel = new Label("Opiskelijanumero:");
        setup.add(studentNumLabel, 0, 2);
        
        TextField studentName = new TextField();
        setup.add(studentName, 1, 1);
        
        TextField studentNum = new TextField();
        setup.add(studentNum, 1, 2);
        
        Button submitButton = new Button("Tallenna");
        setup.add(submitButton, 0, 4);
        
        FileInputStream inputstream = new FileInputStream("src/main/resources/tuni.jpg");
        Image image1 = new Image(inputstream);
        ImageView im = new ImageView(image1);
        setup.add(im, 0, 6, 2, 1);
        
        stage.setScene(setupScene);
        stage.setTitle("Aloitus");

        // Toinen skene päänäkymälle.
        Scene mainScene = new Scene(root, 800, 500);

        // Ykkösnäkymässä nappula vaihtaa kakkosnäkymään.
        submitButton.setOnAction((event) -> {
            name = studentName.getText();
            id = studentNum.getText();
            
            initDegree();
            createDegreeTree();
            
            stage.setScene(mainScene);
            stage.setTitle("GifuGUI - " + name + " (" + id + ")");
        });

        stage.show();
    }
    /**
    * Ohjelman main-metodi.
    * @param args - ohjelman komentoriviltä saamat parametrit.
    */
    public static void main(String[] args) {
        launch();
    }
    
    /**
    * Luo päänäkymään Hboxin.
    */
    private HBox getCenterHbox() {
        //Creating an HBox.
        HBox centerHBox = new HBox(10);
        
        //Adding two VBox to the HBox.
        centerHBox.getChildren().addAll(getLeftVBox(), getRightVBox());
        this.mainBox = centerHBox;
        
        // Make left and right box resize with parent centerHBox
        this.leftBox.prefWidthProperty().bind(centerHBox.widthProperty().divide(2));
        this.rightBox.prefWidthProperty().bind(centerHBox.widthProperty().divide(2));
        
        return centerHBox;
    }
    
    /**
    * Luo päänäkymään vasemmalle Vboxin.
    */
    private VBox getLeftVBox() {
        //Creating a VBox for the left side.
        VBox leftVBox = new VBox();
        leftVBox.setPrefWidth(380);
        leftVBox.setStyle("-fx-background-color: #ffffff;");
        this.leftBox = leftVBox;
        
        return leftVBox;
    }
    
    /**
    * Luo päänäkymään oikealle Vboxin.
    */
    private VBox getRightVBox() {
        //Creating a VBox for the right side.
        VBox rightVBox = new VBox();
        rightVBox.setPrefWidth(380);
        rightVBox.setStyle("-fx-background-color: #ffffff;");
        this.rightBox = rightVBox;
        
        return rightVBox;
    }
    
    /**
    * Luo päänäkymään lopetusnappulan.
    */
    private Button getQuitButton() {
        //Creating a button.
        Button button = new Button("Eiku");
        
        //Adding an event to the button to terminate the application.
        button.setOnAction((ActionEvent event) -> {
            Platform.exit();
        });
        
        return button;
    }
    
    /**
    * Alustaa näytettävän tutkinnon.
    */
    private void initDegree() {
        this.degree = new DegreeProgramme();
        
    }
    
    /**
    * Luo visuaalisen representaation tutkintorakenteesta.
    */
    private void createDegreeTree() {
        this.selectionLabel = new Label("");
        this.selectionLabel.setWrapText(true);
        this.selectionLabel.setTextFill(Color.color(0.31, 0, 0.56));
        
        this.rightBox.getChildren().add(this.selectionLabel);
        
        TreeItem<String> rootItem = new TreeItem<> (this.degree.getName());
        rootItem.setExpanded(true);
        
        for (Module module : this.degree.getSubModules()) {
            degreeRecursion(rootItem, module);
        }
        
        TreeView<String> tree = new TreeView<>(rootItem);
        tree.setStyle("-fx-border-color: white white white white;");
        tree.autosize();
        
        tree.getSelectionModel()
        .selectedItemProperty()
        .addListener((ObservableValue<? extends TreeItem<String>> changed, TreeItem<String> oldVal, TreeItem<String> newVal) -> {
            
            // Näytetään tietoa klikatusta valinnasta ja siihen johtava polku
            if (newVal != null) {
                
                String path = newVal.getValue();
                TreeItem<String> tmp = newVal.getParent();
                while (tmp != null) {
                    path = tmp.getValue() + "\n -> " + path;
                    tmp = tmp.getParent();
                }

                String n = newVal.getValue();
                String code = "";
                int mincreds = -1;
                int maxcreds = -1;
                
                for (CourseUnit c : this.degree.getAllCourses()) {
                    if (c.getName().equals(n)) {
                        code = c.getCode();
                        mincreds = c.getMinCredits();
                        maxcreds = c.getMaxCredits();
                    }
                }
                
                for (Module m : this.degree.getAllModules()) {
                    if (m.getName().equals(n)) {
                        code = m.getCode();
                    }
                }
                
                if (code != null) {
                    if (mincreds == -1) {
                        this.selectionLabel.setText(code + " " + newVal.getValue() + "\n\n" + path);
                    } else {
                        if (mincreds == maxcreds) {
                            this.selectionLabel.setText(code + " " + newVal.getValue() + " "+ mincreds + " op\n\n" + path);
                        } else {
                            this.selectionLabel.setText(code + " " + newVal.getValue() + " "+ mincreds + "-" + maxcreds + " op\n\n" + path);
                        }
                    }
                }
                else {
                    this.selectionLabel.setText(newVal.getValue() + "\n\n" + path);
                }
            }
        });
        
        this.leftBox.getChildren().add(tree);
    }
    
    /**
    * Kulkee tutkinnon tietorakenteen läpi rekursiivisesti.
    * @param header - aloituspiste eli tutkinnon nimi.
    * @param module - moduuli, josta haetaan tietoa tutkinnon rakenteesta.
    */
    private void degreeRecursion(TreeItem<String> header, Module module) {
        TreeItem subHeader = new TreeItem(module.getName());
        
        for (CourseUnit course : module.getSubCourses()) {
            subHeader.getChildren().add(new TreeItem(course.getName()));
        }
        
        for (Module subModule : module.getSubModules()) {
            degreeRecursion(subHeader, subModule);
        }
        
        header.getChildren().add(subHeader);
    }
}
