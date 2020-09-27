package com.reynolds.decious.restaurant.core.ioc;

public enum IoCRepositoryEnum {
    ORDER_REPOSITORY("orderRepository"),
    CASHIER_REPOSITORY("cashierRepository");

    private final String value;

    IoCRepositoryEnum(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}
