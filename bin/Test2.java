class Main {
    public static void main() {
        int a;
        int b;
        a = 1;
        b = 7;

        while (! (a == b)) {
            a = a + 1;
            b = b - 1;
        }

        if (a == b && (4 % 2) == 0) {
            System.out.println(a);
            System.out.println(b);
        } else {
            System.out.println(0);
        }

        boolean [] t;
        t = new boolean[5];
        int i;
        i = 0;
        while (i < 5) {
            if (i % 2 == 0) {
                t[i] = true;
            } else {
                t[i] = false;
            }
            i = i + 1;
        }

        i = 0;
        while (i < 5) {
            if (t[i]) {
                System.out.println(1);
            } else if (!t[i]) {
                System.out.println(0);
            }
            i = i + 1;
        }
    }
}