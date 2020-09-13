package com.programming.classes;

import java.time.Instant;

public final class User {
    private String name;
    private String lastName;
    private Integer age;
    private String identification;
    private Instant birthdate;

    public User() {
    }

    public User(String name, String lastName, Integer age, String identification, Instant birthdate) {
        this.name = name;
        this.lastName = lastName;
        this.age = age;
        this.identification = identification;
        this.birthdate = birthdate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public String getIdentification() {
        return identification;
    }

    public void setIdentification(String identification) {
        this.identification = identification;
    }

    public Instant getBirthdate() {
        return birthdate;
    }

    public void setBirthdate(Instant birthdate) {
        this.birthdate = birthdate;
    }
}
