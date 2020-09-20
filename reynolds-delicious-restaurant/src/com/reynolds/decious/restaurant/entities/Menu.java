package com.reynolds.decious.restaurant.entities;

import java.util.List;
import java.util.Objects;

public class Menu {
    private Long id;
    private String name;
    private List<MenuItem> finalProducts;

    public Menu() {
    }

    public Menu(Long id) {
        this.id = id;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<MenuItem> getFinalProducts() {
        return finalProducts;
    }

    public void setFinalProducts(List<MenuItem> finalProducts) {
        this.finalProducts = finalProducts;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Menu menu = (Menu) o;
        return Objects.equals(id, menu.id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
