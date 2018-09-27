

public class Triangle extends GeometricObject {

    
    private double side1;
    private double side2;
    private double side3;
    private String color;
    private boolean filled;


    // Default constructor for Triangle class
    public Triangle() {

        // Information to be printed about new instance of triangle class
        System.out.println("New default instance of triangle class spawned");
        System.out.println("----------------------------------------");
        System.out.println(this.toString());
    }

    public Triangle(double s1, double s2, double s3) {

        // Constructor overload setting side values from parameters
        this.side1 = s1;
        this.side2 = s2;
        this.side3 = s3;

        // Information to be printed about new instance of triangle class
        System.out.println("New instance of triangle class spawned");
        System.out.println("----------------------------------------");

        // With side information
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 1: " + this.side3);
    }



    public Triangle(double s1, double s2, double s3, String col, boolean fill) {

        // Constructor overload setting side values from parameters
        // and color + filled status
        this.side1 = s1;
        this.side2 = s2;
        this.side3 = s3;
            
        this.color = col;
        this.filled = fill;

        // Information to be printed about new instance of triangle class
        System.out.println("New instance of triangle class spawned");
        System.out.println("----------------------------------------");

        // With side information + color and filled information
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 1: " + this.side3);
        System.out.println("Side 1: " + this.side3);
        System.out.println("Side 1: " + this.side3);
    }










}

