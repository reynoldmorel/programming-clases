package com.programming.classes;

public class Square extends Shape {

    @Override
    public Double computeArea() {
        System.out.println("Square area");
        var area = Math.pow(super.getSide(), 2);
        return area;
    }

    @Override
    public Double getSide() {
        System.out.println("Square Side");
        return 2 * super.getSide().doubleValue();
    }

    public Double getSide(Double side) {
        System.out.println("Square Side");
        return 2 * super.getSide();
    }
}
