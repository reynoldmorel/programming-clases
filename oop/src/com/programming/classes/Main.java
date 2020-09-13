package com.programming.classes;

import java.util.Calendar;

public class Main {
    public static Square square = new Square();

    public static void main(String[] args) {
        setSide(10D);

        System.out.println(computeSquareArea2());
        System.out.println(computeSquareArea());
        System.out.println(computeSquareArea3());

        var triangle = ShapeFactory.create("triangle");
        var square = ShapeFactory.create("square");

        var user = new User();
        user.setName("");
        user.setLastName("");

        var user1 = UserBuilder.build()
                .withName("Juan")
                .withLastName("Perez")
                .get();


    }

    public static Double computeSquareArea() {
        var tmpSq = new Square();
        tmpSq.setSide(5D);

        var area = Math.pow(tmpSq.getSide(), 2);
        tmpSq.setArea(area);

        return tmpSq.getArea();
    }

    public static Double computeSquareArea2() {
        var tmpSq = new Square();
        tmpSq.setSide(8D);

        var area = Math.pow(tmpSq.getSide(), 2);
        tmpSq.setArea(area);

        return tmpSq.getArea();
    }

    public static void setSide(Double side) {
        square.setSide(side);
    }

    public static Double computeSquareArea3() {
        var area = Math.pow(square.getSide(), 2);
        square.setArea(area);

        return square.getArea();
    }
}
