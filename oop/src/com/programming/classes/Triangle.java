package com.programming.classes;

public class Triangle extends Shape {

    @Override
    public Double computeArea() {
        System.out.println("Triangle area");
        var area = super.getSide() * super.getSide() / 2;
        return area;
    }

}
