package com.programming.classes;

public final class EntityManager {
    private static final EntityManager INSTANCE = new EntityManager();

    private EntityManager() {}

    public static EntityManager getInstance() {
        return INSTANCE;
    }
}
