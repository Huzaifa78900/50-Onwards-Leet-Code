
// class Bank {
//     int getRateOfInterest() {
//         return 0;
//     }
// }

// class SBI extends Bank {
//     int getRateOfInterest() {
//         return 8;
//     }
// }

// class ICICI extends Bank {
//     int getRateOfInterest() {
//         return 7;
//     }
// }

// class AXIS extends Bank {
//     int getRateOfInterest() {
//         return 9;
//     }
// }

// public class Main {
//     public static void main(String[] args) {

//         Bank b;

//         b = new SBI();
//         System.out.println("SBI Rate of Interest: " +
//                            b.getRateOfInterest() + "%");

//         b = new ICICI();
//         System.out.println("ICICI Rate of Interest: " +
//                            b.getRateOfInterest() + "%");

//         b = new AXIS();
//         System.out.println("AXIS Rate of Interest: " +
//                            b.getRateOfInterest() + "%");
//     }
// }

import java.util.Scanner;

class Number {
    int n;

    void getdata() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number");
        n = sc.nextInt();
    }

    void calculate() {
        System.out.println("Factorial is:");
    }
}

class Factorial extends Number {

    void getdata() {
        super.getdata();
    }

    void calculate() {
        int fact = 1;

        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }

        System.out.println("Factorial of " + n + " is " + fact);
    }
}

public class Main {
    public static void main(String[] args) {

        Number obj = new Factorial();

        obj.getdata();
        obj.calculate();
    }
}

