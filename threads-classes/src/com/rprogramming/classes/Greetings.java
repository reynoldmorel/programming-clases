package com.rprogramming.classes;

public class Greetings implements Runnable {
    private String greet;
    private Integer delay;

    public Greetings() {
        this.greet = "Hi";
        this.delay = 500;
    }

    public Greetings(String greet, Integer delay) {
        this.greet = greet;
        this.delay = delay;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(this.greet + i);

            try {
                Thread.sleep(this.delay);
            } catch (InterruptedException e) {
                System.out.println("Thread was interrupted.");
            }
        }
    }
}
