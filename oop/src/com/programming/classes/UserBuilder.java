package com.programming.classes;

import java.time.Instant;

public class UserBuilder {

    private User user;

    private UserBuilder(){
        this.user = new User();
    }

    public static UserBuilder build() {
        return new UserBuilder();
    }

    public UserBuilder withName(String name) {
        this.user.setName(name);
        return this;
    }

    public UserBuilder withLastName(String lastName) {
        this.user.setLastName(lastName);
        return this;
    }

    public User get() {
        return this.user;
    }
}
