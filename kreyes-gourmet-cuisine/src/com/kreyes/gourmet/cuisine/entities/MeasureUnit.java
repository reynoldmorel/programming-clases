package com.kreyes.gourmet.cuisine.entities;

import java.util.Objects;

public class MeasureUnit {
    private Long id;
    private String name;

    public MeasureUnit() {
    }

    public MeasureUnit(Long id) {
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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        MeasureUnit measureUnit = (MeasureUnit) o;
        return Objects.equals(id, measureUnit.id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
