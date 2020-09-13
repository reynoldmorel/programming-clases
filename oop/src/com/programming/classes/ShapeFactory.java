package com.programming.classes;

public final class ShapeFactory {
    public static Shape create(String type){
        if(type.equals("triangle")) {
            return new Triangle();
        } else {
            return new Square();
        }
    }
}
