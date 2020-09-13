package com.programming.classes;

public abstract class Shape {
    private Double area = 0D;
    private Double side = 0D;
    private Double angle = 0D;

    public abstract Double computeArea();

    public Double getArea() {
        return area;
    }

    public void setArea(Double area) {
        this.area = area;
    }

    public Double getSide() {
        System.out.println("Shape Side");
        return side;
    }

    public void setSide(Double side) {
        this.side = side;
    }

    public Double getAngle() {
        return angle;
    }

    public void setAngle(Double angle) {
        this.angle = angle;
    }
}
