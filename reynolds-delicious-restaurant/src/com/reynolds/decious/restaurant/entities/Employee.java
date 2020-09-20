package com.reynolds.decious.restaurant.entities;

public class Employee extends User {
    private String code;

    public Employee() {
        super();
    }

    public Employee(Long id) {
        super(id);
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }
}
