package com.rprogramming.classes;

public class Main {

    public static void main(String[] args) {
        var greetings1 = new Greetings("hello", 500);
        var greetings2 = new Greetings("How are you doing?", 1000);

        var thread1 = new Thread(greetings1);
        var thread2 = new Thread(greetings2);

        thread1.start();
        thread2.start();

        var runnable = new Runnable() {
            @Override
            public void run() {
                System.out.println("We are here!!");
            }
        };

        var thread3 = new Thread(() -> System.out.println("Hello"));
        var thread4 = new Thread(() -> System.out.println("How are you doing?"));

        thread3.start();
        thread4.start();
        System.out.println("Threads Started!!");

        System.out.println("Threads Started!!");
    }


}
